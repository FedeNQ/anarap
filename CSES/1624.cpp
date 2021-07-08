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

char vv[8][8];
bitset<8> usedr,usedc;
set<int> sdu,sdd;

int solve(int r, int c, int qleft)
{
	if(c == 8) r++, c = 0;
	if(qleft == 0) return 1;
	if(r == 8) return 0;
	int ret = solve(r,c+1,qleft);
	if(vv[r][c] != '*' && !usedr[r] && !usedc[c] && !sdu.count(r+c) && !sdd.count(r-c))
	{
		usedr.set(r);
		usedc.set(c);
		sdu.insert(r+c);
		sdd.insert(r-c);
		ret += solve(r,c+1,qleft-1);
		usedr.reset(r);
		usedc.reset(c);
		sdu.erase(r+c);
		sdd.erase(r-c);
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
	forn(i,8)forn(j,8) cin >> vv[i][j];
	cout << solve(0,0,8) << '\n';
	return 0;
}
