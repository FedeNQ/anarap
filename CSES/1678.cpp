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

#define MAXN 100010
int n,m;
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
int rta = 0;
int dad[MAXN];
void dfs(int node=0, int d = -1){
	dad[node] = d;
	used[node]=1;
	int root = -1, special = -1;
	//~ cout << "HAGO DFS " << node <<  endl;
	forall(it, G[node]){
		if(rta) break;
		if(comp[node] == comp[*it]){
			if(used[*it]){
				rta=1;
				special = node;
				root = *it;
				break;
			}
			else{
				dfs(*it, node);
				break;
			}
		}
	}
	
	if(special != -1){
		vector<int> ans;
		ans.pb(root);
		while(special != root){
			ans.pb(special);
			special = dad[special];
		}
		ans.pb(root);
		cout << sz(ans) << '\n';
		dforn(i,sz(ans)){
			cout << ans[i]+1;
			if(i) cout << " ";
		}
		cout << '\n';
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
	
	cin >> n >> m;
	N=n;
	forn(i,m){
		int a,b; cin >> a >> b; a--; b--;
		add(a,b);
	}
	kosaraju();
	vector<int> cc(cantcomp);
	forn(i,n) cc[comp[i]]++;
	int scomp = -1;
	//~ forn(i,n) cout << comp[i] << " ";
	//~ cout << '\n';
	forn(i,cantcomp) if(cc[i] > 1){scomp=i; break;}
	if(scomp==-1) cout << "IMPOSSIBLE\n";
	else{
		memset(used, 0, sizeof(used));
		int root = -1;
		forn(i,n) if(scomp == comp[i]) root = i;
		dfs(root);
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

