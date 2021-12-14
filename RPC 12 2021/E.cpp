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

#define MAXN 20
#define INF 1000

vector<int> g[MAXN];
unordered_set<int> s;
int n, dp[1<<MAXN];


int solve(int bm)
{
	if(s.empty()) return 0;
	if(dp[bm] != -1) return dp[bm];
	int ret = -INF;
	vector<int> vnodes;
	vnodes.reserve(sz(s));
	forall(it,s) vnodes.pb(*it);
	forall(ite,vnodes)
	{
		int node = *ite;
		s.erase(node);
		int raid = 0;
		forall(it,g[node]) if(bm & (1<<*it)) raid++; else raid--;
		ret = max(ret, raid-solve(bm|(1<<node)));
		s.insert(node);
	}
	return dp[bm] = ret;
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
	forn(i,n) s.insert(i);
	memset(dp, -1, sizeof(dp));
	int ans = solve(0);
	if(ans == 0) cout << "tie\n";
	else if(ans > 0) cout << "player 1\n";
	else cout << "player 2\n";
	return 0;
}
