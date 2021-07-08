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
typedef pair<ii,int> iii;

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

bool cmp(iii &a, iii &b)
{
	if(a.fst.snd != b.fst.snd) return a.fst.snd < b.fst.snd;
	if(a.fst.fst != b.fst.fst) return a.fst.fst > b.fst.fst;
	assert(false);
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
	int n;
	cin >> n;
	vector<iii> v(n);
	forn(i,n)
	{
		cin >> v[i].fst.fst >> v[i].fst.snd;
		v[i].fst.snd *= -1;
		v[i].snd = i;
	}
	sort(v.begin(), v.end());
	forn(i,n) v[i].fst.snd *= -1;
	vector<int> containsOther(n, 0), isInOther(n, 0);
	ordered_set s;
	forn(i,n)
	{
		isInOther[v[i].snd] = sz(s) - s.order_of_key(mp(v[i].fst.snd, 0));
		s.insert(mp(v[i].fst.snd, v[i].snd));
	}
	sort(v.begin(), v.end(), cmp);
	s.clear();
	forn(i,n)
	{
		containsOther[v[i].snd] = sz(s) - s.order_of_key(mp(v[i].fst.fst, 0));
		s.insert(mp(v[i].fst.fst, v[i].snd));
	}
	forn(i,n)
	{
		if(i) cout << ' ';
		cout << containsOther[i];
	}
	cout << '\n';
	forn(i,n)
	{
		if(i) cout << ' ';
		cout << isInOther[i];
	}
	cout << '\n';
	return 0;
}
