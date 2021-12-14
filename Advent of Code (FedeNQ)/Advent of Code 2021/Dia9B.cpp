// ANARAP 💙💛💙
// 💧🙌🏻
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

vector<vector<int>> mx;
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

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
	int tam(int x){ return setSize[x];}
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
};

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
	string p;
	while(cin >> p){
		mx.pb(vector<int>());
		mx.back().resize(sz(p));
		forn(i,sz(p)) mx.back()[i] = p[i]-'0';
	}
	int n = sz(mx);
	int m = sz(mx[0]);
	UnionFind uf;
	uf.init(n*m);
	ll ans = 1;
	forn(i,n){
		forn(j,m){
			//~ bool valid = 1;
			if(mx[i][j] == 9) continue;
			forn(v, 4){
				if(i+dx[v] >= 0 && i+dx[v] < n && j+dy[v] >= 0 && j+dy[v] < m){
					if(mx[i+dx[v]][j+dy[v]] == 9) continue;
					uf.join(i*m+j, (i+dx[v])*m + j + dy[v]);
				}
			}
			//~ if(valid) ans += mx[i][j]+1;
		}
		//~ cout << '\n';
	}
	set<ii> todos;
	forn(i,n) forn(j,m){
		if(mx[i][j] == 9) continue;
		else todos.insert(mp(uf.tam(uf.comp(i*m+j)), uf.comp(i*m+j)));
	}
	int cont = 0;
	vector<ii> todos2;
	forall(it, todos) todos2.pb(*it);
	sort(todos2.rbegin(), todos2.rend());
	forall(it, todos2){
		ans *= it->fst;
		cont++;
		if(cont == 3) break;
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



