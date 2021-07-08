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
	set<ii> s;
	forn(i,n)
	{
		set<ii>::iterator ite = s.lb(mp(v[i].fst.snd, 0));
		if(ite != s.end()) isInOther[v[i].snd] = 1;
		for(auto it = ite; it != s.end(); it++) containsOther[it->snd] = 1;
		if(ite != s.end() && next(ite) != s.end()) s.erase(ite, prev(s.end()));
		s.insert(mp(v[i].fst.snd, v[i].snd));
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
