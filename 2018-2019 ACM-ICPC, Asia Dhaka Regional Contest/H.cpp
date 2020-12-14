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
#define MOD 78294349
#define MAXN 203
int mx[MAXN][MAXN], now[MAXN][MAXN], nxt[MAXN][MAXN];


vector<int> g[MAXN*MAXN];

#define MAXP 100000 //no necesariamente primo
int criba[MAXP+1];
void crearCriba()
{
	int w[] = {4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3;
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7,cur=0;p*p<=MAXP;p+=w[cur++&7]) if (!criba[p])
	for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}
vector<int> primos;
void buscarPrimos()
{
	crearCriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
}

//factoriza bien numeros hasta MAXP^2
void fact(ll n,map<ll,int> &f) //O (cant primos)
{ //llamar a buscarPrimos antes
	forall(p, primos){
		while(!(n %*p))
		{
			f[*p]++;//divisor found
			n/=*p;
		}
	}
	if(n>1) f[n]++;
}
int auxx;
bool used[MAXN*MAXN];
void dfs(int node){
	used[node] = 1;
	auxx++;
	forall(it, g[node]){
		if(!used[*it]) dfs(*it);
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
	int t;
	cin >> t;
	crearCriba();
	buscarPrimos();
	forn(T,t){
		memset(mx, 0, sizeof(mx));
		memset(nxt, 0, sizeof(nxt));
		memset(now, 0 , sizeof(now));
		int n,m; 
		cin >>n >>m;
		int cont=1;
		forn(i, n){
			string p; cin >> p;
			forn(j, m){
				if(p[j] == '#'){mx[i][j] = cont; cont++;}
				else mx[i][j] = 0;
			}
		}
		forn(i,n) forn(j,m) now[i][j] = mx[i][j];
		forn(j,m){
			int st = 0;
			while(st < n && now[st][j] == 0) st++;
			int aux = 0;
			while(st < n){
				nxt[aux][j] = now[st][j];
				aux++;
				st++;
			}
		}
		forn(i,n) forn(j,m) now[i][j] = nxt[i][j];
		forn(i,n) forn(j,m) nxt[i][j] = 0;
		forn(i,n){
			int st=m-1;
			while(st>=0 && now[i][st] == 0) st--;
			int aux=m-1;
			while(st>=0){
				nxt[i][aux] = now[i][st];
				st--;
				aux--;
			}
		}
		
		forn(i,n) forn(j,m) now[i][j] = nxt[i][j];
		forn(i,n) forn(j,m) nxt[i][j] = 0;
		forn(j, m){
			int st = n-1;
			while(st>=0 && now[st][j] == 0) st--;
			int aux = n-1;
			while(st>=0){
				nxt[aux][j] = now[st][j];
				st--;
				aux--;
			}
		}
		forn(i,n) forn(j,m) now[i][j] = nxt[i][j];
		forn(i,n) forn(j,m) nxt[i][j] = 0;
		forn(i,n){
			int st=0;
			while(st<m && now[i][st] == 0) st++;
			int aux=0;
			while(st<m){
				nxt[i][aux] = now[i][st];
				st++;
				aux++;
			}
		}
		forn(i,n){
			forn(j,m){
				if(mx[i][j]!=0){
					if(mx[i][j] != nxt[i][j]){
						g[mx[i][j]].pb(nxt[i][j]);
						g[nxt[i][j]].pb(mx[i][j]);
					}
				}
			}
		}
		//~ forn(i,n){
			//~ forn(j,m){
				//~ cout << fixed << setprecision(2) << mx[i][j] << " ";
			//~ }
			//~ cout << '\n';
		//~ }
	//~ forn(i,n){
			//~ forn(j,m){
				//~ cout << fixed << setprecision(2) << nxt[i][j] << " ";
			//~ }
			//~ cout << '\n';
		//~ }
		forr(i,1,cont+1) used[i] = 0;
		vector<int> values;
		forr(i,1,cont+1){
			if(!used[i]){
				auxx = 0;
				dfs(i);
				values.pb(auxx);
			}
		}
		ll ans = 1;
		map<ll, int> f1;
		forall(it2, values){
			if(*it2 > 1){
				map<ll, int> f2;
				fact(*it2, f2);
				forall(it, f2) f1[it->fst] = max(f1[it->fst], f2[it->fst]);
			}
		}
		
		forall(it, f1){
			forn(_, it->snd){
				ans = (ans*(it->fst))%MOD;
			}
		}
		cout << "Case " << T+1 << ": " << ans << '\n';
		forn(i, n*m+1) g[i].clear();
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

