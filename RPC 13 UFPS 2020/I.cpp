#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define CANT 3

const ll P = 9973, MOD[CANT] = {999727999, 1070777777, 1000000033}, PI[CANT] = {718444858, 219888989, 457735902};
vector<ll> vp[CANT], vpi[CANT];

struct Node{
	ll h[CANT];
	Node(char c, int e) {
		forn(i,CANT) h[i] = c*vp[i][e]%MOD[i];
	}
	Node() {
		forn(i,CANT) h[i] = 0;
	}
};

typedef Node tipo;

Node operacion(Node a, Node b)
{
	Node ret;
	forn(i,CANT) ret.h[i] = (a.h[i]+b.h[i])%MOD[i];
	return ret;
}

//Dado un arreglo y una operacion asociativa con neutro
const tipo neutro;
struct RMQ {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
}; //Use: definir operacion tipo neutro y MAXN,
//cin >> n; rmq.init(n); forn(i, n) cin >> rmq[i]; rmq.updall();

vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
Node query(int x, int y, RMQ &st){
	Node r=neutro;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r=operacion(r,st.get(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	r=operacion(r,st.get(pos[x],pos[y]+1));
	return r;
}
// for updating: rmq.upd(pos[x],v);
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line 28)

const int LOGN=18;
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int N, f[MAXN][LOGN], L[MAXN];
//call before build:
void dfs(int v, int fa=-1, int lvl=0){//generate required data
	f[v][0]=fa, L[v]=lvl;
	forall(it, g[v])if(*it!=fa) dfs(*it, v, lvl+1); }
void build(){//f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) f[i][k+1]=f[f[i][k]][k];}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if(!d) return a;
	dforn(i, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;}
ii lca(int a, int b){//O(lgn)
	bool swapped = false;
	if(L[a]<L[b]) swap(a, b), swapped=true;
	a=climb(a, L[a]-L[b]);
	if(a==b) return mp(a,-1);
	dforn(i, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return mp(f[a][0], swapped?a:b); 
}



int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	string s;
	cin >> n >> q >> s;
	N = n;
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	hld_init();
	dfs(0);
	build();
	int depth = 0;
	forn(i,n) depth = max(depth, dep[i]);
	forn(i,CANT) vp[i] = vector<ll>(depth+5);
	forn(i,CANT) vpi[i] = vector<ll>(depth+5);
	forn(k,CANT)
	{
		vp[k][0] = vpi[k][0] = 1;
		forr(i,1,depth+5)
		{
			vp[k][i] = vp[k][i-1]*P % MOD[k];
			vpi[k][i] = vpi[k][i-1]*PI[k] % MOD[k];
		}
	}
	assert(curpos == n);
	RMQ st,stinv;
	//hash para abajo
	st.init(n);
	//hash para arriba
	stinv.init(n);
	forn(i,n)
	{
		st[pos[i]] = Node(s[i], dep[i]);
		stinv[pos[i]] = Node(s[i], depth-dep[i]);
	}
	st.updall();
	stinv.updall();
	forn(_,q)
	{
		/*forn(i,n)
		{
			cout << "node=" << i+1 << " pos=" << pos[i] << " char=" << s[i] << " h=" << st[pos[i]].hval << ' ' << dep[i] << " invh=" << stinv[pos[i]].hval << ' ' << depth-dep[i] << '\n';
		}*/
		int t;
		cin >> t;
		if(t == 1)
		{
			int a,b;
			cin >> a >> b;
			if(a == b)
			{
				cout << "Yes\n";
				continue;
			}
			a--;b--;
			ii lcaresp = lca(a,b);
			int lcanode = lcaresp.fst;
			if(lcanode == a || lcanode == b)
			{
				//cout << "case ancestor: \n";
				if(lcanode == b) swap(a,b);
				Node x = query(a,b,st), xinv = query(a,b,stinv);
				assert(dep[a] < dep[b]);
				bool ok = true;
				forn(i,CANT) if(x.h[i]*vpi[i][dep[a]]%MOD[i] != xinv.h[i]*vpi[i][depth-dep[b]]%MOD[i])
				{
					ok = false;
					break;
				}
				if(ok) cout << "Yes\n";
				else cout << "No\n";
			}
			else
			{
				//cout << "case lca needed: \n";
				assert(dep[lcanode] < dep[a]);
				assert(dep[lcanode] < dep[b]);
				Node aup = query(a, lcanode, stinv), bup = query(b, lcaresp.snd, stinv);
				Node downa = query(a, lcanode, st), downb = query(b, lcaresp.snd, st);
				int lena = dep[a] - dep[lcanode]+1, lenb = dep[b] - dep[lcanode];
				//cout << "lca=" << lcanode+1 << " second=" << lcaresp.snd+1 << '\n';
				//cout << "aup=" << aup.hval << ' ' << aup.hval*vpi[depth-dep[a]]%MOD << " bup=" << bup.hval*vpi[depth-dep[b]]%MOD;
			//	cout << " downa=" << downa.hval << ' ' << downa.hval*vpi[dep[lcanode]]%MOD << " downb=" << downb.hval*vpi[dep[lcaresp.snd]]%MOD << '\n';
				//cout << "lena=" << lena << " lenb=" << lenb << '\n';
				ll hvalab, hvalba;
				bool ok = true;
				forn(i,CANT)
				{
					hvalab = aup.h[i]*vpi[i][depth-dep[a]]%MOD[i];
					hvalba = bup.h[i]*vpi[i][depth-dep[b]]%MOD[i];
					hvalab = (hvalab + downb.h[i]*vpi[i][dep[lcaresp.snd]]%MOD[i]*vp[i][lena])%MOD[i];
					hvalba = (hvalba + downa.h[i]*vpi[i][dep[lcanode]]%MOD[i]*vp[i][lenb])%MOD[i];
					if(hvalab != hvalba)
					{
						ok = false;
						break;
					}
				}
				if(ok) cout << "Yes\n";
				else cout << "No\n";
			}
		}
		else
		{
			int node;
			char c;
			cin >> node >> c;
			node--;
			s[node] = c;
			st.set(pos[node], Node(c, dep[node]));
			stinv.set(pos[node], Node(c, depth-dep[node]));
		}
		
	}
	return 0;
}
