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
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;


struct UnionFind{
	vector<int> f, setSize; //the array f contains the parent of each node
	int cantSets;
	void init(int n)
	{
		f.clear(); setSize.clear();
		cantSets = n;
		f.rsz(n, -1);
		setSize.rsz(n, 1);
	}
	int comp(int x) {return (f[x]==-1? x : f[x]=comp(f[x]));}//O(1)
	bool join(int i,int j) //devuelve true si ya estaban juntos
	{
		int a = comp(i), b = comp(j);
		if(a != b)
		{
			cantSets--;
			if(setSize[a] > setSize[b]) swap(a,b);
			setSize[b] += setSize[a];
			f[a] = b; //el grupo mas grande (b) ahora representa al mas chico (a)
		}
		return a == b;
	}
}uf;

int n,m;

struct Ar{int a,b,w;};
bool operator<(const Ar& a, const Ar &b){return a.w<b.w;}
vector<Ar> E;

// Minimun Spanning Tree in O(e log e)
ll kruskal(){
    ll cost=0;
    sort(E.begin(), E.end());//ordenar aristas de menor a mayor
    n++;
    uf.init(n);
    forall(it, E){
        if(uf.comp(it->a)!=uf.comp(it->b)){//si no estan conectados
            uf.join(it->a, it->b);//conectar
            cost+=it->w;
        }
    }
    return cost;
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
	
	forn(i,m){
		int p; cin >> p;
		int cost; cin >> cost;
		p--;
		Ar edge;
		edge.a = p;
		edge.b = n;
		edge.w = cost;
		E.pb(edge);
	}
	forn(i,n){
		int cost; cin >> cost;
		Ar edge;
		edge.a=i;
		edge.b=(i+1)%n;
		edge.w=cost;
		E.pb(edge);
	}
	//~ forall(it,E){
		//~ cout << it->a << " " << it->b << " " << it->w << "\n";
	//~ }
	cout << kruskal() << "\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

