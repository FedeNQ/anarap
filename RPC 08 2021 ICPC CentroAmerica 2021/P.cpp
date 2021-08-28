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
	int n,m,q,d[3] = {-1,0,1};
	cin >> n >> m >> q;
	vector<vector<int>> v(n, vector<int>(m));
	forn(i,n)forn(j,m) cin >> v[i][j];
	set<ii> s;
	forn(_,q)
	{
		int r,c;
		cin >> r >> c;
		r--;c--;
		forn(i,3)forn(j,3)
		{
			int rr = r+d[i], cc = c+d[j];
			if(rr < 0 || cc < 0 || rr >= n || cc >= m || v[rr][cc] == 0) continue;
			s.insert(mp(rr,cc));
		}
	}
	cout << sz(s) << '\n';
	return 0;
}
