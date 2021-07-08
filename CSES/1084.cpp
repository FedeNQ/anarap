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
	cin >> n >> m >> k;
	vector<int> v1(n), v2(m);
	forn(i,n) cin >> v1[i];
	forn(i,m) cin >> v2[i];
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int pos2 = 0, ans = 0;
	forn(i,n)
	{
		while(pos2 < m && v2[pos2] < v1[i]-k) pos2++;
		if(pos2 == m) break;
		if(v2[pos2] <= v1[i]+k) ans++, pos2++;
	}
	cout << ans << '\n';
	return 0;
}
