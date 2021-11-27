
// ANARAP 💙💛💙
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

#define MAXN 1003
char mx[MAXN][MAXN];
int dp[MAXN][MAXN];
int d[3] = {-1,0,1};

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
		forn(j,m) mx[i][j] = p[j];
	}
	vector<int> alfa[26];
	forn(i,n) forn(j,m) alfa[mx[i][j]-'A'].pb(i*m+j);
	forn(i,n) forn(j,m) dp[i][j] = 1;
	forn(i,26){
		forall(it, alfa[i]){
			int x = *it/m, y = *it%m;
			forn(dx,3){
				forn(dy,3){
					if(d[dx] == 0 && d[dy] == 0) continue;
					int xx = x+d[dx];
					int yy = y+d[dy];
					if(xx>=0 && xx < n && yy>=0 && yy < m){
						if(mx[xx][yy] - 'A' == i+1) dp[xx][yy] = max(dp[x][y]+1, dp[xx][yy]);
					}
				}
			}
		}
	}
	int ans = 0;
	forn(i,n) forn(j,m) ans = max(ans, dp[i][j]);
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


