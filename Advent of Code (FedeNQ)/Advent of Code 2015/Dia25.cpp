// ANARAP 💙💛💙
// 💧🙌🏻
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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 33554393

ll mulMod(ll a,ll b,ll m=MOD) //O(log b)
{ //returns (a*b) %c, and minimize overfloor
	ll x=0, y=a%m;
	while(b>0)
	{
		if(b%2==1) x=(x+y)%m;
		y=(y*2)%m;
		b/=2;
	}
	return x%m;
}
ll expMod(ll b,ll e,ll m=MOD) //O(log b)
{
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=mulMod(q,q,m);
	return e%2? mulMod(b,q,m) : q;
}

ll gauss(ll x){
	return x * (x+1) / 2;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll x,y; cin >> x >> y;
	ll val = gauss(x+y-2)+y - 1;
	cout << val << '\n'; 
	ll st = 20151125;
	ll mult = 252533;
	mult = expMod(mult, val);
	ll ans = (st * mult)%MOD;
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


