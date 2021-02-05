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
#define MAXN 100
#else
#define MAXN 1000
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string curans;
int maxd, curd, n, m, dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0}, used[MAXN][MAXN], d[MAXN][MAXN], curt, rr, cc;
char dd[4] = {'D','L','R','U'};

void dfs(int r, int c)
{
	used[r][c] = curt;
	if(maxd == curd)
	{
		if(maxd > 0) cout << curans << '\n';
		return;
	}
	forn(i,4)
	{
		rr = r+dr[i];
		cc = c+dc[i];
		if(rr < 0 || cc < 0 || rr >= n || cc >= m || used[rr][cc] == curt || d[rr][cc] != d[r][c]+1) continue;
		curd++;
		curans.pb(dd[i]);
		dfs(rr, cc);
		curans.pop_back();
		curd--;
	}
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
	char v[MAXN][MAXN];
	int t,R,C,r,c;
	cin >> t;
	forn(T,t)
	{
		curt = T+1;
		cin >> m >> n;
		forn(i,n)forn(j,m) d[i][j] = -1;
		forn(i,n)forn(j,m)
		{
			cin >> v[i][j];
			if(v[i][j] == '@') r = i, c = j;
		}
		cout << "Case " << T+1 << ":\n";
		queue<ii> q;
		d[r][c] = 0;
		q.push(mp(r,c));
		maxd = 0;
		R = r; C = c;
		while(!q.empty())
		{
			r = q.front().fst, c = q.front().snd;
			maxd = max(maxd, d[r][c]);
			q.pop();
			forn(i,4)
			{
				rr = r+dr[i];
				cc = c+dc[i];
				if(rr < 0 || cc < 0 || rr >= n || cc >= m || v[rr][cc] != '.') continue;
				if(d[rr][cc] == -1)
				{
					d[rr][cc] = d[r][c] + 1;
					q.push(mp(rr,cc));
				}
			}
		}
		/*cout << "maxd=" << maxd << '\n';
		forn(i,n)forn(j,m) if(d[i][j] == maxd) cout << "good " << i << ' ' << j << '\n';
		forn(i,n)
		{
			forn(j,m) if(d[i][j] == -1) cout << '#'; else cout << d[i][j];
			cout << '\n';
		}*/
		int ans = 0;
		forn(i,n)forn(j,m) if(d[i][j] == maxd) ans++;
		cout << ans << ' ' << maxd << '\n';
		dfs(R,C);
	}
	return 0;
}
