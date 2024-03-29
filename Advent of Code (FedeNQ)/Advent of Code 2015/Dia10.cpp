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
	
	string p; cin >> p;
	vector<int> v;
	forall(it,p) v.pb(*it-'0');
	int x = 50;
	while(x--){
		int cont = 1;
		vector<int> nxt;
		forr(i,1,sz(v)){
			if(v[i] == v[i-1]) cont++;
			else{
				vector<int> aux;
				while(cont > 0){
					aux.pb(cont%10);
					cont/=10;
				}
				dforn(j,sz(aux)) nxt.pb(aux[j]);
				nxt.pb(v[i-1]);
				cont=1;
			}
		}
		vector<int> aux;
		while(cont > 0){
			aux.pb(cont%10);
			cont/=10;
		}
		dforn(j,sz(aux)) nxt.pb(aux[j]);
		nxt.pb(v.back());
		v.clear();
		forall(it,nxt) v.pb(*it);
	}
	cout << sz(v) << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


