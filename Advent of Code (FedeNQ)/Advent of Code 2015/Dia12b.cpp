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
		forn(i,sz(p)){
			if(p[i] == 'r' && i+2 < sz(p) && p[i+1] == 'e' && p[i+2] == 'd'){
				int pos = i-1;
				bool ok =0;
				int cont = 0;
				int cont2 = 0;
				while(pos>=0){
					if(p[pos] == '[') cont2--;
					else if(p[pos] == ']') cont2++;
					if(cont2 < 0) break;
					if(p[pos] == '{') cont--;
					else if(p[pos] == '}') cont++;
					if(p[pos] == '{' && cont<0){ ok = 1; break;}
					pos--;
				}
				cout << ok << '\n';
				if(ok){
					pos=i-1;
					cont = 1;
					while(pos >= 0){
						if(p[pos] == '{') cont--;
						else if(p[pos] == '}') cont++;
						p[pos] = '$';
						if(cont == 0) break;
						pos--;
					}
					cont = 1;
					pos=i;
					while(pos < sz(p)){
						if(p[pos] == '}') cont--;
						else if(p[pos] == '{') cont++;
						p[pos] = '$';
						if(cont==0) break;
						pos++;
					}
				}
			}
		}
		cout << p << '\n';
		forn(i,sz(p)){
			
			if(p[i] >= '0' && p[i] <= '9'){
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


