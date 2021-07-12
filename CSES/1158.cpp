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
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int dp[1010][MAXN];
int n, x;
ii cost[1010];

//~ ll solve(int pos, int act){
	//~ if(pos >= n) return 0;
	//~ if(dp[pos][act] != -1) return dp[pos][act];
	//~ int ret = 0;
	//~ ret = solve(pos+1, act);
	//~ if(act-cost[pos].fst >= 0) ret = max(ret, solve(pos+1, act-cost[pos].fst)+cost[pos].snd);
	//~ return dp[pos][act]=ret;
//~ }

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
	
	cin >> n >> x;
	forn(i,n) cin >> cost[i].fst;
	forn(i,n) cin >> cost[i].snd;
	memset(dp,0,sizeof(dp));
	forn(i,n){
		dforn(j, x+1){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j-cost[i].fst >= 0) dp[i+1][j-cost[i].fst] = max(dp[i+1][j-cost[i].fst], dp[i][j] + cost[i].snd);
		}
	}
	int ans = 0;
	forn(j, x+1) ans = max(dp[n][j], ans);
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

