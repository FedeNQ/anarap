// ANARAP 💙💛💙
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

#define MOD 1000000007

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
	
	int n; cin >> n;
	int q; cin >> q;
	vector<ll> pot2(n+2);
	pot2[0] = 1;
	forr(i,1,n+1) pot2[i] = (pot2[i-1]*2LL) % MOD; 
	map<ll,ll> acum;
	forn(i,q){
		ll x; cin >> x;
		ll val = 1;
		int lvlq = 0;
		while(val <= x){
			val = val*2;
			lvlq++;
		}
		ll rta = ((pot2[n-lvlq] - acum[x])%MOD+MOD)%MOD;
		cout << rta << '\n';
		dforn(j,31){
			if((1LL<<j)&x){
				x = (x ^ (1LL<<j));
				acum[x] = ((acum[x]+rta)%MOD+MOD)%MOD;
			}
		}
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


