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

typedef __int128 ll;
typedef pair<int,int> ii;

/*unordered_map<ll,int> m;

bool go(ll x, ll y, ll n)
{
	while(x != y && m[x] < 2)
	{
		m[x]++;
		x = x*2%n;
		y = y*4%n;
	}
	return x == y;
}*/

__int128 expMod(ll b,ll e,const ll m) //O(log b)
{
	if(!e) return 1;
	__int128 q=expMod(b,e/2,m);
	q=q*q%m;
	return e%2? b*q%m : q;
}

// Returns minimum x for which a ^ x % m = b % m, a and m are coprime.
ll solve(__int128 a, __int128 b, ll m) {
    a %= m, b %= m;
    ll n = sqrtl((long double)m) + 1;

    __int128 an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    map<ll, ll> vals;
    for (ll q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (ll p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            ll ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}

__int128 inverso(ll x, const ll m)
{
	return expMod(x, m-2, m);
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
	long long n,x,a,y,b;
	cin >> n >> x >> a >> y >> b;
	/*if(x == y) cout << "0\n";
	else if(a == b) cout << "-1\n";
	else*/
	{
		if(b < a) swap(x,y), swap(a,b);
		ll pot2 = expMod(2,b-a,n);
		ll xinvy = x*inverso(y,n)%n;
		ll ans = solve(pot2,xinvy,n);
		if(ans == -1) cout << "-1\n";
		else
		{
			assert(x*expMod(expMod(2,a,n), ans, n)%n == x*expMod(2,a*ans,n)%n);
			cout << (long long)ans << ' ' << (long long)(x*expMod(expMod(2,a,n), ans, n)%n) << '\n';
		}
	}
	return 0;
}
