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

bool simular(ll hp, ll at, ll def){
	ll hp2 = 103, at2 = 9, def2=2;
	int cont = 0;
	while(1){
		if(cont%2) hp -= max(1LL,(at2-def));
		else hp2 -= max(1LL,(at-def2)); 
		if(hp <= 0 || hp2 <= 0) break;
		cont++;
	}
	//~ if(hp>hp2) cout << hp << " " << at << " " << def << " " << (hp>hp2) << '\n';
	if(hp > hp2) return 1;
	return 0;
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
	vector<vector<int>> w(5), a(6), r(8);
	string p;
	forn(i,5){
		cin >> p;
		w[i].resize(3);
		forn(j,3) cin >> w[i][j];
	}
	forn(i,5){
		cin >> p;
		a[i].resize(3);
		forn(j,3) cin >> a[i][j];
	}
	a[5].resize(3);
	forn(j,3) a[5][j] = 0;
	
	forn(i,6){
		cin >> p >> p;
		r[i].resize(3);
		forn(j,3) cin >> r[i][j];
	}
	r[6].resize(3), r[7].resize(3);
	forn(j,3){r[6][j]=0, r[7][j]=0;}
	
	forn(i,5){
		cout << w[i][0] << " " << w[i][1] << " " << w[i][2] << '\n';
		cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << '\n';
		cout << r[i][0] << " " << r[i][1] << " " << r[i][2] << '\n';
	}
	
	ll ans = 0;
	forn(W, 5){
		forn(A, 6){
			forn(R1, 8){
				forr(R2,R1+1,8){
					ll cost = w[W][0] + a[A][0] + r[R1][0] + r[R2][0];
					ll hp = 100, at = 0, def = 0;
					at += w[W][1] + a[A][1] + r[R1][1] + r[R2][1];
					def+= w[W][2] + a[A][2] + r[R1][2] + r[R2][2];
					if(!simular(hp,at,def)){
						ans = max(cost, ans);
						//~ cout << cost << '\n';
					}
				}
			}
		}
	}
	cout << ans << '\n';

	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


