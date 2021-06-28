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
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXN 5001
#define MAXM 21

int dp[MAXN][MAXM];
vector<int> vans;

int solve(int n, int m, bool fst)
{
	assert(m >= 1);
	if(n == 0) return 0;	
	if(m == 1)
	{
		if(fst) vans.pb(1);
		return n;
	}
	if(dp[n][m] != -1) return dp[n][m];
	int ret = MAXN;
	forr(i,1,n+1)
	{
		int aux = 1+max(solve(i-1, m-1, false), solve(n-i, m, false));
		if(aux < ret)
		{
			ret = aux;
			if(fst) vans.clear();
		}
		if(fst && aux == ret) vans.pb(i);
	}
	assert(ret < MAXN);	
	return dp[n][m] = ret;
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
	int n,m;
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	int ans = solve(n, m, true);
	assert(!vans.empty());
	cout << ans << ' ';
	if(sz(vans) == 1) cout << vans[0];
	else cout << vans[0] << '-' << vans.back();
	cout << '\n';
	return 0;
}
