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
#define MAXN 53
#else
#define MAXN 1003
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n,w,c,h,m;
bool hum[MAXN], mil[MAXN];
vector<int> g[MAXN][20];
int dp[MAXN][MAXN];

bool solve(int x, int y){
	if(mil[x] && mil[y]) return true;
	if(x>y) swap(x,y);
	if(dp[x][y]) return false;
	dp[x][y] = true;
	bool ok = 0;
	forn(i, c){
		forall(it, g[x][i]){
			if(x==y) ok = solve(*it, *it);
			forall(it2, g[y][i]) ok |= solve(*it, *it2);
			if(ok) return true;
		}
	}
	return ok;
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
	cin >> n >> w >> c >> h >> m;
	memset(hum, 0, sizeof(hum));
	forn(i,h){
		int x; cin >> x;
		hum[x] = 1;
	}
	forn(i,m){
		int x; cin >> x;
		mil[x] = 1;
	}
	
	forn(i, w){
		int a,b,d; cin >> a >> d >> b;
		d--;
		g[a][d].pb(b);
	}
//	cout << " A " << endl;
	bool ok = 0;
	memset(dp, 0, sizeof(dp));
	forn(i,n){
		forr(j, i+1, n){
			
			if(hum[j]!=hum[i]){
				ok = solve(i,j);
				
			}
			//cout << ok << endl;
			if(ok) break;
		}
		if(ok) break;
	}
	
	if(ok) cout << "YES\n";
	else cout << "NO\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 
