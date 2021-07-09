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

vector<int> solve(vector<int> &v)
{
	int n = sz(v);
	vector<ii> s;
	vector<int> ret(n, -1e9);
	forn(i,n)
	{
		vector<ii>::iterator ite = lb(s.begin(), s.end(), mp(v[i], 0));
		if(ite != s.begin())
		{
			ite--;
			ret[i] = ite->snd;
		}
		while(!s.empty() && s.back().fst >= v[i]) s.pop_back();
		s.pb(mp(v[i], i));
	}
	return ret;
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
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	vector<int> ans = solve(v);
	forn(i,n) 
	{
		if(i) cout << ' ';
		cout << max(-1, ans[i])+1;
	}
	cout << '\n';
	return 0;
}
