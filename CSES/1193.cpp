
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
#define MAXN 1003
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

char mx[MAXN][MAXN];
int dist[MAXN*MAXN];
int dad[MAXN*MAXN];
vector<int> g[MAXN*MAXN];

void add(int a, int b){
	g[a].pb(b);
	g[b].pb(a);
	return;
}


void bfs(int node){
	queue<int> q;
	q.push(node);
	dist[node] = 0;
	while(!q.empty()){
		int aux = q.front();
		q.pop();
		forall(it, g[aux]){
			if(dist[*it] == -1){
				q.push(*it);
				dist[*it] = dist[aux]+1;
				dad[*it] = aux;
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
	
	int n,m; cin >> n >> m;
	forn(i,n){
		string p; cin >> p;
		forn(j,m) mx[i][j] = p[j];
	}
	int st=-1, fn=-1;
	forn(i,n){
		forn(j,m){
			if(mx[i][j] == 'A') st = i*m+j;
			if(mx[i][j] == 'B') fn = i*m+j;
			if(mx[i][j] != '#'){
				if(i+1 < n && mx[i+1][j] != '#') add(i*m+j, (i+1)*m+j);
				if(j+1 < m && mx[i][j+1] != '#') add(i*m+j, i*m+j+1);
			}
		}
	}
	memset(dist,-1,sizeof(dist));
	bfs(st);
	vector<char> rta;
	if(dist[fn] == -1) cout << "NO\n";
	else {
		cout << "YES\n";
		cout << dist[fn] << '\n';
		int act = dist[fn];
		int nd = fn;
		while(act != 0){
					int x = nd/m, y=nd%m;
					int xx = dad[nd]/m, yy = dad[nd]%m;
					if(y < yy) rta.pb('L');
					else if(y > yy) rta.pb('R');
					else if(x < xx) rta.pb('U');
					else rta.pb('D');
					nd = dad[nd];
					act--;
		}
		dforn(i,sz(rta)) cout << rta[i];
		cout << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


