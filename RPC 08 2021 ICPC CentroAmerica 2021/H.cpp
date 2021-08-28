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
#define MAXN 500030

vector<int> g[MAXN];
int dist[MAXN];

void bfs(int node){
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	q.push(node);
	dist[node] = 0;
	while(!q.empty()){
		int aux= q.front();
		q.pop();
		forall(it, g[aux]){
			if(dist[*it] == -1){
				dist[*it] = dist[aux]+1;
				q.push(*it);
			}
		}
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
	
	int n; cin >> n;
	int m; cin >> m;
	int st; cin >> st;
	forn(i,m){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(st);
	vector<ii> todo;
	forn(i,n) if(i!=st){
		if(dist[i] == -1) dist[i] =0;
		 todo.pb(mp(dist[i], i));
	 }
	sort(todo.begin(), todo.end());
	if(!todo.empty()){
		int last = todo[0].fst;
		cout << last << ": " << todo[0].snd;
		forr(i,1,sz(todo)){
			if(last != todo[i].fst){
				cout << '\n';
				last=todo[i].fst;
				cout << last << ": " << todo[i].snd;
			}
			else cout << " " << todo[i].snd;
		}
		cout << '\n';
	}
	else cout << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


