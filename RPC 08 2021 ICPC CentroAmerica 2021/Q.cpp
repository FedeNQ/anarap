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

#define INF 1000100100100LL

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<ll> v;
	v.reserve(1e6);
	v.pb(1);
	ll n = 1;
	while(v.back() < INF)
	{
		n++;
		v.pb(n*(3*n-1)/2);
	}
	int t;
	cin >> t;
	forn(T,t)
	{
		ll x;
		cin >> x;
		vector<ll>::iterator ite = ub(v.begin(), v.end(), x);
		if(*ite-x < x-*prev(ite)) cout << *ite << '\n';
		else cout << *prev(ite) << '\n';
	}
	return 0;
}
