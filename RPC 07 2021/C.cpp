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

#define MAXN 201

map<string, int> strId;
vector<int> g[MAXN];
int nxtId, t, used[MAXN], special;

int solve(int node, int len)
{
	used[node] = t;
	int ret = -1;
	forall(it,g[node])
	{
		if(*it == special) return len+1;
		if(used[*it]) continue;
		ret = max(ret, solve(*it, len+1));
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
	int n;
	cin >> n;
	forn(i,n)
	{
		string a,b,c;
		cin >> a >> b >> c;
		if(!strId.count(b)) strId[b] = nxtId++;
		if(!strId.count(c)) strId[c] = nxtId++;
		g[strId[b]].pb(strId[c]);
	}
	int ans = -1;
	forn(i,n)
	{
		t++;
		special = i;
		ans = max(ans, solve(i, 0));
	}
	if(ans == -1) cout << "No trades possible\n";
	else cout << ans << '\n';
	return 0;
}
