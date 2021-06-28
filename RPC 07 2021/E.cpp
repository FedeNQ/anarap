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

ll mx[12][12];

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
	forn(i,n) forn(j,n) cin >> mx[i][j];
	cin >> noskipws;
	char x; cin >> x;
	cin >> x;
	vector<ll> aux;
	while(x!='\n'){
		if(x==' ') aux.pb(36);
		else if(x >= 'A' &&  x <= 'Z') aux.pb(x-'A');
		else aux.pb(26+(x-'0'));
		cin >> x;
	}
	while(sz(aux)%n != 0) aux.pb(36);
	string ans = "";
	for(int i = 0; i<sz(aux); i+=n){
		forn(i2, n){
			ll now = 0;
			forn(j, n){
				now += mx[i2][j]*aux[i+j];
				now = now%37; 
			}
			if(now == 36) ans = ans + " ";
			else if(now <= 25){
				char auxx = char(now+'A');
				ans = ans + auxx; 
			}
			else{
				now-=26;
				char auxx = char(now+'0');
				ans = ans + auxx; 
			}
		}
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


