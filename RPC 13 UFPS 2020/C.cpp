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
typedef pair<int, ii> iii;
#define INF 100000001
#define MAXN 101
int G[MAXN][MAXN];
int n,m,x;
int pers[MAXN], tal[MAXN];
vector<pair<int, ii>> edg;
struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};
struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {} //clear and init
	void addEdge(int u, int v, ll cap)
	{
		if (u != v)
		{
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}
	bool BFS(int S, int T)
	{
		queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k: g[u])
			{
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
				{
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	ll DFS(int u, int T, ll flow = -1)
	{
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < sz(g[u]); ++i)
		{
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1)
			{
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = DFS(e.v, T, amt))
				{
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int S,int T) //O(V^2*E), unit nets: O(sqrt(V)*E)
	{
		ll total = 0;
		while(BFS(S, T))
		{
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = DFS(S, T)) total += flow;
		}
		return total;
	}
};

void floyd(){
	forn(k,n){
		forn(i,n){
			if(G[i][k]!=INF){
				forn(j,n){
					if(G[k][j]!=INF) G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
				}
			}
		}
	}
}

int solve(int M){
	int src=2*n, snk=2*n+1;
	Dinic dinic(2*n+2);
	forn(i,n){
		dinic.addEdge(src,i,pers[i]);
		dinic.addEdge(i+n,snk,tal[i]);
	}
	forall(it, edg){
		if(it->fst > M) break;
		else dinic.addEdge(it->snd.fst, it->snd.snd+n, INF);
	}
	return dinic.maxFlow(src,snk);
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
	cin >> n >> m >> x;
	forn(i,n) cin >> pers[i];
	forn(i,n) cin >> tal[i];
	forn(i,n)forn(j,n) G[i][j] = INF;
	forn(i,n) G[i][i] = 0;
	forn(i,m){
		int a,b,w; cin >> a >> b >> w; a--; b--;
		G[a][b]=G[b][a]=min(G[b][a], w);
	}
	
	floyd();
	forn(i,n)forn(j,n) if(G[i][j]!=INF) edg.emplace_back(mp(G[i][j], mp(i,j)));
	sort(edg.begin(), edg.end());
	int L = 0, R=x, ans = solve(x);
	while(L<R){
		int M = (L+R)/2;
		int aux = solve(M);
		if(aux < ans) L = M+1;
		else R = M;
	}
	cout << L << " " << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

