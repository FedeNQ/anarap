#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct UnionFind{
	vector<int> f;
	int cantSets;
	void init(int n)
	{
		f.clear();
		cantSets = n;
		f.rsz(n, -1);
	}
	int comp(int x) {return (f[x]==-1? x : f[x]=comp(f[x]));}
	bool join(int i, int j)
	{
		int a = comp(i), b = comp(j);
		if(a != b)
		{
			cantSets--;
			f[a] = b;
		}
		return a == b;
	}
};

struct Query {
	int r1,r2,c1,c2;
};

int n,m;

inline int id(int r, int c)
{
	return r*m+c;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q,dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
	cin >> m >> n >> q;
	vector<vector<int>> cnt(n, vector<int>(m, 0));
	vector<Query> vq(q);
	forn(i,q)
	{
		int r1,r2,c1,c2;
		cin >> c1 >> r1 >> c2 >> r2;
		r1--;r2--;c1--;c2--;
		forr(r,r1,r2+1)forr(c,c1,c2+1) cnt[r][c]++;
		vq[i] = {r1,r2,c1,c2};
	}
	int black = 0;
	UnionFind dsu;
	dsu.init(n*m);
	forn(r,n)forn(c,m)
	{
		if(cnt[r][c]) black++;
		else forn(k,4)
		{
			int rr = r+dr[k], cc = c+dc[k];
			if(rr < 0 || rr >= n || cc < 0 || cc >= m || cnt[rr][cc]) continue;
			dsu.join(id(r,c), id(rr,cc));
		}
	}
	vector<int> ans(q);
	dforn(i,q)
	{
		assert(dsu.cantSets >= black);
		ans[i] = dsu.cantSets - black;
		forr(r, vq[i].r1, vq[i].r2+1)forr(c, vq[i].c1, vq[i].c2+1)
		{
			cnt[r][c]--;
			if(cnt[r][c] == 0)
			{
				black--;
				forn(k,4)
				{
					int rr = r+dr[k], cc = c+dc[k];
					if(rr < 0 || rr >= n || cc < 0 || cc >= m || cnt[rr][cc]) continue;
					dsu.join(id(r,c), id(rr,cc));
				}
			}
		}
	}
	forn(i,q) cout << ans[i] << '\n';
	return 0;
}
