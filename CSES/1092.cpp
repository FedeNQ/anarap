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
	int n;
	cin >> n;
	ll sum = 0;
	forn(i,n+1) sum += i;
	if(n%4 == 1 || n%4 == 2) cout << "NO\n";
	else
	{
		vector<int> v1,v2;
		int l = 1, r = n;
		if(n%4 == 3)
		{
			v1.pb(1);
			v1.pb(2);
			v2.pb(3);
			l = 4;
		}
		while(l < r)
		{
			assert((r-l+1)%4 == 0);
			v1.pb(l++); v1.pb(r--);
			v2.pb(l++); v2.pb(r--);
		}
		cout << "YES\n";
		cout << sz(v1) << '\n';
		forn(i,sz(v1))
		{
			if(i) cout << ' ';
			cout << v1[i];
		}
		cout << '\n';
		cout << sz(v2) << '\n';
		forn(i,sz(v2))
		{
			if(i) cout << ' ';
			cout << v2[i];
		}
		cout << '\n';
	}
	return 0;
}
