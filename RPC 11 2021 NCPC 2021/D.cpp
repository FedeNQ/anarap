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

#define MAXN 1003
int n,m,st;
char mx[MAXN][MAXN];
int dist[MAXN*MAXN], dist2[MAXN*MAXN];
string p;
void bfs(int node){
	memset(dist,-1,sizeof(dist));
	queue<int> q; q.push(node);
	dist[node] = 0;
	while(!q.empty()){
		int aux = q.front();
		q.pop();
		int x = aux/m, y=aux%m;
		int val = -1;
		if(x-1 >= 0){
			val = (x-1)*m+y;
			if(mx[x-1][y] == '.' && dist[val] == -1) dist[val] = dist[aux]+1, q.push(val);
		}
		if(x+1 < n){
			val = (x+1)*m+y;
			if(mx[x+1][y] == '.' && dist[val] == -1) dist[val] = dist[aux]+1, q.push(val);
		}
		if(y-1 >= 0){
			val = x*m+y-1;
			if(mx[x][y-1] == '.' && dist[val] == -1) dist[val] = dist[aux]+1, q.push(val);	
		}
		if(y+1 < m){
			val = x*m+y+1;
			if(mx[x][y+1] == '.' && dist[val] == -1) dist[val] = dist[aux]+1, q.push(val);	
		}
	}
	return;
}

void bfs2(int node){
	memset(dist2,-1,sizeof(dist2));
	queue<int> q; q.push(node);
	dist2[node] = 0;
	while(!q.empty()){
		int aux = q.front();
		q.pop();
		if(dist[aux] >= sz(p)) continue;
		int x = aux/m, y=aux%m;
		int val = -1;
		if(x-1 >= 0){
			val = (x-1)*m+y;
			if(dist[aux]+1 == dist[val]){
				if(mx[x-1][y] == '.' && dist2[val] == -1 && p[dist2[aux]] != 'N') dist2[val] = dist2[aux]+1, q.push(val);
			}
		}
		if(x+1 < n){
			val = (x+1)*m+y;
			if(dist[aux]+1 == dist[val]){
				if(mx[x+1][y] == '.' && dist2[val] == -1 && p[dist2[aux]] != 'S') dist2[val] = dist2[aux]+1, q.push(val);
			}
		}
		if(y-1 >= 0){
			val = x*m+y-1;
			if(dist[aux]+1 == dist[val]){
				if(mx[x][y-1] == '.' && dist2[val] == -1 && p[dist2[aux]] != 'W') dist2[val] = dist2[aux]+1, q.push(val);
			}
		}
		if(y+1 < m){
			val = x*m+y+1;
			if(dist[aux]+1 == dist[val]){
				if(mx[x][y+1] == '.' && dist2[val] == -1 && p[dist2[aux]] != 'E') dist2[val] = dist2[aux]+1, q.push(val);
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
	
	cin >> m >> n;
	forn(i,n){
		cin >> p;
		forn(j,m){
			mx[i][j] = p[j];
			if(p[j] == 'S') st = i*m+j;
		}
	}
	cin >> p;
	bfs(st);
	bfs2(st);
	forn(i,n){
		forn(j,m){
			if(dist2[i*m+j] == sz(p)) cout << '!';
			else cout << mx[i][j];
		}
		cout << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


