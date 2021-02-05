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
#define MAXN 10001
#endif

#define MAXK 101

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define INF 1000100100

int n, s[MAXN], v[MAXN], p[MAXN], dp[MAXN][MAXK];

int solve(int pos, int k)
{
	if(pos == n)
	{
		if(k > 0) return -INF;
		return 0;
	}
	if(dp[pos][k] != -1) return dp[pos][k];
	return dp[pos][k] = max(solve(pos+1, max(0, k-s[pos])), solve(pos+1, k) + max(v[pos], p[pos]));
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
	int t;
	cin >> t;
	forn(T,t)
	{
		int k;
		cin >> n >> k;
		forn(i,n) cin >> s[i] >> v[i] >> p[i];
		memset(dp, -1, sizeof(dp));
		int ans = solve(0,k);
		if(ans < 0) cout << "NO SOLUTION\n";
		else cout << ans << '\n';
	}
	return 0;
}

