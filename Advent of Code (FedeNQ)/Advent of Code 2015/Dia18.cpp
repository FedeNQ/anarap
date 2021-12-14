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

#define MAXN 103
char mx[MAXN][MAXN];
char nxt[MAXN][MAXN];
int d[3] = {-1,0,1};

#define n 100

bool valid(int x, int y){
	if(x>=0 && x<n && y>=0 && y<n) return 1;
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
	
	forn(i, n){
		string p; cin >> p;
		forn(j, n) mx[i][j] = p[j];
	}
	int cont = 100;
	while(cont--){
		forn(i,n){
			forn(j,n){
				if((i==0 || i==n-1) && (j==0 || j==n-1)){
					nxt[i][j]='#';
					continue;
				}
				int v = 0;
				forn(dx,3){
					forn(dy,3){
						if(d[dx] == 0 && d[dy] == 0) continue;
						if(i==0 && j==0){
							cout << i+d[dx] << " " << j+d[dy] << '\n';
							cout << valid(i+d[dx], j+d[dy]) << '\n';
						}
						if(valid(i+d[dx], j+d[dy])){
							if(mx[i+d[dx]][j+d[dy]] == '#') v++;
						}
					}
				}
				if(i==0 && j==0) cout << v << '\n';
				if(mx[i][j] == '#'){
					if(v == 2 || v==3) nxt[i][j] = '#';
					else nxt[i][j] = '.';
				}
				else{
					if(v==3) nxt[i][j] = '#';
					else nxt[i][j] = '.';
				}
			}
		}
		forn(i,n){
			forn(j,n){
				mx[i][j] = nxt[i][j];
			}
		}
	}
	ll ans = 0;
	forn(i,n){
		forn(j,n){
			cout << mx[i][j];
			
		}
		cout << '\n';
	}
	forn(i,n) forn(j,n) if(mx[i][j] == '#') ans++;
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


