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

#define MAXN 301

vector<int> g[MAXN];
int n;
ll dg[MAXN], used[MAXN], d[MAXN][MAXN], d2[MAXN][MAXN], flag;
unordered_map<int,ll> dp[MAXN];
bool inCycle[MAXN];

bool dfs(int node)
{
    if(used[node] == flag+1) return true;
    if(used[node] == flag) return false;
    used[node] = flag+1;
    forall(it,g[node]) if(dfs(*it)) return true;
    used[node] = flag;
    return false;
}

#define INF 1000100100100100LL

vector<int> gorig[MAXN];

bitset<MAXN> reachable;

void dfs2(int node, int bad, bool fst)
{
	reachable.set(node);
	forall(it,gorig[node]) if(!reachable[*it] && !(*it == bad && fst)) dfs2(*it, bad, false);
}

ll solve(int node, int bad)
{
    if(bad == -1 && inCycle[node]) return INF;
    if(dg[node] == 1) return 0;
    if(dp[node].count(bad)) return dp[node][bad];
    ll ret = 0;
    if(bad != -1)
    {
		reachable.reset();
		dfs2(node, bad, true);
		ll maxd = 0;
        forn(j,n) if(reachable[j]) maxd = max(maxd, d[node][j]);
        assert(maxd > 0);
        forn(j,n) if(reachable[j] && d[node][j] == maxd) ret = max(ret, d[node][j]+solve(j, -1));
	}
    else forall(it,g[node]) ret = max(ret, d[node][*it]+solve(*it, -1));
    return dp[node][bad] = min(ret, INF);
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
    int m,p,t;
    cin >> n >> m >> p >> t;
    p--;t--;
    forn(i,n)forn(j,n) d[i][j] = d2[i][j] = INF*(i!=j);
    forn(_,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = d[b][a] = d2[a][b] = d2[b][a] = c;
        gorig[a].pb(b);
        gorig[b].pb(a);
        dg[a]++; dg[b]++;
    }
    forn(k,n)forn(i,n)forn(j,n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    forn(k,n)if(k!=t)forn(i,n)forn(j,n) d2[i][j] = min(d2[i][j], d2[i][k]+d2[k][j]);
    forn(i,n) if(dg[i] > 1)
    {
        ll maxd = 0;
        forn(j,n) maxd = max(maxd, d[i][j]);
        assert(maxd > 0);
        forn(j,n) if(d[i][j] == maxd) g[i].pb(j);
    }
    forn(i,n) if(dg[i] > 1)
    {
        flag += 2;
        inCycle[i] = dfs(i);
    }
    //cout << "special: "; forn(i,n) if(inCycle) cout << i+1 << ' '; cout << '\n';
    ll ans = INF;
    forall(it,gorig[t])
    {
		ans = min(ans, d2[p][*it]+d[*it][t]+solve(t,*it));
		//cout << "try " << *it+1 << ' ' << d[p][*it]+d[*it][t]+solve(t,*it) << '\n';
	}
    if(ans == INF) cout << "impossible\n";
    else cout << ans << '\n';
    return 0;
}
