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

int n;
ll dp[20][11][2][2];
string s;

ll solve(int pos, int last, bool smaller, bool notz)
{
	if(!notz) last = 10;
	if(pos == n) return 1;
	if(dp[pos][last][smaller][notz] != -1) return dp[pos][last][smaller][notz];
	ll ret = 0;
	forn(i,10) if(i != last && (smaller || i <= s[pos]-'0')) ret += solve(pos+1, i, smaller || i < s[pos]-'0', notz || i > 0);
	return dp[pos][last][smaller][notz] = ret;
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
	ll aa, bb;
	cin >> aa >> bb;
	stringstream ss;
	ss << aa-1 << ' ' << bb;
	string a,b;
	ss >> a >> b;
	n = sz(b);
	s = b;
	memset(dp, -1, sizeof(dp));
	ll ans = solve(0, 10, false, false);
	n = sz(a);
	s = a;
	memset(dp, -1, sizeof(dp));
	if(aa > 0) ans -= solve(0, 10, false, false);
	cout << ans << '\n';
	return 0;
}
