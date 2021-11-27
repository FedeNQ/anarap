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

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXN 100010

int t, acum[MAXN];

inline bool canDistinguish(int s1, int s2)
{
	if(s1 > s2) swap(s1,s2);
	return acum[t/s1] - acum[t/s2] > 0;
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
	int n,m,k;
	cin >> n >> m >> k >> t;
	vector<int> vs(n);
	vector<int> vd(m);
	forn(i,n) cin >> vs[i];
	forn(i,m) cin >> vd[i];
	
	vector<bool> used(t+1, false);
	vector<int> goodD;
	goodD.reserve(t+1);
	goodD.pb(0);
	used[0] = true;
	forn(i, m)
	{
		int aux = sz(goodD);
		forn(j,aux) if(goodD[j]+vd[i] <= t && !used[goodD[j]+vd[i]]) used[goodD[j]+vd[i]] = true, goodD.pb(goodD[j]+vd[i]);
	}

	
	sort(goodD.begin(), goodD.end());
	int pos = 1;
	forr(i,1,t+1)
	{
		acum[i] = acum[i-1];
		if(pos < sz(goodD) && goodD[pos] == i) acum[i]++, pos++;
	}
	
	sort(vs.begin(), vs.end());
	int maxbest = vs[0];
	forr(i,1,n)
	{
		if(canDistinguish(vs[i-1], vs[i])) break;
		maxbest = vs[i];
	}
	int ans = 0;
	forn(i,n) if(vs[i] <= maxbest) ans++;
	cout << max(ans, k) << '\n';	
	return 0;
}
