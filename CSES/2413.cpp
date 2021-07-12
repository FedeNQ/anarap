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
#define MAXN 2000
#else
#define MAXN 1000010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll dp[2][MAXN];
#define MOD 1000000007

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
	
	int t; cin >> t;
	forn(T,t){
		memset(dp, 0, sizeof(dp));
		int n; cin >> n;
		dp[0][0]=1;
		dp[1][0]=1;
		forn(i,n){
			dp[0][i+1] = (dp[0][i]*2+dp[1][i])%MOD;
			dp[1][i+1] = (dp[1][i]*4+dp[0][i])%MOD;
		}
		cout << (dp[0][n-1]+dp[1][n-1])%MOD << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

