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
	int n, x;
	cin >> n >> x;
	multiset<int> s;
	forn(i,n)
	{
		int xx;
		cin >> xx;
		s.insert(xx);
	}
	int ans = 0;
	while(sz(s) > 1)
	{
		ans++;
		int aux = *s.rbegin();
		s.erase(prev(s.end()));
		multiset<int>::iterator ite = s.ub(x-aux);
		if(ite != s.begin()) s.erase(prev(ite));
	}
	cout << ans+sz(s) << '\n';
	return 0;
}
