
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
	int n; cin >> n;
	while(n!=0){
		int faul = 0;
		forn(N,n){
			string p;
			cin >> p;
			ll D = 34200;
			ll E = 45000; 
			ll O = 30600;
			ll st=0, en=0;
			int cont = 0;
			bool ok = 1;
			ll acum = 0;
			p+=":";
			forr(i,2,sz(p)){
				if(p[i] == ':'){
					cont++;
					if(cont == 1){
						if(ok) st += acum*60*60;
						else en += acum*60*60;
					}
					else if(cont == 2){
						if(ok) st += acum*60;
						else en += acum*60;
					}
					else if(cont == 3){
						if(ok){
							 st+= acum;
							 ok = false;
							 cont = 0;
						 }
						else en+= acum;
					}
					acum = 0;
				}
				else{
					acum = acum*10 + (p[i]-'0');
				}
			}
			//~ cout << st << " " << en << '\n';
			st = max(st, O);
			if(p[0] == 'D'){
				if(st > D) faul++;
				else{
					if(en-st < 28800) faul++;
				}
			}
			else{
				if(st > E) faul++;
				else if(en-st < 32400) faul++;
			}
		}
		
		if(faul == 0) cout << "All OK\n";
		else if(faul == 1) cout << "1 Point(s) Deducted\n";
		else if(faul == 2) cout << "2 Point(s) Deducted\n";
		else if(faul == 3) cout << "3 Point(s) Deducted\n";
		else cout << "Issue Show Cause Letter\n";
		cin >> n;
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

