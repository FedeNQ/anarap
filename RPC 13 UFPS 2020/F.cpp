#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> g[MAXN];
unordered_map<int,ll> best[MAXN];
int n, vnodes[MAXN];

int dfs1(int node, int p)
{
	forall(it,g[node]) if(*it != p) vnodes[node] = max(vnodes[node], dfs1(*it, node));
	vnodes[node]++;
	return vnodes[node];
}

void dfs2(int node, int p, int prev)
{
	int vmax[3] = {prev,0,0};
	forall(it, g[node]) if(*it != p)
	{
		vmax[2] = max(vmax[2], vnodes[*it]);
		dforn(i,2) if(vmax[i+1] > vmax[i]) swap(vmax[i+1], vmax[i]);
	}
	if(p != node)
	{
		if(prev == vmax[0]) best[node][p] = vmax[1]+vmax[2];
		else if(prev == vmax[1]) best[node][p] = vmax[0]+vmax[2];
		else best[node][p] = vmax[0]+vmax[1];
	}
	forall(it, g[node]) if(*it != p)
	{
		int aux = vnodes[*it];
		if(aux == vmax[0]) best[node][*it] = vmax[1]+vmax[2];
		else if(aux == vmax[1]) best[node][*it] = vmax[0]+vmax[2];
		else best[node][*it] = vmax[0]+vmax[1];
		
		if(aux == vmax[0]) dfs2(*it, node, vmax[1]+1);
		else dfs2(*it, node, vmax[0]+1);
		
		best[node][p] = max(best[node][p], best[*it][node]);
	}
}

void dfs3(int node, int p, ll prev)
{
	ll max1 = prev, max2 = 0;
	forall(it, g[node]) if(*it != p)
	{
		max2 = max(max2, best[*it][node]);
		if(max2 > max1) swap(max1, max2);
	}
	forall(it, g[node]) if(*it != p)
	{
		if(best[*it][node] == max1)
		{
			best[node][*it] = max(best[node][*it], max2);
			dfs3(*it, node, max2);
		}
		else
		{
			best[node][*it] = max(best[node][*it], max1);
			dfs3(*it, node, max1);
		}
	}
	
}

ll solve()
{
	ll ret = 0;
	forn(i,n) forall(it,g[i])
	{
		ret = max(ret, best[i][*it]*best[*it][i]);
		//cout << i+1 << ' ' << *it+1 << ' ' << best[i][*it] << ": " << best[i][*it]*best[*it][i] << '\n';
	}
	return ret;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(0,0);
	dfs2(0,0,0);
	dfs3(0,0,0);
	cout << "Alice and Bob won " << solve() << " nlogonian dollars\n";
	return 0;
}
