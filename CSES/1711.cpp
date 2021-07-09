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

#define MAX_V 505
#define INF 1000100100
//special nodes
#define SRC 501
#define SNK 502
map<int, int> G[MAX_V];//limpiar esto -- unordered_map mejora
//To add an edge use
#define add(a, b, w) G[a][b]=w
int f, p[MAX_V];
void augment(int v, int minE)
{
	if(v==SRC) f=minE;
	else if(p[v]!=-1)
	{
		augment(p[v], min(minE, G[p[v]][v]));
		G[p[v]][v]-=f, G[v][p[v]]+=f;
	}
}
int maxflow()//O(min(VE^2,Mf*E))
{
	int Mf=0;
	do
	{
		f=0;
		char used[MAX_V]; queue<int> q; q.push(SRC);
		memset(used, 0, sizeof(used)), memset(p, -1, sizeof(p));
		while(sz(q))
		{
			int u=q.front(); q.pop();
			if(u==SNK) break;
			forall(it, G[u])
				if(it->snd>0 && !used[it->fst])
				used[it->fst]=true, q.push(it->fst), p[it->fst]=u;
		}
		augment(SNK, INF);
		Mf+=f;
	}while(f);
	return Mf;
}

 
int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	set<ii> edges;
	vector<int> g[MAX_V];
	forn(i,m)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		add(a,b,1);
		edges.insert(mp(a,b));
		g[a].pb(b);
	}
	add(SRC, 0, m);
	add(n-1, SNK, m);
	int ans = maxflow();
	cout << ans << '\n';
	forn(_,ans)
	{
		int node = 0;
		vector<int> vans;
		vans.pb(0);
		while(node != n-1)
		{
			bool changed = false;
			forall(it,g[node]) if(edges.count(mp(node, *it)) && G[node][*it] == 0)
			{
				edges.erase(mp(node, *it));
				vans.pb(*it);
				node = *it;
				changed = true;
				break;
			}
			assert(changed);
		}
		cout << sz(vans) << '\n';
		forn(i,sz(vans))
		{
			if(i) cout << ' ';
			cout << vans[i]+1;
		}
		cout << '\n';
	}
	return 0;
}
