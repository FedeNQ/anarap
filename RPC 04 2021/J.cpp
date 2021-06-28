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

vector<int> g[26];
int dp[26];

int solve(int node)
{
	if(dp[node] != -1) return dp[node];
	int ret = 0;	
	forall(it,g[node]) ret = max(ret, solve(*it));
	return dp[node] = ret+1;
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
	int n,k;
	cin >> n >> k;
	vector<vector<int>> v(n, vector<int>(k));
	int fromto[26][26];
	memset(fromto, 0, sizeof(fromto));
	forn(i,n)forn(j,k)
	{
		char c;
		cin >> c;
		v[i][j] = c-'A';
		forn(pos,j) fromto[v[i][pos]][v[i][j]]++;
	}
	forn(i,k)forn(j,k) if(i != j && fromto[i][j] > 0 && fromto[j][i] == 0) g[i].pb(j);
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	forn(i,k) ans = max(ans, solve(i));
	cout << ans << '\n';
	return 0;
}
