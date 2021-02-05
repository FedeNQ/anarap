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

#define MOD 1000000000

ll expMod(ll b,ll e,ll m=MOD){
	if(!e)return 1;
	ll q=expMod(b,e/2,m);
	q=q*q%m;
	return e%2? b*q%m : q;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(T,t)
	{
		ll k,q;
		cin >> k >> q;
		vector<ll> v(k);
		forn(i,k) cin >> v[i];
		forn(_,q)
		{
			ll x;
			cin >> x;
			cout << (expMod(v[x%k], 1+x/k)+MOD)%MOD << '\n';
		}
	}
	return 0;
}
