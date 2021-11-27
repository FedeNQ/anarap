// ANARAP 💙💛💙
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

#define INF 1e9
int N, n, m;
ll c;
#define MAX_V 100021
vector<ii> G[MAX_V];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))

ll calc(ll now, ll per){
	return now-(now*per+99)/(100LL);
}

ll dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<ii, vector<ii>, less<ii> > Q;
	vector<ll> dist(N, 0LL); vector<int> dad(N, -1);
	Q.push(make_pair(c, s)); dist[s] = c;
	while(sz(Q)){
		ii p = Q.top(); Q.pop();
		
		if(t == p.snd) break;
		if(dist[p.snd] > p.fst) continue;
		forall(it, G[p.snd]){
			//~ cout << "calculo " << p.fst << " " << p.snd << " " << it->first << " " << it->snd << endl;
			//~ cout << "meda " << calc(dist[p.snd], it->fst) << '\n';
			if(calc(dist[p.snd],it->first) > dist[it->snd]){
				dist[it->snd] = calc(dist[p.snd],it->fst);
				dad[it->snd] = p.snd;
				Q.push(make_pair(dist[it->snd], it->snd));	
			}
		}
		//~ cout << " e " << endl;
	}
	return dist[t];
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
	int st, goal; cin >> st >> goal >> c;
	st--; goal--;
	forn(i,m){ 
		int a,b; ll w; 
		cin >> a >> b >> w; 
		a--; b--; 
		add(a,b,w), add(b,a,w);
	}
	cout << dijkstra(st, goal) << '\n';

	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


