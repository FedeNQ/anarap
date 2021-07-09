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
//<key,mapped type,comparator,...>
typedef tree<ii,null_type,less<ii>,rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;
//find_by_order(i) devuelve iterador al i-esimo elemento
//order_of_key(k): devuelve la pos del lower bound de k
//Ej: 12, 100, 505, 1000, 10000.
//order_of_key(10) == 0, order_of_key(100) == 1,
//order_of_key(707) == 3, order_of_key(9999999) == 5


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	vector<int> v(n+1, 0);
	forn(i,n) cin >> v[i+1];
	n++;
	ordered_set s;
	ll curcost = 0;
	forn(i,k) s.insert(mp(v[i], i));
	ii curmed = *s.find_by_order((sz(s)-1)/2);
	forn(i,k) curcost += abs(curmed.fst-v[i]);
	forr(i,k,n)
	{
		// take out
		curcost -= abs(curmed.fst-v[i-k]);
		s.erase(mp(v[i-k], i-k));
		s.insert(mp(v[i], i));
		
		// get new median
		ii nxtmed = *s.find_by_order((sz(s)-1)/2);
		s.erase(mp(v[i], i));
		
		// calc changes on remaining
		if(nxtmed.fst > curmed.fst)
		{
			curcost -= (sz(s)-s.order_of_key(nxtmed))*(nxtmed.fst - (ll)curmed.fst);
			curcost += s.order_of_key(nxtmed)*(nxtmed.fst - (ll)curmed.fst);
		}
		else if(nxtmed.fst < curmed.fst)
		{
			curcost += (sz(s)-s.order_of_key(curmed))*(curmed.fst - (ll)nxtmed.fst);
			curcost -= s.order_of_key(curmed)*(curmed.fst - (ll)nxtmed.fst);
		}
		
		// add new one
		s.insert(mp(v[i], i));
		curmed = nxtmed;
		curcost += abs(nxtmed.fst-v[i]);
		
		if(i > k) cout << ' ';
		cout << curcost;
	}
	cout << '\n';
	return 0;
}
