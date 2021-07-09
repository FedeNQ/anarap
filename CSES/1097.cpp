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
#define MAXN 500
#else
#define MAXN 5001
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;

ll dp[MAXN][MAXN], v[MAXN], acum[MAXN];

ll solve(int l, int r)
{
	assert(l <= r);
	if(l == r) return v[l];
	if(dp[l][r] != -1) return dp[l][r];
	dp[l][r] = acum[r+1] - acum[l] - min(solve(l+1,r), solve(l,r-1));
	//cout << l << ' ' << r << ' ' << dp[l][r] << '\n';
	return dp[l][r];
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
	int n;
	cin >> n;
	forn(i,n) cin >> v[i];
	memset(dp, -1, sizeof(dp));
	forn(i,n) acum[i+1] = acum[i] + v[i];
	cout << solve(0,n-1) << '\n';
	return 0;
}
