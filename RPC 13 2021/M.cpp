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

vector<vector<int>> g;
vector<bool> used;

void dfs(int node)
{
	used[node] = true;
	forall(it,g[node]) if(!used[*it]) dfs(*it);
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
	int t;
	cin >> t;
	forn(T,t)
	{
		int n,m;
		cin >> n >> m;
		g = vector<vector<int>>(n);
		forn(_,m)
		{
			int a,b;
			cin >> a >> b;
			assert(a >= 0 && a < n);
			assert(b >= 0 && b < n);
			g[a].pb(b);
			g[b].pb(a);
		}
		int ans = 0;
		used = vector<bool>(n,false);
		forn(i,n) if(!used[i])
		{
			ans++;
			dfs(i);
		}
		if(ans == 1) cout << "Pure Compound!\n";
		else cout << "Mixture: " << ans << '\n';
	}
	return 0;
}
