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

struct Movie{
	int a,b,id;
};

bool cmp(Movie &a, Movie &b)
{
	if(a.b != b.b) return a.b < b.b;
	return a.id < b.id;
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
	int n, k;
	cin >> n >> k;
	vector<Movie> v(n);
	forn(i,n)
	{
		cin >> v[i].a >> v[i].b;
		v[i].id = i;
	}
	sort(v.begin(), v.end(), cmp);
	int ans = 0;
	multiset<int> slast;
	forn(i,k) slast.insert(0);
	forn(i,n)
	{
		multiset<int>::iterator ite = slast.ub(v[i].a);
		if(ite != slast.begin())
		{
			ans++;
			slast.erase(prev(ite));
			slast.insert(v[i].b);
		}
	}
	cout << ans << '\n';
	return 0;
}
