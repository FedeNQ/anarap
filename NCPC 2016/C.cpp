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

int n,dp[1<<4][4][52][13][3];
ii v[52];
char num[13] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char type[4] = {'s','h','d','c'};

int solve(int bm, int curt, int pos, int curn, int move)
{
	if(pos == n) return 0;
	if(dp[bm][curt][pos][curn][move] != -1) return dp[bm][curt][pos][curn][move];
	int ret = 1+solve(bm, curt, pos+1, curn, move);
	if((bm & (1<<v[pos].snd)) == 0)
	{
		if(v[pos].snd == curt)
		{
			//up
			if(v[pos].fst > curn && (move == 0 || move == 1))
			{
				ret = min(ret, solve(bm, curt, pos+1, v[pos].fst, 1));
			}
			//down
			if(v[pos].fst < curn && (move == 0 || move == 2))
			{
				ret = min(ret, solve(bm, curt, pos+1, v[pos].fst, 2));
			}
		}
		else ret = min(ret, solve(bm | (1<<curt), v[pos].snd, pos+1, v[pos].fst, 0));
	}
	return dp[bm][curt][pos][curn][move] = ret;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	forn(i,n)
	{
		string s;
		cin >> s;
		forn(j,13) if(s[0] == num[j]) v[i].fst = j;
		forn(j,4) if(s[1] == type[j]) v[i].snd = j;
	}
	memset(dp, -1, sizeof(dp));
	int ans = n;
	forn(i,n) ans = min(ans, i+solve(0, v[i].snd, i+1, v[i].fst, 0));
	cout << ans << '\n';
	return 0;
}
