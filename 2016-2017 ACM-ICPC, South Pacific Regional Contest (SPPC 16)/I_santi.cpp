
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#define MAXN 1000
#else
#define MAXN 100010
#endif

#define INF 

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

typedef ll tipo;

#define operacion(x,y) max(x,y)

const tipo neutro = 0;
struct RMQ{
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n){
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro;
		
	}
	void updall() { dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);}
	tipo get(int i, int j){return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b){
		if(j<=a||i>=b) return neutro;
		if(i<=a&&b<=j) return t[n];
		int c=(a+b)/2;
		return operacion(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
		
	}
	void set(int p, tipo val){
		p+=sz;
		while(p>0 && t[p]!=val){
			t[p]=val;
			p/=2;
			val = operacion(t[p*2], t[p*2+1]);
		}
	}
};

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n;
	 cin >> n;
	 vector<ii> v(n);
	 set<int> s;
	 map<int,int> comp;
	 forn(i,n)
	 {
		 cin >> v[i].fst >> v[i].snd;
		 s.insert(v[i].snd);
	 }
	 int aux = 0;
	 forall(it, s) comp[*it] = aux++;
	 RMQ st;
	 st.init(aux);
	 ll ans = 0;
	 forn(i,n)
	 {
		 ll best = st.get(0, comp[v[i].snd]) + v[i].snd - v[i].fst + 1;
		 ans = max(ans, best);
		 if(best > st[comp[v[i].snd]]) st.set(comp[v[i].snd], best);
	 }
	 cout << ans << '\n';
	 return 0;
	
}
