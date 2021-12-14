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

int n,m,dr[4] = {0,0,-1,1}, dc[4] = {1,-1,0,0};
vector<vector<int>> dp;
vector<string> vv;
vector<ii> auxv;

int solve(int r, int c)
{
	if(dp[r][c] != -1) return dp[r][c];
	dp[r][c] = 0;
	auxv.pb(mp(r,c));
	int ret = 1;
	forn(i,4)
	{
		int rr = r+dr[i], cc = c+dc[i];
		if(rr < 0 || cc < 0 || rr >= n || cc >= m || vv[rr][cc] == '#') continue;
		assert(dp[rr][cc] == -1 || dp[rr][cc] == 0);
		ret += solve(rr,cc);
	}
	return ret;
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
		cout << "Case " << T+1 << ":\n";
		cin >> m >> n;
		vv = vector<string>(n);
		forn(i,n) cin >> vv[i];
		dp = vector<vector<int>>(n, vector<int>(m,-1));
		int q;
		cin >> q;
		forn(_,q)
		{
			int r,c;
			cin >> r >> c;
			r--;c--;
			auxv.clear();
			int ans = solve(r,c);
			forall(it,auxv) dp[it->fst][it->snd] = ans;
			cout << ans << '\n';
		}
	}
	return 0;
}
