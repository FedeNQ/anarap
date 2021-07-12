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

ll solve(ll n, int lvl, bool ok, int stlvl = -1){
	if(!ok){
	
		ll aux = 9;
		forn(i,lvl-1) aux*=10;
		aux *= lvl;
		//~ cout << n << " " << lvl << " " << ok << " " << aux << '\n';
		if(aux >= n){
			 if(lvl==1) return n;
			 return solve(n,lvl,1,lvl);
		 }
		else { 
			n-=aux;
			return solve(n, lvl+1, ok);
		}
	}
	else{
		//~ cout << " RESOLVER " << n << " " << lvl << " " << 1 << '\n';
		
		if(n%lvl == 1 || lvl == 1){
			ll szb = 1;
			forn(i,lvl-1) szb*=10;
			szb*=lvl;
			ll ans = (n+szb-1)/szb;
			if(stlvl == lvl) return ans%10;
			return (ans-1)%10;
		}
		else {
			ll piso = (n+lvl-1)/lvl;
			n-=piso;
			return solve(n, lvl-1, 1);
		}
	}
	return -1;
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
	
	int q; cin >> q;
	forn(Q, q){
		ll k; cin >> k;
		cout << solve(k, 1, 0) << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


