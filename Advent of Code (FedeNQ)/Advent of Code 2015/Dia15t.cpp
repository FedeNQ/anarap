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
	
	string p,a;
	vector<vector<int>> v(2);
	int cont = 0;
	while(cin >> a){
		v[cont].resize(5);
		cin >> p >> v[cont][0] >> p >> p >> v[cont][1] >> p >> p >> v[cont][2] >> p >> p >> v[cont][3] >> p >> p >> v[cont][4];
		cont++;
	}
	ll ans = 0;
	forn(i1, 101){
		forn(i2,101){
			if(i1+i2 != 100) continue;
			ll score = 1;
			forn(i,4){
				ll act = i1*v[0][i] + i2*v[1][i];
				if(act <= 0) act = 0;
				score *= act;
			}
			//~ if(score > ans && score == 3600000000) cout << i1 << " " << i2 << '\n';
			ans = max(ans, score);
		}
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



