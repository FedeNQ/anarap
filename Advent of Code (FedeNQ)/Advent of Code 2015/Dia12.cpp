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
	string p;
	ll ans  = 0;
	while(cin >> p){
		int cont = 0;
		bool can = 1;
		forn(i,sz(p)){
			if(p[i] == '{') cont++;
			if(p[i] == '}') cont--;
			if(cont > 0 && p[i] == 'r' && i+2 < sz(p) && p[i+1] == 'e' && p[i+2] == 'd') can=0;
			if(cont == 0) can = 1;
			if(p[i] >= '0' && p[i] <= '9' && can){
				ll now = 0;
				int pos = i;
				while(pos < sz(p)){
					if(p[pos] >= '0' && p[pos]<='9'){
						now *= 10;
						now += p[pos]-'0';
					}
					else break;
					pos++;
				}
				if(i-1 >= 0 && p[i-1] == '-') now*=-1;
				ans += now;
				i=pos-1;
			}
		}
	}
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


