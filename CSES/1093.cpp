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
#define MAXN 50
#else
#define MAXN 501
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007

int dp[MAXN][MAXN*MAXN], n;

int solve(int x, int k)
{
	if(k == 0) return 1;
	if(x > n || x > k) return 0;
	if(dp[x][k] != -1) return dp[x][k];
	return dp[x][k] = (solve(x+1, k)+solve(x+1,k-x))%MOD;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	if(n*(n+1)/2%2) cout << "0\n";
	else cout << solve(1,n*(n+1)/4)*500000004LL%MOD << '\n';
	return 0;
}
