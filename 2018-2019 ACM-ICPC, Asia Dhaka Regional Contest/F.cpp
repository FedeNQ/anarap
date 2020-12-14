#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


const int MAXN=10004, LOGN=20;
vector<int> G[MAXN];
bool used[MAXN];
bitset<MAXN> val[MAXN];
int N, f[MAXN][LOGN], L[MAXN];
void dfs(int v,int fa= -1, int lvl=0){
	f[v][0]=fa, L[v]=lvl;
	forall(it, G[v]) if(*it!=fa) dfs(*it,v, lvl+1);
}
void build(){
	forn(k,LOGN-1) forn(i,N) f[i][k+1] = f[f[i][k]][k];
}
#define lg(x) (31-__builtin_clz(x))
int climb(int a, int d){
	if(!d) return a;
	dforn(i, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
	return a;
}
int lca(int a, int b){
	if(L[a]<L[b]) swap(a,b);
	a=climb(a,L[a]-L[b]);
	if(a==b) return a;
	dforn(i, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0];
	
}
int dist(int a, int b){	return L[a]+L[b]-2*L[lca(a,b)];}

void rundfs(int node, bitset<MAXN> bs){
	if(used[node]) return;
	used[node] = 1;
	bs.set(node);
	val[node] = bs;
	//~ cout << node << " " << bs << '\n';
	forall(it, G[node]){
		if(!used[*it]){
			rundfs(*it, bs);
		}
	}
	return; 
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(T,t){
		int n;
		cin >> n;
		N=n;
		forn(i,n-1){
			int a, b; 
			cin >> a >> b;
			a--; b--;
			G[a].pb(b);
			G[b].pb(a);
		}
		forn(i,n) val[i].reset();
		forn(i,n) used[i] = 0;
		int q; cin >> q;
		bitset<MAXN> vacio;
		rundfs(0, vacio);
		dfs(0);
		build();
		cout << "Case " << T+1 << ": " << '\n';
		forn(Q,q){
			int x;
			cin >> x;
			bitset<MAXN> aux;
			aux.set();
			forn(X,x){
				int a,b;
				cin >> a >> b;
				a--; b--;
				int lcaux = lca(a,b);
				//~ cout << "A " << val[a] << '\n';
				//~ cout << "B " << val[b] << '\n';
				//~ cout << "AB " << (val[a]|val[b]) << '\n';
				//~ cout << "L " << val[lcaux] << '\n';
				bitset<MAXN> now = (val[a]|val[b])^val[lcaux];
				now.set(lcaux);
				aux &= now;
			}
			cout << aux.count() << '\n';
		}
		forn(i,n) G[i].clear();
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

