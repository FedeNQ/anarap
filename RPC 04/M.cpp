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
#define MAXC 1000
#else
#define MAXC 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,c;
	cin >> n >> c;
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> acum(n+1,0);
	forn(i,n) acum[i+1] = acum[i]+v[i];
	vector<bitset<MAXC>> dp(n+1);
	dp[n].set(0);
	dforn(pos,n) forn(k,c)
	{
		if(dp[pos+1][k] || (v[pos] <= k && dp[pos+1][k-v[pos]]))
		{
			dp[pos].set(k);
			//cout << pos << ' ' << k << '\n';
		}
	}
	dforn(extra,c)
	{
		int pos = ub(v.begin(), v.end(), extra) - v.begin();
		int aux = c-extra-acum[pos];
		if(aux >= 0 && dp[pos][aux])
		{
			cout << c-extra << '\n';
			return 0;
		}
	}
	assert(false);
	return 0;
}
