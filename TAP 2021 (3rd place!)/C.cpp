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

ll MOD;
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
void fact(ll n,map<ll,ll> &f) //O (lg n)
{ //llamar a crearCriba antes
	while (criba[n])
	{
		f[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) f[n]++;
}

ll eulerPhi(ll n) // con criba: O(lg n)
{
	map<ll,ll> f;
	fact(n,f);
	ll ret=n;
	forall(it, f) ret-=ret/it->first;
	return ret;
}
ll mulMod(ll a,ll b,ll m=MOD) //O(log b)
{ //returns (a*b) %c, and minimize overfloor
	ll x=0, y=a%m;
	while(b>0)
	{
		if(b%2==1) x=(x+y)%m;
		y=(y*2)%m;
		b/=2;
	}
	return x%m;
}
ll expMod(ll b,ll e,ll m=MOD) //O(log b)
{
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=mulMod(q,q,m);
	return e%2? mulMod(b,q,m) : q;
}
int inverso(int x) //O(log x)
{
	return expMod(x, eulerPhi(MOD)-1);//si mod no es primo(sacar a mano)
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
	crearCriba();
	int b; cin >> b;
	int n; cin >> n;
	vector<ll> resto(n+3, 0);
	vector<ll> add(n+3,0);
	vector<ll> v(n);
	ll bb = b+1;
	resto[0] = 1;
	forr(i,1,n+2) resto[i] = (resto[i-1]*b)%bb;
	//~ forn(i,n+1) cout << resto[i] << " ";
	//~ cout << '\n';
	forn(i,n) cin >> v[n-1-i];
	ll total = 0;
	forn(i,n){
		add[i] = (v[i]*resto[i])%bb;
		total += add[i];
		total %= bb;
	}
	MOD = bb;
	ll inv0 = inverso(resto[0]), inv1 = inverso(resto[1]);
	//~ cout << resto[0] << " " << resto[1] << '\n';
	//~ cout << inv0 << " " << inv1 << '\n';
	return 0;
	if(total % bb == 0) cout << "0 0\n";
	else{
		//~ cout << "total " << total << '\n';
		ll nuevo;
		pair<int,int> ans = mp(-1,-1);
		//~ bool ok = 0;
		//~ forn(i,n) cout << v[i] << " ";
		//~ cout << '\n';
		dforn(i,n){
			if(i%2 == 0) nuevo = (((total*inv1 + v[i])%bb ) + bb )% bb;
			else nuevo = (((total*inv0 + v[i])%bb ) + bb )% bb;
			//~ cout << v[i] << " total:" << total << " nuevo:" << nuevo << "\n";
			if(nuevo < v[i]){ans = mp(n-i, nuevo); break;} 
		}
		
		cout << ans.fst << " " << ans.snd << '\n';
	}
	
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


