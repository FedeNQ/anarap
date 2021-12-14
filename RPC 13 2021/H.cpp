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
typedef pair<ii,ll> iii;

vector<iii> g[MAXN];
const int bucketSize = 317;
inline int getBucket(int x)
{
	return x/bucketSize;
}
deque<iii> endInBucket[bucketSize];
deque<iii> endInNode[MAXN];

#define INF 1000100100100100LL
int N;
void dijkstra(int s){//O(|E| log |V|)
	priority_queue<pair<ll,ii>, vector<pair<ll,ii>>, greater<pair<ll,ii>> > Q;
	vector<ll> dist(N, INF);
	Q.push(make_pair(0, mp(s,s+1))); dist[s] = 0;
	set<int> notUsed;
	vector<bool> used(N, false);
	forn(i,N) notUsed.insert(i);
	while(sz(Q)){
		int l = Q.top().snd.fst;
		int r = Q.top().snd.snd;
		ll d = Q.top().fst;
		Q.pop();
		set<int>::iterator ite = notUsed.lb(l);
		vector<int> toErase;
		while(ite != notUsed.end() && *ite < r)
		{
			int node = *ite;
			dist[node] = d;
			used[node] = true;
			toErase.pb(node);
			forall(it,g[node]) Q.push(mp(d+it->snd, it->fst));
			int aux = node;
			while(aux < N && getBucket(aux) == getBucket(node))
			{
				while(!endInNode[aux].empty() && endInNode[aux].front().fst.fst <= node)
				{
					if(!used[endInNode[aux].front().fst.snd]) Q.push(mp(d+endInNode[aux].front().snd, mp(endInNode[aux].front().fst.snd, endInNode[aux].front().fst.snd+1)));
					endInNode[aux].pop_front();
				}
				aux++;
			}
			forr(i,getBucket(node)+1,bucketSize)
			{
				while(!endInBucket[i].empty() && endInBucket[i].front().fst.fst <= node)
				{
					if(!used[endInBucket[i].front().fst.snd]) Q.push(mp(d+endInBucket[i].front().snd, mp(endInBucket[i].front().fst.snd, endInBucket[i].front().fst.snd+1)));
					endInBucket[i].pop_front();
				}
			}
			ite++;
		}
		forall(it,toErase) notUsed.erase(*it);
	}
	forn(i,N)
	{
		if(i) cout << ' ';
		if(dist[i] == INF) cout << "-1";
		else cout << dist[i];
	}
	cout << '\n';
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
	int n,m,start;
	cin >> n >> m >> start;
	start--;
	N = n;
	forn(_,m)
	{
		string s;
		cin >> s;
		if(s == "basic")
		{
			int a,b,w;
			cin >> a >> b >> w;
			a--;b--;
			g[a].pb(mp(mp(b,b+1),w));
		}
		else if(s == "fixed-origin")
		{
			int x,l,r,w;
			cin >> x >> l >> r >> w;
			x--;l--;r--;
			g[x].pb(mp(mp(l,r+1),w));
		}
		else
		{
			assert(s == "fixed-destination");
			int x,l,r,w;
			cin >> x >> l >> r >> w;
			x--;l--;r--;
			endInNode[r].pb(mp(mp(l,x),w));
			endInBucket[getBucket(r)].pb(mp(mp(l,x),w));
		}
	}
	forn(i,MAXN) sort(endInNode[i].begin(), endInNode[i].end());
	forn(i,bucketSize) sort(endInBucket[i].begin(), endInBucket[i].end());
	dijkstra(start);
	return 0;
}
