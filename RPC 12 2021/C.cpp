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

//Compilar: g++ --std=c++11
struct Hash{
	size_t operator()(const vector<int> &v)const
	{
		size_t s=0;
		for(auto &e : v) s^=hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
		return s;
	}
};

#define INF 1000

int n,m;
vector<unordered_map<vector<int>, int, Hash>> dp[10];
vector<string> vv;

int solve(int r, int c, vector<int> &v)
{
	if(c == m) r--, c = 0;
	if(r < 0) return 0;
	if(dp[c][r].count(v)) return dp[c][r][v];
	bool canput = c+1 < m && max(v[c], v[c+1]) == 1;
	bool covered = v[c] == 2;
	
	int vc = v[c];
	v[c] = max(0, v[c]-1);
	int ret = INF;
	if(covered) ret = solve(r,c+1,v);
	else
	{
		if(canput)
		{
			int x1 = v[c], x2 = v[c+1];
			v[c] = v[c+1] = 2;
			ret = 1+solve(r,c+2,v);
			v[c] = x1;
			v[c+1] = x2;
		}
		if(vv[r][c] == '.') ret = min(ret, solve(r,c+1,v));
	}
	v[c] = vc;
	
	return dp[c][r][v] = ret;
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
	cin >> n >> m;
	vv.rsz(n);
	forn(i,n) cin >> vv[i];
	forn(i,m) dp[i].rsz(n);
	vector<int> v(m,1);
	cout << solve(n-1,0,v) << '\n';
	return 0;
}
