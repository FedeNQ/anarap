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
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

typedef int tf;
typedef ll tc;

const int MAXN=205;
const tf INFFLUJO = 1e9;
const tc INFCOSTO = 1e14;

struct costflow{
	struct edge {
		int u, v;
		tf cap, flow;
		tc cost;
		tf rem() { return cap - flow; }
	};
	int nodes; //numero de nodos
	vector<int> G[MAXN]; // limpiar!
	vector<edge> e;  // limpiar!
	void addEdge(int u, int v, tf cap, tc cost) {
		//cout << u << ' ' << v << ' ' << cap << ' ' << cost << '\n';
		G[u].pb(sz(e)); e.pb((edge){u,v,cap,0,cost});
		G[v].pb(sz(e)); e.pb((edge){v,u,0,0,-cost});
	}
	tc dist[MAXN], mnCost;
	int pre[MAXN];
	tf cap[MAXN], mxFlow;
	//tf wantedFlow; //For fixed flow instead of max
	bool in_queue[MAXN];
	void flow(int s, int t) {// O(n^2 * m^2)
		memset(in_queue, 0, sizeof(in_queue));
		mxFlow=mnCost=0;
		while(1) {
			fill(dist, dist+nodes, INFCOSTO); dist[s] = 0;
			memset(pre, -1, sizeof(pre)); pre[s]=0;
			memset(cap, 0, sizeof(cap)); cap[s] = INFFLUJO;		
			queue<int> q; q.push(s); in_queue[s]=1;
			while(sz(q)) {//Fast bellman-ford
				int u=q.front(); q.pop(); in_queue[u]=0;
				for(auto it:G[u]) {
					edge &E = e[it];
					if(E.rem() && dist[E.v] > dist[u] + E.cost) {// ojo EPS
						dist[E.v]=dist[u]+E.cost;
						pre[E.v] = it;
						cap[E.v] = min(cap[u], E.rem());
						if(!in_queue[E.v]) q.push(E.v), in_queue[E.v]=1;
					}
				}
			}
			if (pre[t] == -1) break;
			tf flow = cap[t];
			//flow = min(flow, wantedFlow-mxFlow) //For fixed flow
			mxFlow += flow;
			mnCost += flow*dist[t];
			for (int v = t; v != s; v = e[pre[v]].u) {
				e[pre[v]].flow += flow;
				e[pre[v]^1].flow -= flow;
			}
			//if(mxFlow == wantedFlow) break; //For fixed flow
		}
	}
};

#define SRC 200
#define SNK 201

ll solve(vector<int> &v, vector<int> &cnt, int mult)
{
	costflow cf;
	int n = sz(v), maxidx = 0;
	forn(i,n) if(v[i] > v[maxidx]) maxidx = i;
	forn(i,n)
	{
		if(i != maxidx) cf.addEdge(SRC, i, 1, 0);
		if(i == maxidx) cf.addEdge(100+i, SNK, cnt[i], 0);
		else cf.addEdge(100+i, SNK, cnt[i]-1, 0);
		forn(j,n) if(v[i] < v[j]) cf.addEdge(i, 100+j, 1, mult*(v[i]^v[j]));
	}
	cf.nodes = MAXN;
	cf.flow(SRC,SNK);
	//cout << "flow " << cf.mxFlow << '\n';
	return mult*cf.mnCost;
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
	int n;
	cin >> n;
	vector<int> v(n),cnt(n);
	forn(i,n) cin >> v[i] >> cnt[i];
	cout << solve(v, cnt, 1) << ' ' << solve(v, cnt, -1) << '\n';
	return 0;
}
