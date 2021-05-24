#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

map<int,vector<int>> g;
set<int> used;

int cntNodes, cntEdges, biggest;
ll ans = 0;

void dfs(int node)
{
	cntNodes++;
	biggest = max(biggest, node);
	used.insert(node);
	map<int,vector<int>>::iterator ite = g.find(node);
	cntEdges += sz(ite->snd);
	forall(it, ite->snd) if(!used.count(*it)) dfs(*it);
	ans += (sz(ite->snd)-1LL)*node;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	forn(i,n)
	{
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	forall(it,g)if(!used.count(it->fst))
	{
		cntNodes = cntEdges = biggest = 0;
		dfs(it->fst);
		cntEdges /= 2;
		assert(cntEdges == cntNodes || cntEdges == cntNodes-1);
		if(cntEdges == cntNodes-1) ans += biggest;
	}
	cout << ans << '\n';
	return 0;
}

