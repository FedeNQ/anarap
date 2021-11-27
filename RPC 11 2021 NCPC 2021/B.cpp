// ANARAP 💙💛💙
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

struct Hassh{
	size_t operator()(const ii &a)const
	{
		size_t s=hash<int>()(a.fst);
		return hash<int>()(a.snd)+0x9e3779b9+(s<<6)+(s>>2);
	}
	size_t operator()(const vector<int> &v)const
	{
		size_t s=0;
		for(auto &e : v) s^=hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
		return s;
	}
};
unordered_set<vector<int>, Hassh> s;
unordered_map<vector<int>, int, Hassh> m;//map<key, value, hasher>

int Hash(ii aux){
    if(aux.fst > aux.snd) swap(aux.fst, aux.snd);
    return aux.fst*7 + aux.snd;
}
unordered_map<int, int> val;
unordered_map<int, ii> reves;

int n, goal;
vector<int> v;
vector<ii> orden;
int bestAns = 9;
bool dbg=0;

int solve(int pos, int needed, int used, int left, int parity){
    if(needed <= 0 || needed-parity <=0){bestAns = min(used,bestAns); return 0;}
    if(pos >= 21 || used >= bestAns || ((left/2) < needed)) return 20;
    if(m.count(v)) return m[v];
    int actual = v[orden[pos].snd];
	v[orden[pos].snd] = v[orden[pos].snd]%2;
	int ret = 21;
	ret = min(ret, solve(pos+1, needed-(orden[pos].fst)*(actual/2), used, left-orden[pos].fst*actual, parity-(orden[pos].fst)*(actual/2)));
	v[orden[pos].snd] = actual;
	
    if(v[orden[pos].snd] > 0){
        v[orden[pos].snd]--;
        ii aux = reves[orden[pos].snd];
        //vertical cut
        forr(x,1,aux.fst){
            int v1 = val[Hash(mp(x, aux.snd))];
            int v2 = val[Hash(mp(aux.fst-x, aux.snd))];
            v[v1]++, v[v2]++;
            int newParity = parity;
            if(v[orden[pos].snd] % 2) newParity -= orden[pos].fst;
            if(v1 == v2) newParity += x*aux.snd;
            else{
                if(v[v1]%2 == 0) newParity += x*aux.snd;
                if(v[v2]%2 == 0) newParity += (aux.fst-x)*aux.snd;
            }
            ret=min(ret,solve(pos, needed, used+1, left, newParity)+1);
            v[v1]--, v[v2]--;
        }
        // horizontal cut
        forr(x,1,aux.snd){
            int v1 = val[Hash(mp(aux.fst, x))];
            int v2 = val[Hash(mp(aux.fst, aux.snd-x))];
            v[v1]++, v[v2]++;
            int newParity = parity;
            if(v[orden[pos].snd] % 2) newParity -= orden[pos].fst;
            if(v1 == v2) newParity += x*aux.fst;
            else{
                if(v[v1]%2 == 0) newParity += x*aux.fst;
                if(v[v2]%2 == 0) newParity += aux.fst*(aux.snd-x);
            }
            ret=min(ret,solve(pos, needed, used+1, left, newParity)+1);
            v[v1]--, v[v2]--;
        }
        v[orden[pos].snd]++;
   }
	return m[v] = ret;
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
    cin >> n >> goal;
    v.resize(21);
    int cont = 0;
    int left = 0;
    forr(i,1,7) forr(j,1,i+1){ 
        ii aux = mp(i,j);
        if(aux.fst > aux.snd) swap(aux.fst, aux.snd);
        val[Hash(aux)]=cont; 
        reves[cont] = aux;
        orden.pb(mp(i*j, cont));
        //~ cout << i << " " << j << " " << cont << '\n';
        cont++;
    }
    sort(orden.rbegin(), orden.rend());
    //~ cout << cont << '\n';
    forn(i,n){
        string p; cin >> p;
        ii aux = mp(p[0]-'0', p[2]-'0');
        //~ cout << aux.fst << " " << aux.snd << '\n';
        left += aux.fst * aux.snd;
        v[val[Hash(aux)]]++;
    }
    int par = 0;
    forn(pos,cont) par += (v[orden[pos].snd]/2) * orden[pos].fst;
    bestAns = min(bestAns, solve(0, goal, 0, left, par));
    cout << bestAns << '\n';
    
    #ifdef ANARAP
    t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
    #endif
    return 0;
}
