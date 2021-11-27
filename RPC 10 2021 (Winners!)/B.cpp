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

ll sumDigs(ll x){
	ll ret = 0;
	while(x) ret+=(x%10), x/=10;
	return ret;
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
	int d, k;
	while(cin >> d >> k){
		if(d==0 && k==0) break;
		ll uno = (d*d)%10;
		ll dos = (d*d)/10;
		ll resto = 0;
		ll ans = 0;
		forn(i,k){
			ll now = i+1;
			ll add = uno * now + resto;
			//~ cout << "agrego " << add%10 << endl;
			ans += add%10;
			add/=10;
			resto = 0;
			resto += add;
			resto += dos*now;
			//~ cout << ans << " " << resto << "\n";
		}
		dforn(i,k-1){
			ll now = i+1;
			ll add = uno * now + resto;
			//~ cout << "agrego " << add%10 << endl;
			ans += add%10;
			add/=10;
			resto = 0;
			resto += add;
			resto += dos*now;
			//~ cout << ans << " " << resto << "\n";
		}
		ans += sumDigs(resto);
		cout << ans << '\n';
	}
	
	
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


