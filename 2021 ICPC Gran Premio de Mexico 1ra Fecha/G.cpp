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
	int t; t=1;
	#ifdef ANARAP 
	cin >> t;
	#endif
	
	forn(T,t){
		int n; cin >> n;
		int m; cin >> m;
		
		if(n<=m){cout << "Pay the bill\n"; continue;}
		
		if(m==1){
			int st = n-1;
			dforn(i,n){
				if(__builtin_popcount(i) % 2){
					int dif = st-i;
					if(dif%2) cout << "Pay the bill\n";
					else cout << "Free snacks!\n";
					break;
				}
			}
		}
		else if(m==2){
			int valNow = m+1;
			int posMoved = 0;
			while(__builtin_popcount(valNow) % 2){posMoved++; valNow++;}
			if(valNow >= n){
				if(posMoved < 2) cout << "Free snacks!\n";
				else cout << "Pay the bill\n";
			}
			else{
				while(1){
					valNow += m;
					if(valNow >= n){cout << "Pay the bill\n"; break;}
					valNow++;
					posMoved=0;
					while(__builtin_popcount(valNow) % 2){
						posMoved++;
						valNow++;
					}
					if(valNow == n){
						if(posMoved < 2) cout << "Free snacks!\n";
						else cout << "Pay the bill\n";
						break;
					}
				}
			}
		}
		else{
			int valNow = m+1;
			while(__builtin_popcount(valNow) % 2){valNow++; }
			if(valNow >= n) cout << "Free snacks!\n";
			else{
				while(1){
					valNow += m;
					if(valNow >= n){cout << "Pay the bill\n"; break;}
					valNow++;
					while(__builtin_popcount(valNow) % 2)	valNow++;
					if(valNow == n){cout << "Free snacks!\n"; break;}
				}
			}
		}
		
	}
	
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



