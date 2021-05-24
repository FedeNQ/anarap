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
#define MAXN 1000100
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007

int v[MAXN],n;
ll dp[MAXN][3];

ll solve(int pos, int step)
{
	if(pos == n) return 0;
	if(dp[pos][step] != -1) return dp[pos][step];
	ll ret = solve(pos+1, step);
	if(v[pos] == 1 && step == 0) ret += solve(pos+1, 1);
	if(v[pos] == 2 && step == 1) ret += solve(pos+1, 1) + solve(pos+1, 2);
	if(v[pos] == 3 && step == 2) ret++;
	return dp[pos][step] = ret%MOD;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	forn(i,n) cin >> v[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(0,0) << '\n';	
	return 0;
}
