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

#define MAXM 10001

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll MOD = (1LL<<31)-1;
	unordered_set<ll> s;
	ll fibo[MAXM];
	fibo[0] = 0;
	fibo[1] = 1;
	forr(i,2,MAXM) fibo[i] = (fibo[i-1]+fibo[i-2])%MOD;
	forn(i,MAXM) s.insert(fibo[i]);
	int t;
	cin >> t;
	forn(T,t)
	{
		ll n;
		cin >> n;
		if(s.count(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
