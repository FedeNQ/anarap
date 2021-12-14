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
	vector<ll> v(n);
	forn(i,n) cin >> v[i];
	vector<vector<ll>> dp(n, vector<ll>(n));
	forn(i,n) dp[n-1][i] = v[n-1];
	dforn(pos,n-1)
	{
		ll best = v[pos]+dp[pos+1][1];
		forr(jump,1,n)
		{
			if(pos+jump < n) best = max(best, v[pos]+dp[pos+jump][jump]);
			dp[pos][jump] = best;
		}
	}
	ll ans = dp[0][1];
	forr(i,2,n) ans = max(ans, dp[0][i]);
	cout << ans << '\n';
	return 0;
}
