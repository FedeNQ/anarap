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

int solve(vector<int> &v)
{
	int n = sz(v);
	stack<int> st;
	int ret = 0;
	forn(i,n)
	{
		while(!st.empty() && st.top() < v[i]) ret++, st.pop();
		st.push(v[i]);
	}
	return ret;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	int ans = solve(v);
	reverse(v.begin(), v.end());
	cout << ans+solve(v) << '\n';
	return 0;
}
