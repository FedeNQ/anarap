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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

set<int> g[MAXN];
int vclr[MAXN];

void dfs(int node, int clr)
{
	vclr[node] = clr;
	forall(it,g[node])
	{
		if(vclr[*it] == -1) dfs(*it,1-clr);
		else assert(vclr[*it] == 1-clr);
	}
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
	int n,m;
	cin >> n >> m;
	if(n%2)
	{
		cout << n/2 << '\n';
		return 0;
	}
	forn(_,m)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].insert(b);
		g[b].insert(a);
	}
	memset(vclr,-1,sizeof(vclr));
	forn(i,n) if(vclr[i] == -1) dfs(i,0);
	int cnt[2] = {0,0};
	forn(i,n) cnt[vclr[i]]++;
	assert(cnt[0]%2 == cnt[1]%2);
	if(cnt[0]%2 == 0)
	{
		cout << n/2 << '\n';
		return 0;
	}
	bool allbad = true;
	forn(i,n) if(sz(g[i]) < cnt[1-vclr[i]]) allbad = false;
	cout << n/2-allbad << '\n';
	return 0;
}
