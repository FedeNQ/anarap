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

bool used[7][7];
int dr[4] = {0,-1,0,1}, dc[4] = {-1,0,1,0}, dg[7][7];
int v[48];

inline bool good(int r, int c)
{
	return r >= 0 && c >= 0 && r < 7 && c < 7 && !used[r][c];
}

bool checkSplit(int r, int c)
{
	bool splitlr = true, splitud = true;
	forn(i,4)
	{
		int rr = r+dr[i], cc = c+dc[i];
		if(i%2 == 0)
		{
			if(good(rr,cc)) splitud = false; else splitlr = false;
		}
		else
		{
			if(good(rr,cc)) splitlr = false; else splitud = false;
		}
	}
	return splitlr || splitud;
}

int solve(int r, int c, int pos)
{
	//if(r == 6 && c == 0) cout << "asd " << pos << '\n';
	//if(pos > 47) cout << r << ' ' << c << ' ' << pos << '\n';
	if(pos == 48) return r == 6 && c == 0;
	if(checkSplit(r,c)) return 0;
	if(v[pos] != -1 && !good(r+dr[v[pos]], c+dc[v[pos]])) return 0;
	used[r][c] = true;
	int ret = 0;
	if(v[pos] != -1) ret = solve(r+dr[v[pos]], c+dc[v[pos]], pos+1);
	else 
	{
		bitset<4> only1;
		forn(i,4)
		{
			int rr = r+dr[i], cc = c+dc[i];
			if(good(rr,cc) && --dg[rr][cc] <= 1 && rr+cc < 12) only1.set(i);
		}
		int aux = only1.count();
		if(aux <= 1) forn(i,4)
		{
			int rr = r+dr[i], cc = c+dc[i];
			if(good(rr,cc) && (aux == 0 || only1[i])) ret += solve(rr, cc, pos+1);
		}
		forn(i,4)
		{
			int rr = r+dr[i], cc = c+dc[i];
			if(good(rr,cc)) dg[rr][cc]++;
		}
	}
	used[r][c] = false;
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
	char vc[4] = {'L','U','R','D'};
	string s;
	cin >> s;
	forn(i,sz(s))
	{
		if(s[i] == '?') v[i] = -1;
		else forn(j,4) if(s[i] == vc[j]) v[i] = j;
	}
	forn(i,7)forn(j,7) dg[i][j] = 4;
	//forn(i,7) dg[i][0] = dg[i][6] = dg[0][i] = dg[6][i] = 3;
	//dg[0][0] = dg[0][6] = dg[6][0] = dg[6][6] = 2;
	cout << solve(0,0,0) << '\n';
	return 0;
}
