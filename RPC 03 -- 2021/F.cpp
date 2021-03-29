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
#define MAXN 1001
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


const ll INF  = 10000000000000;
int n,m,pp,c,N;
ll total;
vector<ii> G[MAXN];
int st[102];

vector<int> stations[MAXN];
#define add(a, b, w) G[a].pb(make_pair(w, b))

ll dist[MAXN];
vector<vector<ll>>dad;
vector<bool> visi;

void goback(int st, int ori){
	visi[st] = true;
	stations[st].pb(ori);
	forn(i,dad[st].size()) if(!visi[dad[st][i]]){
		goback(dad[st][i],ori);
	}
	return;
}

void dijkstra(int s){
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	forn(i,n) dist[i] = INF;
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		ii p = Q.top(); Q.pop();
		//~ if(p.snd == t) break;
		forall(it, G[p.snd])
			if(dist[p.snd]+it->first < dist[it->snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				dad[it->snd].clear();
				dad[it->snd].pb(p.snd);
				Q.push(make_pair(dist[it->snd], it->snd));
			}else if(dist[p.snd]+it->first == dist[it->snd]){
				dad[it->snd].pb(p.snd);
			}
	}
	return;
	//~ if(dist[t]<INF)
		//~ for(int i=t; i!=-1; i=dad[i])
			//~ printf("%d%c", i, (i==s?'\n':' '));
}

ll cost(int sta){
	ll auxt = total;
	ll resto = dist[sta];
	ll tam = sz(stations[sta]);
	auxt = auxt - resto * tam;
	auxt += tam * c;
	//~ cout << sta << " " << tam << " " << auxt << "\n";
	return auxt;
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
	
	cin >> n >> m >> pp >> c;
	N=n;
	dad.resize(1010);
	visi.resize(1010);
	forn(i,pp) cin >> st[i];
	forn(i,pp) st[i]--;
	forn(i,m){
		int a,b, w; cin >> a >> b >> w;
		a--; b--;
		G[a].pb({w,b});
		G[b].pb({w,a});
	}
	dijkstra(0);
	total = 0;
	forn(i,pp) total+=dist[st[i]];
	forn(i,pp){
		forn(j,1010) visi[j]=false;
		goback(st[i],st[i]);
	}
	ll ans = total;
	forr(i,1,n)ans = min(ans, cost(i));
	cout << ans << "\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

