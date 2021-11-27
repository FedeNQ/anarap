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

ll n, dp[40][40][2];

ll solve(int pos, int cnt1, bool smaller)
{
	if(pos == -1) return 1LL<<cnt1;
	if(dp[pos][cnt1][smaller] != -1) return dp[pos][cnt1][smaller];
	ll ret = solve(pos-1, cnt1, smaller || (n & (1LL<<pos)));
	if(smaller || (n & (1LL<<pos))) ret += solve(pos-1, cnt1+1, smaller);
	return dp[pos][cnt1][smaller] = ret;
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
	cin >> n;
	n--;
	memset(dp, -1, sizeof(dp));
	cout << solve(38,0,0) << '\n';
	return 0;
}
