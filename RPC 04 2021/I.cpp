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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXZOOM 30

//Dado un arreglo y una operacion asociativa con neutro

typedef vector<ii> tipo;
int k;
tipo neutro;
tipo operacion(tipo a, tipo b)
{
	if(a == neutro) return b;
	if(b == neutro) return a;
	vector<ii> ret = neutro;
	int posa = 0, posb = 0;
	forn(i,k) if(a[posa] > b[posb]) ret[i] = a[posa++]; else ret[i] = b[posb++];
	return ret;
}
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
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
}; //Use: definir operacion tipo neutro y MAXN,
//cin >> n; rmq.init(n); forn(i, n) cin >> rmq[i]; rmq.updall();

ii g[MAXN][MAXZOOM][6];
int dist[MAXN][MAXZOOM], n, gpos[MAXN][MAXZOOM];
vector<ii> v;

void bfs()
{
	int node = -1;
	forn(i,n) if(v[i].fst == 0) node = i;
	assert(node != -1);
	queue<ii> q;
	q.push(mp(node, 1));
	memset(dist, -1, sizeof(dist));
	dist[node][1] = 0;
	while(!q.empty())
	{
		ii cur = q.front();
		int d = dist[cur.fst][cur.snd];
		//cout << "cur " << cur.fst << ' ' << cur.snd << ' ' << dist[cur.fst][cur.snd] << '\n';
		q.pop();
		forn(i,gpos[cur.fst][cur.snd]) 
		{
			int a = g[cur.fst][cur.snd][i].fst, b = g[cur.fst][cur.snd][i].snd;
			if(dist[a][b] == -1) dist[a][b] = d + 1, q.push(mp(a,b));
		}
	}
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
	cin >> n >> k;
	neutro = vector<ii>(k, mp(-1,-1));
	v = vector<ii>(n+1);
	forn(i,n)
	{
		cin >> v[i].fst;
		v[i].snd = i;
	}
	v[n++] = mp(0, -1);
	sort(v.begin(), v.end());
	//cout << "nodes: ";
	//forn(i,n) cout << v[i].fst << ' ' << v[i].snd << '\n';
	vector<int> maxGoodZoom(n,0);
	RMQ st;
	st.init(n);
	forn(i,n) st[i][0] = mp(v[i].snd, i);
	st.updall();
	forn(i,n)
	{
		forn(j,MAXZOOM-1) g[i][j][gpos[i][j]++] = mp(i,j+1);
		forr(j,1,MAXZOOM) g[i][j][gpos[i][j]++] = mp(i,j-1);
		int l,r, width = 1;
		vector<ii> s;
		forr(j,1,MAXZOOM)
		{
			l = v[i].fst - width;
			r = v[i].fst + width;
			width *= 2;
			int lpos = lb(v.begin(), v.end(), mp(l, -1))-v.begin();
			int rpos = ub(v.begin(), v.end(), mp(r, n))-v.begin();
			//cout << i << ' ' << j << ' ' << lpos << ' ' << rpos << '\n';
			s = st.get(lpos, rpos);
			forall(it, s) if(it->snd != -1)
			{
				if(it->snd == i) maxGoodZoom[i] = j;
				//cout << "from " << i << ' ' << j << " to " << it->snd << ' ' << j  << '\n';
				g[i][j][gpos[i][j]++] = mp(it->snd, j);
			}
		}
	}
	bfs();
	vector<int> ans(n-1);
	forn(i,n) if(v[i].fst != 0)
	{
		int aux = -1;
		forn(j,maxGoodZoom[i]+1) if(aux == -1 || (dist[i][j] != -1 && dist[i][j] < aux)) aux = dist[i][j];
		ans[v[i].snd] = aux;
	}
	forn(i,n-1) cout << ans[i] << '\n';
	return 0;
}
