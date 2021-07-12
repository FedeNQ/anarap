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

#define MOD 1000000007

int n,m;
int v[MAXN];
ll dp[102][MAXN];

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
	
	cin >> n >> m;
	forn(i,n) cin >> v[i];
	if(v[0] == 0) forn(x,m+1) dp[x][0] = 1;
	else dp[v[0]][0] = 1;
	
	forn(i,n){
		if(v[i] == 0){
			forr(x,1,m+1){
				int xx = x-1;
				forn(dif, 3){
					dp[xx+dif][i+1] += dp[x][i];
					dp[xx+dif][i+1] %= MOD;
				}
			}
		}
		else {
			int xx = v[i]-1;
			forn(dif, 3){
				dp[xx+dif][i+1] += dp[v[i]][i];
				dp[xx+dif][i+1] %= MOD;
			}
		}
	}
	ll ans = 0;
	if(v[n-1] == 0){forr(x,1, m+1){ans+=dp[x][n-1]; ans%=MOD;}}
	else ans = dp[v[n-1]][n-1];
	cout << ans%MOD << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


