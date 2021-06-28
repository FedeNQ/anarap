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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 998244353

int n,dp[MAXN][11][2][2][2];
string l,r;

int solve(int pos, int prev, bool lower, bool bigger, bool nonz)
{
	if(pos == n) return nonz;
	if(dp[pos][prev+1][lower][bigger][nonz] != -1) return dp[pos][prev+1][lower][bigger][nonz];
	int from = 0, to = 9, ret = 0;
	if(!lower) to = r[pos]-'0';
	if(!bigger) from = l[pos]-'0';
	forr(i,from,to+1) if(i != prev)
	{
		if(i == 0) ret = (ret+solve(pos+1, min(prev, 0), lower || i < to, bigger || i > from, nonz))%MOD;
		else ret = (ret+solve(pos+1, i, lower || i < to, bigger || i > from, true))%MOD;
	}
	return dp[pos][prev+1][lower][bigger][nonz] = ret;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> r;
	n = sz(r);
	reverse(l.begin(), l.end());
	while(sz(l) < n) l.pb('0');
	reverse(l.begin(), l.end());
	memset(dp, -1, sizeof(dp));
	cout << solve(0, -1, false, false, false) << '\n';
	return 0;
}
