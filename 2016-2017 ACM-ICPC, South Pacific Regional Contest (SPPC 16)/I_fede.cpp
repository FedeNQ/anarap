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
typedef int tipo;

#define operacion(x, y) max(x, y)

const tipo neutro=0;
struct RMQ {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion(t[p*2], t[p*2+1]);
		}
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
	int n; cin >> n;
	set<int> ordered;
	vector<ii> all;
	forn(i,n){
		int a,b; cin >> a >> b;
		all.pb(mp(b, b-a+1));
		ordered.insert(b);
	}
	map<int, int> compr;
	int cont = 0;
	forall(it, ordered){
		compr[*it] = cont;
		cont++;
	}
	forn(i, n) all[i].fst = compr[all[i].fst];
	RMQ stree;
	stree.init(n+2);
	//~ forall(it, all) cout << it->fst << " " << it->snd << '\n';
	forn(i,n){
		int aux = stree.get(0, all[i].fst);
		int aux2 = stree.get(all[i].fst, all[i].fst+1);
		//~ cout << aux << " " << aux2 << " " << all[i].snd << '\n';
		if(aux+all[i].snd > aux2) stree.set(all[i].fst, all[i].snd+aux);
		//~ cout << stree.get(0, all[i].fst) << " " << stree.get(0, all[i].fst+1)  << '\n';
	}
	cout << stree.get(0, n+2) << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

