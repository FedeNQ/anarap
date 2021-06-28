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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<int> a(n);
	forn(i,n) cin >> a[i];
	ordered_set c;
	forn(i,n)c.insert(mp(i,a[i]));
	vector<ii> b(n);
	forn(i,n) b[i] = mp(a[i], i);
	sort(b.begin(), b.end());
	ll ans = 0;
	int act = n;
	forn(i,n-1){
		//~ cout << b[i].snd << " " << b[i].fst << '\n';
		ii aux = mp(b[i].snd, b[i].fst);
		int l = c.order_of_key(aux);
		int r = act-l-1;
		//~ cout << "possible " << l << " " << l << '\n';
		act--;
		ans += min(l,r);
		c.erase(aux);
	}
	cout << ans << '\n';
	return 0;
}
