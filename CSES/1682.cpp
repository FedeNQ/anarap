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

int n,m; 
#define MAXN 100010
vector<int> G[MAXN],gt[MAXN]; //Limpiar si se corre mas de una vez
//nodos 0...N-1 ; componentes 0...cantcomp-1
int comp[MAXN],N,cantcomp,used[MAXN];
stack<int> pila;
void add(int a, int b){ G[a].pb(b);gt[b].pb(a);}
void dfs1(int nodo)
{
	used[nodo]=1;
	forall(it,G[nodo]) if(!used[*it]) dfs1(*it);
	pila.push(nodo);
}
void dfs2(int nodo)
{
	used[nodo]=2;
	comp[nodo]=cantcomp-1;
	forall(it,gt[nodo]) if(used[*it]!=2) dfs2(*it);
}
void kosaraju()
{
	cantcomp=0;
	memset(used,0,sizeof(used));
	forn(i,N) if(!used[i]) dfs1(i);
	while(!pila.empty())
	{
		if(used[pila.top()]!=2)
		{
			cantcomp++;
			dfs2(pila.top());
		}
		pila.pop();
	}
}

bool bfs(int node, int goal){
	bool ret = 0;
	queue<int> q;
	q.push(node);
	used[node] = 1;
	while(!q.empty()){
		if(ret) break;
		int aux = q.front(); q.pop();
		forall(it, G[aux]){
			if(!used[*it]){
				used[*it] = 1;
				q.push(*it);
				if(*it == goal) ret = 1;
			}
		}
	}
	
	
	return ret;
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
	forn(i,m){
		int a,b; 
		cin >> a >> b;
		a--; b--;
		add(a,b);
	}
	kosaraju();
	if(cantcomp == 1) cout << "YES\n";
	else{
		cout << "NO\n";
		int sp = comp[0];
		int root = 0, goal = -1;
		forn(i,n){
			if(comp[i] != sp){
				goal = i;
				break;
			}
		}
		memset(used,0,sizeof(used));
		if(bfs(root,goal)) swap(root, goal);
		cout << root+1 << " " << goal+1 << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


