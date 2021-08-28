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

#define INF (7*6*5*4*3*2*20001)
int N;
#define MAX_V (7*6*5*4*3*2)
vector<ii> G[MAX_V];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))
ll dijkstra(int s, int t){//O(|E| log |V|)
	priority_queue<ii, vector<ii>, greater<ii> > Q;
	vector<ll> dist(N, INF);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		ii p = Q.top(); Q.pop();
		if(p.snd == t) break;
		forall(it, G[p.snd])
			if(dist[p.snd]+it->first < dist[it->snd]){
				dist[it->snd] = dist[p.snd] + it->fst;
				Q.push(make_pair(dist[it->snd], it->snd));	}
	}
	return dist[t];
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
	vector<int> ini(7), obj(7), v;
	forn(i,7) cin >> ini[i];
	forn(i,7) cin >> obj[i];
	v = ini;
	sort(v.begin(), v.end());
	map<vector<int>, int> mid;
	int curid = 0;
	do
	{
		mid[v] = curid++;
	}while(next_permutation(v.begin(), v.end()));
	assert(mid.count(ini));
	assert(mid.count(obj));
	int auxmat[3][3] = {{-1,0,1},
						{2,3,4},
						{5,6,-1}};
	int dr[2] = {0,1}, dc[2] = {1,0};
	vector<ii> vswaps;
	forn(r,3)forn(c,3)if(auxmat[r][c] != -1)forn(k,2)
	{
		int rr = r+dr[k], cc = c+dc[k];
		if(rr == 3 || cc == 3 || auxmat[rr][cc] == -1) continue;
		vswaps.pb(mp(auxmat[r][c], auxmat[rr][cc]));
	}
	//cout << "swaps:\n"; forall(it,vswaps) cout << it->fst << ' ' << it->snd << '\n'; cout << '\n';
	forall(it, mid)
	{
		int cur = it->snd;
		vector<int> auxv = it->fst;
		forall(ite, vswaps)
		{
			int i = ite->fst, j = ite->snd;
			if(auxv[i] == auxv[j]) continue;
			swap(auxv[i], auxv[j]);
			add(cur, mid[auxv], auxv[i]+auxv[j]);
			swap(auxv[i], auxv[j]);
		}
	}
	N = curid;
	cout << dijkstra(mid[ini], mid[obj]) << '\n';
	return 0;
}
