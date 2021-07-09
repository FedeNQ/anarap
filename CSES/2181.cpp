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
#define MAXM 100
#else
#define MAXM 1001
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007

int n,m,dp[1<<10][2][10][MAXM];

int solve(int bm, int up, int r, int c)
{
	if(r == n) r=up=0, c++;
	if(c == m) return bm == 0;
	if(dp[bm][up][r][c] != -1) return dp[bm][up][r][c];
	int ret = 0;
	if(bm & (1<<r))
	{
		// if left cell is empty, we must put horizontal tile
		ret = solve(bm & (((1<<n)-1) ^ (1<<r)), 0, r+1, c);
	}
	else
	{
		// if left cell is not empty, we can leave current empty
		ret = solve(bm | (1<<r), 1, r+1, c);
		if(up)
		{
			// if also the cell above is empty, we can put a vertical tile
			ret += solve(bm & (((1<<n)-1) ^ (1<<(r-1))), 0, r+1, c);
		}
	}
	return dp[bm][up][r][c] = ret%MOD;
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
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0, 0) << '\n';
	return 0;
}
