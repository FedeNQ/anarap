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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXN 2503
int n,m, N;
//Mas lento que Dijsktra, pero maneja arcos con peso negativo

const ll INF = LLONG_MAX;

vector<pair<ll,int>> G[MAXN];//ady. list with pairs (weight, dst)
ll dist[MAXN];

void bford(int src){//O(VE)
	dist[src]=0;
	forn(i, N-1) forn(j, N) if(dist[j]!=INF) forall(it, G[j])
		dist[it->snd]=min(dist[it->snd], dist[j]+it->fst);
}

bool hasNegCycle(){
	forn(j, N) if(dist[j]!=INF) forall(it, G[j])
		if(dist[it->snd]>dist[j]+it->fst) return true;
	//inside if: all points reachable from it->snd will have -INF distance(do bfs)
	return false;
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
	N=n;
	forn(i,n) dist[i] = INF;
	dist[0] = 0;
	forn(i,m){
		int a,b; ll w;
		cin >> a >> b >> w;a--; b--;
		G[a].pb(mp(w,b));
		if(a==0) dist[b]=w;
	}
	bford(0);
	
	if(hasNegCycle()) cout << "YES\n";
	else cout << "NO\n";
	forn(i,n){
		cout << dist[i] << " ";
	}
	cout << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


