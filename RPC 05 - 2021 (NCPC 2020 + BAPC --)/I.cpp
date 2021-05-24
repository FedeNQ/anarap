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

#define MAXN 120

vector<int> g[MAXN];
int n,m;
int mt[MAXN], mt2[MAXN], ds[MAXN];
bool bfs(){
	queue<int> q;
	memset(ds,-1,sizeof(ds));
	forn(i,n) if(mt2[i]<0) ds[i]=0,q.push(i);
	bool r=false;
	while(!q.empty()){
			int x=q.front(); q.pop();
			for(int y:g[x]){
				if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q.push(mt[y]);
				else if(mt[y]<0) r=true;
			}
	}
	return r;
}

bool dfs(int x){
	for(int y:g[x]) if(mt[y]<0||ds[mt[y]] == ds[x]+1 && dfs(mt[y])){
		mt[y]=x;mt2[x]=y;
		return true;
		
	}
	ds[x]=1<<30;
	return false;
}

int MM(){
	int r=0;
	memset(mt,-1,sizeof(mt)); memset(mt2,-1,sizeof(mt2));
	while(bfs()){
		forn(i,n) if(mt2[i]<0) r+=dfs(i);
	}
	return r;
}

vector<ii> G[MAXN];
bitset<MAXN> edgeUsed;
int clr[MAXN];

void dfs1(int node, int curclr)
{
	clr[node] = curclr;
	forall(it, G[node]) if(clr[it->fst] == -1)
	{
		edgeUsed.set(it->snd);
		dfs1(it->fst, 1-curclr);
	}
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
	int nn, mm;
	cin >> nn >> mm;
	vector<ii> vedges(mm);
	forn(i,mm)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		G[a].pb(mp(b,i));
		G[b].pb(mp(a,i));
		vedges[i] = mp(a,b);
	}
	memset(clr, -1, sizeof(clr));
	dfs1(0,0);
	vector<int> enu;
	forn(i,mm) if(!edgeUsed[i] && clr[vedges[i].fst] == clr[vedges[i].snd])
	{
		enu.pb(i);
		//cout << vedges[i].fst << ' ' << vedges[i].snd << endl;
	}
	assert(sz(enu) <= mm-nn+1);
	n=m=nn;
	int ans = 1;
	forn(bm, (1<<sz(enu)))
	{
		bitset<MAXN> blocked;
		forn(i,sz(enu))
		{
			if(bm & (1<<i)) blocked.set(vedges[enu[i]].fst);
			else blocked.set(vedges[enu[i]].snd);
		}
		forall(it, vedges)
		{
			if(blocked[it->fst] || blocked[it->snd]) continue;
			//cout << "add " << it->fst << ' ' << it->snd << '\n';
			assert(clr[it->fst] != clr[it->snd]);
			if(clr[it->fst] == 0) g[it->fst].pb(it->snd);
			else g[it->snd].pb(it->fst);
		}
		//cout << blocked << ' ' << MM() << '\n';
		ans = max(ans, nn-MM()-(int)blocked.count());
		forn(i,nn) g[i].clear();
	}
	cout << ans << '\n';
	return 0;
}
