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
	vector<ll> q(10), nxt(10);
	for(int i=0; i<sz(p); i+=2) q[p[i]-'0']++;
	forn(i,10) cout << q[i] << " ";
	cout << '\n';
	int cont = 256;
	while(cont--){
		forn(i,10) nxt[i] = 0;
		forn(i,10){
			if(i == 0){
				nxt[8]+=q[0];
				nxt[6]+=q[0];
			}
			else{
				nxt[i-1]+=q[i];
			}
		}
		forn(i,10) q[i] = nxt[i];
		//~ forn(i,10) cout << q[i] << " ";
	//~ cout << '\n';
	}
	ll sum = 0;
	forn(i,10) sum+=q[i];
	cout << sum << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



