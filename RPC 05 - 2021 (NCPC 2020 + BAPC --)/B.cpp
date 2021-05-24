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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	ll ans = 0;
	forn(i,n)dforn(j,n)
	{
		if(j == i) break;
		int atLeast = v[j]-v[i]+1;
		int cnt = 0;
		forr(k,i+1,j) if(v[k] >= atLeast) cnt++;
		ll aux = 1;
		forn(_,cnt) aux *= 2;
		ans += aux-1;
	}
	cout << ans << '\n';
	return 0;
}
