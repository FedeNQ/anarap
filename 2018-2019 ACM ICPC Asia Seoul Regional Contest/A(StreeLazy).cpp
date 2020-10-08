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
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef int Elem, Alt;

#define operacion(x,y) max(x,y)
const Elem neutro=0; const Alt neutro2=0;
//Cambiar segun el N del problema
int auxans = 0;
struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];//las alteraciones pueden ser de tipo distinto a Elem
	Elem &operator[](int p) {return t[sz+p];}
	void init(int n){//O(nlgn)
		sz = 1 << (32-__builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
		forn(i, 2*sz) dirty[i] = neutro2;
	}
	void updall() {dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);} //O(n)
	void push(int n, int a, int b) {//propaga el dirty a sus hijos
		if(dirty[n] != neutro2) {// n = node of range [a,b)
			t[n] += dirty[n];//altera el nodo, modificar segun el problema
			auxans = max(auxans, t[n]);
			if(n<sz){
				dirty[2*n] += dirty[n];
				dirty[2*n+1] += dirty[n];
			}
			dirty[n] = neutro2;
		}
	}
	
	void alterar(int i, int j, int n, int a, int b) {//O(lgn)
		push(n, a, b);
		if(j<=a || i>=b) return;
		if(i<=a && b<=j){
			dirty[n]++; // modificar segun el problema
			push(n, a, b);
			return;
		}
		int c = (a+b)/2;
		alterar(i, j, 2*n, a, c), alterar(i, j, 2*n+1, c, b);
		t[n] = operacion(t[2*n], t[2*n+1]);//por esto es el push de arriba
	}
	void alterar(int i, int j){alterar(i,j,1,0,sz);}
};

int n;

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
	cin >> n;
	vector<ii> range(n);
	vector<int> open(n);
	set<int> coords;
	map<int, int> values;
	forn(i,n){
		cin >> range[i].snd >> range[i].snd >> range[i].fst >> range[i].fst;
		coords.insert(range[i].fst); coords.insert(range[i].snd);
	}
	int val = 1;
	forall(it, coords) {values[*it] = val; val++;}
	//~ forall(it, coords) cout << *it << " ";
	//~ cout << endl;
	multiset<ii> s;
	
	forn(i, n){
		range[i].fst = values[range[i].fst];
		range[i].snd = values[range[i].snd];
		open[i] = range[i].fst;
		s.insert(mp(range[i].fst, -1));
		s.insert(mp(range[i].snd, i));
	}
	RMQ st;
	st.init(val);
	int opened = 0, ans = 0;
	forall(it, s){
		if(it->snd == -1) opened++;
		else opened--, st.alterar(open[it->snd], it->fst+1);
		ans = max(ans, opened+auxans);
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 

