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
	vector<ii> v(n);
	forn(i,n) cin >> v[i].snd;
	forn(i,n) cin >> v[i].fst;
	sort(v.begin(), v.end());
	ll ans = 1, acum = 0;
	forn(i,n) if(v[i].fst != -1)
	{
		ll cur = v[i].fst;
		acum += v[i].snd;
		ans = max(ans, (acum+cur-1)/cur);
	}
	cout << ans << '\n';
	return 0;
}
