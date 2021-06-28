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

int n,m;

inline int id(int r, int c) {
	return r*m+c;
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
	int k;
	cin >> n >> m >> k;
	vector<vector<int>> vv(n, vector<int>(m, -1));
	vector<int> vcpos(m, n-1);
	UnionFind diagd, diagu, ver, hor;
	diagd.init(n*m);
	diagu.init(n*m);
	ver.init(n*m);
	hor.init(n*m);
	forn(i,n*m)
	{
		int c;
		cin >> c;
		c--;
		int r = vcpos[c]--;
		vv[r][c] = i%2;
		//ver
		if(r+1 < n && vv[r+1][c] == vv[r][c]) ver.join(id(r,c), id(r+1,c));
		//hor
		if(c-1 >= 0 && vv[r][c-1] == vv[r][c]) hor.join(id(r,c), id(r,c-1));
		if(c+1 < m && vv[r][c+1] == vv[r][c]) hor.join(id(r,c), id(r,c+1));
		//diagd
		if(c-1 >= 0 && r-1 >= 0 && vv[r-1][c-1] == vv[r][c]) diagd.join(id(r,c), id(r-1,c-1));
		if(c+1 < m && r+1 < n && vv[r+1][c+1] == vv[r][c]) diagd.join(id(r,c), id(r+1,c+1));
		//diagu
		if(c-1 >= 0 && r+1 < n && vv[r+1][c-1] == vv[r][c]) diagu.join(id(r,c), id(r+1,c-1));
		if(c+1 < m && r-1 >= 0 && vv[r-1][c+1] == vv[r][c]) diagu.join(id(r,c), id(r-1,c+1));
		if(max({diagd.setSize[diagd.comp(id(r,c))], diagu.setSize[diagu.comp(id(r,c))], ver.setSize[ver.comp(id(r,c))], hor.setSize[hor.comp(id(r,c))]}) >= k)
		{
			cout << (i%2?'B':'A') << ' ' << i+1 << '\n';
			return 0;
		}
	}
	cout << "D\n";
	return 0;
}
