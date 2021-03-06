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
	ll ans = 1e18;
	forn(bm,(1<<n))
	{
		ll sum[2] = {0,0};
		forn(i,n) if(bm & (1<<i)) sum[1] += v[i]; else sum[0] += v[i];
		ans = min(ans, abs(sum[0]-sum[1]));
	}
	cout << ans << '\n';
	return 0;
}
