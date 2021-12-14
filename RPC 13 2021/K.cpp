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
typedef pair<char,ii> cii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dr[4] = {-1,0,0,1}, dc[4] = {0,1,-1,0};
	char auxc[4] = {'U','R','L','D'};
	int t;
	cin >> t;
	forn(T,t)
	{
		int n,m;
		cin >> n >> m;
		vector<string> vv(n);
		forn(i,n) cin >> vv[i];
		int rs,cs,rx,cx;
		vector<vector<int>> vd(n,vector<int>(m,-1));
		forn(i,n)forn(j,m)
		{
			if(vv[i][j] == 'S') rs = i, cs = j;
			if(vv[i][j] == 'X') rx = i, cx = j;
		}
		vector<vector<cii>> vdad(n, vector<cii>(m));
		queue<ii> q;
		vd[rs][cs] = 0;
		q.push(mp(rs,cs));
		while(!q.empty())
		{
			int r = q.front().fst, c = q.front().snd;
			q.pop();
			forn(i,4)
			{
				int rr = r+dr[i], cc = c+dc[i];
				if(rr < 0 || cc < 0 || rr >= n || cc >= m || vv[rr][cc] == '#' || vd[rr][cc] != -1) continue;
				vd[rr][cc] = vd[r][c]+1;
				vdad[rr][cc] = mp(auxc[i], mp(r,c));
				q.push(mp(rr,cc));
			}
		}
		if(vd[rx][cx] == -1) cout << "No exit\n";
		else
		{
			string ans = "";
			assert(vd[rx][cx] > 0);
			int dist = vd[rx][cx];
			while(mp(rx,cx) != mp(rs,cs))
			{
				ans.pb(vdad[rx][cx].fst);
				ii aux = vdad[rx][cx].snd;
				rx = aux.fst;
				cx = aux.snd;
			}
			reverse(ans.begin(), ans.end());
			assert(sz(ans) == dist);
			cout << ans << '\n';
		}
	}
	return 0;
}
