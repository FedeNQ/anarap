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
#define MAXN 100
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n,m;
vector<int> g[MAXN];
int dist[MAXN];
int dad[MAXN];
bool rta = 0;

void dfs(int node=0, int d = -1){
	dad[node] = d;
	int root = -1, special = -1;
	//~ cout << "HAGO DFS " << node <<  endl;
	forall(it, g[node]){
		if(rta) break;
		if(dist[*it] != -1 && abs(dist[*it]-dist[node]) >= 2){
			special = node;
			root = *it;
			rta=1;
			break;
		}
		else if(dist[*it] == -1){
			dist[*it] = dist[node]+1;
			dfs(*it, node);
		}
	}
	
	if(special != -1){
		vector<int> ans;
		ans.pb(root);
		while(special != root){
			ans.pb(special);
			special = dad[special];
		}
		ans.pb(root);
		cout << sz(ans) << '\n';
		dforn(i,sz(ans)){
			cout << ans[i]+1;
			if(i) cout << " ";
		}
		cout << '\n';
	}
	return;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	forn(i,m){
		int a,b; cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(dist, -1, sizeof(dist));
	forn(i,n){
		if(dist[i] == -1){
			dist[i] = 0;
			dfs(i);
		}
	}
	//~ forn(i,n) cout << dist[i] << " ";
	if(!rta) cout << "IMPOSSIBLE\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

