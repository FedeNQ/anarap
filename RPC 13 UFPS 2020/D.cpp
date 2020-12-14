#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
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

ll dp[MAXN][9][5][10];
int n;
string s;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> s;
	dp[sz(s)][0][1][0] = dp[sz(s)][0][3][0] = 1;
	forr(i,1,10) dp[sz(s)][i%9][2][i] = dp[sz(s)][i%9][4][i] = 1;
	dforn(pos,sz(s))forn(mod,9)dforn(state,5)forn(r,10)
	{
		if(state == 0) dp[pos][mod][state][r] = dp[pos+1][mod][0][r];
		else if(state > 2) dp[pos][mod][state][r] = dp[pos+1][mod][state][r];
		else dp[pos][mod][state][r] = dp[pos][mod][2+state][r];
		//not digit picked yet (state 0) or digits picked sum 0 (state 1)
		if(state < 2)
		{
			if(s[pos] == '0') dp[pos][mod][state][r] += dp[pos+1][mod][1][r];
			else dp[pos][mod][state][r] += dp[pos+1][(mod+s[pos]-'0')%9][2][r];
		}
		//digits picked sum > 0
		if(state == 2) dp[pos][mod][state][r] += dp[pos+1][(mod+s[pos]-'0')%9][2][r];
		//if(dp[pos][mod][state][r] != 0) cout << pos << ' ' << mod << ' ' << state << ' ' << r << ' ' << dp[pos][mod][state][r] << '\n';
	}
	forn(i,10)
	{
		if(i) cout << ' ' ;
		cout << dp[0][0][0][i];
	}
	cout << '\n';
	return 0;
}
