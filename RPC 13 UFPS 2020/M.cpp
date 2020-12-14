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

#define MAXN 22
int mx[MAXN][MAXN];
int aux[MAXN][MAXN];
int mov[3] = {0, -1, 1};

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
	
	int n,m; cin >> n >> m;
	forn(i,n){
		string p; cin >> p;
		
		forn(j,m){
			if(p[j] == '.') mx[i][j] = 0;
			else mx[i][j] = p[j]-'0';
		}
	}
	int pot = (1<<n*m);
	//~ cout << pot << '\n';
	int nporm = n*m;
	map<int, int> cool;
	forn(i,pot){
		memset(aux,0,sizeof(aux));
		int on = 0;
		bool valid = true;
		forn(j, nporm){
			if((1<<j) & i){
				on++;
				int x = j/m;
				int y = j%m;
				if(mx[x][y] != 0){valid = false;}
				else{
					forn(auxx, 3){
						forn(auxy, 3){
							if(mov[auxy] == 0 && mov[auxx] == 0) continue;
							int movx = mov[auxx]+x;
							int movy = mov[auxy]+y;
							if(movx >= 0 && movx<n && movy<m && movy>=0){
								aux[movx][movy]++;
							}
						}
					}
				}
			}
		}
		forn(ai,n){
			forn(aj, m){
				if(mx[ai][aj] != 0 && mx[ai][aj] != aux[ai][aj]) valid = false;
			}
		}
		if(valid) cool[on]++;
	}
	if(cool.empty()) cout << 0 << '\n';
	else {
		auto it = cool.begin();
		cout << it->snd << " " << it->fst << '\n';
	}
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

