
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

struct Activity {
	int h,d,t,id;
};

bool cmp(Activity &a, Activity &b)
{
	if(a.t != b.t) return a.t < b.t;
	return a.id < b.id;
}

vector<Activity> v;
vector<int> dp;

int nxtPos(int pos)
{
	int goodFrom = v[pos].t + v[pos].d;
	int L = pos+1, R = sz(v), M;
	while(L < R)
	{
		M = (L+R)/2;
		if(v[M].t >= goodFrom) R = M;
		else L = M+1;
	}
	return L;
}

int solve(int pos)
{
	if(pos == sz(v)) return 0;
	if(dp[pos] != -1) return dp[pos];
	return dp[pos] = max(solve(pos+1), v[pos].h + solve(nxtPos(pos)));
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
	int n,T;
	cin >> n >> T;
	forn(_,n)
	{
		int h,d,k;
		cin >> h >> d >> k;
		forn(_,k)
		{
			int t;
			cin >> t;
			v.pb({h,d,t,sz(v)});
		}
	}
	sort(v.begin(), v.end(),cmp);
	dp.rsz(sz(v),-1);
	cout << solve(0) << '\n';
	return 0;
}
