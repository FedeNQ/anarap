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
#define MAXN 1003
char mx[MAXN][MAXN];
int dist[MAXN*MAXN];
vector<int> g[MAXN*MAXN];
void bfs(int node){
	queue<int> q;
	q.push(node);
	dist[node] = 0;
	while(!q.empty()){
		int aux = q.front();
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

int n,m;
bool ok(int a, int b){
	if(a < 0 || b<0 || a>=n || b>=m) return 0;
	if(mx[a][b] == '.' || mx[a][b] == 'E') return 1;
	return 0;
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
	
	memset(dist,-1,sizeof(dist));
	cin >> n >> m;
	int st = -1;
	
	forn(i,n){
		string p; cin >> p;
		forn(j,m){
			mx[i][j] = p[j];
			if(mx[i][j] == 'E') st = i*m+j;
		}
	}
	
	forn(i,n){
		forn(j,m){
			if(!(mx[i][j] == '.' || mx[i][j] == 'E'))  continue;
			int now = i*m + j;
			if(i+1 < n && (mx[i+1][j] == '.' || mx[i+1][j] == 'E')){
				int nxt = (i+1)*m+j;
				g[nxt].pb(now);
				g[now].pb(nxt);
			}
			if(j+1 < m && (mx[i][j+1] == 'E' || mx[i][j+1] == '.')){
				int nxt = i*m+j+1;
				g[nxt].pb(now);
				g[now].pb(nxt);
			}
		}
	}
	bfs(st);
	int q; cin >> q;
	//~ forn(i,n*m) cout << dist[i] << " ";
	//~ cout << endl;
	forn(i,q){
		int a,b; cin >> a >> b;
		a--; b--;
		if(mx[a][b] == 'X') cout << "X\n";
		else if(mx[a][b] == 'E') cout << "E\n";
		else if(mx[a][b] == '#') cout << "W\n";
		else{
			if(dist[a*m+b] == -1) cout << "?\n";
			else{
				int dmin = m*n + 5;
				if(ok(a-1,b)) dmin = min(dist[(a-1)*m+b], dmin);
				if(ok(a+1,b)) dmin = min(dist[(a+1)*m+b], dmin);
				if(ok(a,b+1)) dmin = min(dist[a*m+b+1], dmin);
				if(ok(a,b-1)) dmin = min(dist[a*m+b-1], dmin);
				
				if(ok(a,b-1) && dist[a*m+b-1] == dmin) cout << "L\n";
				else if(ok(a+1,b) && dmin == dist[(a+1)*m+b]) cout << "D\n";
				else if(ok(a,b+1) && dist[a*m+b+1] == dmin) cout << "R\n";
				else cout << "U\n";
				//~ cout << dmin << endl;
			}
		}
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


