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
#define MAXN 500
#else
#define MAXN 5001
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define INF 1000100100100100100

ll nways[MAXN][MAXN];
int n;
vector<int> g[MAXN];

int dfs(int node, int p)
{
	int ret = 1, maxpos = 1;
	nways[node][1] = 1;
	ll auxways[MAXN];
	forall(it,g[node]) if(*it != p)
	{
		int aux = dfs(*it, node);
		ret += aux;
		forn(i,min(MAXN, maxpos+aux+2)) auxways[i] = 0;
		forn(i,maxpos+1) if(nways[node][i]) forn(j,aux+1) if(nways[*it][j])
		{
			assert(i+j < MAXN);
			auxways[i+j] = min((__int128)INF, auxways[i+j]+nways[node][i]*(__int128)nways[*it][j]);
			maxpos = max(maxpos, i+j);
		}
		forn(i,maxpos+1) nways[node][i] = auxways[i];
	}
	nways[node][0] = 1;
	/*cout << node << ": ";
	forn(i,6) cout << nways[node][i] << ' ';
	cout << '\n';*/
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
	ll k;
	cin >> n >> k;
	forn(i,n-1)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,0);
	forr(i,1,n+1)
	{
		forn(j,n)
		{
			k -= nways[j][i];
			if(k <= 0)
			{
				cout << i << '\n';
				return 0;
			}
		}
	}
	cout << "-1\n";
	return 0;
}
