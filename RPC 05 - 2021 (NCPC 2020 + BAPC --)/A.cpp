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

int vp[MAXN], v[MAXN], vlvl[MAXN];
vector<int> g[MAXN];
bitset<MAXN> isLeaf;

void dfs(int node, int lvl)
{
	vlvl[node] = lvl;
	forall(it, g[node]) dfs(*it, lvl+1);
}

bool cmp(int a, int b)
{
	if(vlvl[a] != vlvl[b]) return vlvl[a] > vlvl[b];
	if(isLeaf[a] != isLeaf[b]) return !isLeaf[a];
	return a < b;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	forn(i,k) cin >> v[i];
	sort(v, v+k);
	isLeaf.set();
	forr(i,1,n)
	{
		cin >> vp[i];
		isLeaf.reset(vp[i]);
		g[vp[i]].pb(i);
	}
	dfs(0,0);
	vector<int> vids(n);
	forn(i,n) vids[i] = i;
	sort(vids.begin(), vids.end(), cmp);
	assert(vids.back() == 0);
	bitset<MAXN> used;
	vector<int> games(n,-1);
	multiset<int> sgames;
	forn(i,n-1)
	{
		int x = vids[i];
		if(isLeaf[x])
		{
			games[x] = 1;
			sgames.insert(1);
		}
		else
		{
			int aux = 0;
			forall(it,g[x])
			{
				assert(games[*it] != -1);
				aux = max(aux, games[*it]);
			}
			assert(aux > 0);
			sgames.erase(sgames.find(aux));
			sgames.insert(aux+1);
			games[x] = aux+1;
		}
	}
	assert(sz(sgames) == k);
	int pos = 0;
	ll ans = 0;
	forall(it,sgames) ans += *it*(ll)v[pos++];
	cout << ans << '\n';
	return 0;
}
