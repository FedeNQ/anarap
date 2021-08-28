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

struct UnionFind{
	vector<int> f, setSize; //the array f contains the parent of each node
	int cantSets;
	void init(int n)
	{
		f.clear(); setSize.clear();
		cantSets = n;
		f.rsz(n, -1);
		setSize.rsz(n, 1);
	}
	int comp(int x) {return (f[x]==-1? x : f[x]=comp(f[x]));}//O(1)
	bool join(int i,int j) //devuelve true si ya estaban juntos
	{
		int a = comp(i), b = comp(j);
		if(a != b)
		{
			cantSets--;
			if(setSize[a] > setSize[b]) swap(a,b);
			setSize[b] += setSize[a];
			f[a] = b; //el grupo mas grande (b) ahora representa al mas chico (a)
		}
		return a == b;
	}
};


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<string> v(n);
	forn(i,n) cin >> v[i];
	int dr[4] = {0,0,1,-1}, dc[4] = {1,-1,0,0}, ans = 0;
	map<iii, int> mid;
	forn(r,n)forn(c,m)if(v[r][c] == '#')forn(k,4)
	{
		int rr = r+dr[k], cc = c+dc[k];
		if(rr < 0 || cc < 0 || rr >= n || cc >= m || v[rr][cc] == '.') mid[mp(mp(r,c), k)] = ans++;
	}
	UnionFind dsu;
	dsu.init(ans);
	forn(r,n)forn(c,m)if(v[r][c] == '#')forn(k,4)
	{
		int rr = r+dr[k], cc = c+dc[k];
		if(rr < 0 || cc < 0 || rr >= n || cc >= m || v[rr][cc] == '.')
		{
			int curid = mid[mp(mp(r,c), k)];
			if(dr[k] == 0)
			{
				if(mid.count(mp(mp(r-1,c),k))) dsu.join(curid, mid[mp(mp(r-1,c),k)]);
				if(mid.count(mp(mp(r+1,c),k))) dsu.join(curid, mid[mp(mp(r+1,c),k)]);
			}
			else
			{
				if(mid.count(mp(mp(r,c-1),k))) dsu.join(curid, mid[mp(mp(r,c-1),k)]);
				if(mid.count(mp(mp(r,c+1),k))) dsu.join(curid, mid[mp(mp(r,c+1),k)]);
			}
		}
	}
	cout << dsu.cantSets << '\n';
	return 0;
}
