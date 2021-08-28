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

#define MAXN 16

int n, dp[MAXN][1<<MAXN];
vector<int> g[MAXN];

int solve(int node, int bm)
{
	bm |= 1<<node;
	if(bm == (1<<n)-1) return 1;
	if(dp[node][bm] != -1) return dp[node][bm];
	int ret = 1;
	forall(it, g[node]) if((bm & (1<<*it)) == 0) ret = max(ret, 1+solve(*it, bm));
	return dp[node][bm] = ret;
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
	int m;
	cin >> n >> m;
	forn(_,m)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	forn(i,n) ans = max(ans, solve(i, 0));
	cout << ans << '\n';
	return 0;
}
