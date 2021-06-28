
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
#define MAXN 100
#else
#define MAXN 504
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int r,c;
ll dp[MAXN][MAXN][12];
bool high[MAXN][MAXN];
int mx[MAXN][MAXN];
#define INF 400000000


bool valid(int x){
	if(x<0 || x>=r) return false;
	return true;
}
ll solve(int x, int y, int val){
	if(y==c || val == -1){
		if(val == 0) return 0;
		else return INF*2;
	}
	else if(mx[x][y] == -1) return INF*2;
	else if(dp[x][y][val] != INF+5) return dp[x][y][val];
	else{
		int soy = high[x][y];
		int actx = x-1;
		//~ cout << " ME INTENTO MOVER " << x << " " << y << " " << val << '\n';
		forn(i,3){
			if(valid(actx+i)) dp[x][y][val] = min(dp[x][y][val],mx[x][y]+solve(actx+i, y+1, val-soy));
		}
	}
		return dp[x][y][val];
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
	int n;
	cin >> r >> c >> n;
	forn(i,r){
		forn(j,c){
			cin >> mx[i][j];
			forn(x,11){
				dp[i][j][x] = INF+5;
			}
		}
	}
	forr(j,1,c-1){
		forr(i,1,r-1){
			if(mx[i][j]!=-1 && mx[i][j] > mx[i][j-1] && mx[i][j] > mx[i][j+1] && mx[i][j-1]!=-1 && mx[i][j+1]!=-1 && mx[i][j] < mx[i-1][j] && mx[i][j] < mx[i+1][j]) high[i][j]=true;
		}
	}
	
	forn(i,r) dp[i][c-1][0] = mx[i][c-1];
	vector<int> var = {-1, 0, 1};
	
	
	dforn(j, c-1){
		forn(i, r){
			if(mx[i][j] == -1) continue;
			//~ cout << i << " " << j << endl;
			if(high[i][j]){
				//~ if(j==5) cout << "HOLA" << endl;
				forr(x,1,n+1){
					forn(p, 3){
						int nextx = i+var[p];
						if(valid(nextx)) dp[i][j][x] = min(dp[i][j][x], mx[i][j] + dp[nextx][j+1][x-1]);
						//~ if(j==5)cout << "INTENTOX " << dp[i][j][x] << " " << i << " " << j << " " << x << '\n';
					}
				};
			}
			else{
				forr(x,0,n+1){
					forn(p, 3){
						int nextx = i+var[p];
						if(valid(nextx)){
							 dp[i][j][x] = min(dp[i][j][x], mx[i][j] + dp[nextx][j+1][x]);
							 //~ if(i == 2 && j == 4) cout << nextx << " " << j+1 << " " << x << " " << dp[nextx][j+1][x] << endl;
						 }
					}
				}
			}
		}
	}
	
	//~ forn(i,r)cout << dp[i][5][1] << '\n';
	//~ cout << " A " << endl;
	//~ forn(i,r)cout << dp[i][4][1] << '\n';
	
	ll ans = INF*2;
	//~ forn(x,r){
		//~ if(mx[x][0] != -1){
			 //~ ans = min(ans, solve(x,0,n));
		 //~ }
	//~ }
	forn(x,r){
		//~ cout << dp[x][0][n] << '\n';
		ans = min(ans, dp[x][0][n]);
	}
	if(ans >= INF) cout << "impossible\n";
	else cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
