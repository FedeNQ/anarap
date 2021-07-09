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

int dp[MAXN][MAXN];

int solve(int a, int b)
{
	if(a > b) swap(a,b);
	if(a == 1) return b-1;
	if(a == b) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	int ret = MAXN*MAXN;
	forr(i,1,b) ret = min(ret, 1 + solve(a, i) + solve(a, b-i));
	forr(i,1,a) ret = min(ret, 1 + solve(i, b) + solve(a-i, b));
	return dp[a][b] = ret;
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
	int a,b;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << solve(a,b) << '\n';
	return 0;
}
