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
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 10000007LL
#define MAXN 1000100

#define MAXP 10001001
int criba[MAXP+1];
void crearCriba(){
	int w[]={4,2,4,2,4,6,2,6};
	for(int p=25;p<=MAXP;p+=10) criba[p]=5;
	for(int p=9;p<=MAXP;p+=6) criba[p]=3;
	for(int p=4;p<=MAXP;p+=2) criba[p]=2;
	for(int p=7, cur=0; p*p<=MAXP; p+=w[cur++&7]) if(!criba[p])
	for(int j=p*p;j<=MAXP;j+=(p<<1)) if(!criba[j]) criba[j]=p;
}

vector<int> primos;

void fact(int n, map<int,int> &f){
	while(criba[n]){
		f[criba[n]]++;
		n/=criba[n];
		
	}
	if(n>1) f[n]++;
	
}

ll expMod(ll b, ll e, ll m=MOD){
	if(!e) return 1;
	ll q = expMod(b,e/2, m);
	q=q*q%m;
	return e%2? b*q%m:q;
}

ll ephi;

int eulerPhi(int n)
{
	map<int,int> f;
	fact(n,f);
	int ret=n;
	forall(it, f) ret-=ret/it->first;
	return ret;
}


ll inverso(ll x){
	return expMod(x, ephi-1);
}


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	crearCriba();
	ephi = eulerPhi(MOD);
	vector<ll> vexp(MAXN,0);
	set<int> bad;
	vector<ll> vans(MAXN);
	ll curans = 1;
	forr(i,1,MAXN)
	{
		map<int,int> f;
		fact(i,f);
		forall(it,f)
		{
			ll aux = (vexp[it->fst] + it->snd)%MOD;
			if(bad.count(it->fst))
			{
				if(__gcd((aux+1)*(aux+2)/2, MOD) == 1)
				{
					//if(i < 5) cout << "curans=" << curans << '\n';
					//if(i < 5) cout << "mult by " << (aux+1)*(aux+2)/2 << '\n';
					curans = curans*((aux+1)*(aux+2)/2%MOD)%MOD;
					//if(i < 5) cout << "curans=" << curans << '\n';
					bad.erase(it->fst);
				}
			}
			else
			{
				//if(i < 5) cout << "curans=" << curans << '\n';
				//if(i < 5) cout << "divide by " << (vexp[it->fst]+1)*(vexp[it->fst]+2)/2 << ' ' << "(inv=" << inverso((vexp[it->fst]+1)*(vexp[it->fst]+2)/2%MOD) << ")\n";
				//assert(__gcd((vexp[it->fst]+1)*(vexp[it->fst]+2)/2, MOD) == 1);
				curans = curans*inverso((vexp[it->fst]+1)*(vexp[it->fst]+2)/2%MOD)%MOD;
				//if(i < 5) cout << "curans=" << curans << '\n';
				if(__gcd((aux+1)*(aux+2)/2, MOD) != 1) bad.insert(it->fst);
				else
				{
					//if(i < 5) cout << "curans=" << curans << '\n';
					//if(i < 5) cout << "mult by " << (aux+1)*(aux+2)/2 << '\n';
					curans = curans*((aux+1)*(aux+2)/2%MOD)%MOD;
					//if(i < 5) cout << "curans=" << curans << '\n';
				}
			}
			vexp[it->fst] = aux;
		}
		//assert(curans != 0);
		ll ans = curans;
		forall(it, bad) ans = ans*((vexp[*it]+1)*(vexp[*it]+2)/2%MOD)%MOD;
		vans[i] = ans;
		/*if(i <= 5)
		{
			cout << i << ": " << curans << "\n";
			forn(j,MAXN) if(vexp[j]) cout << j << ' ' << vexp[j] << '\n';
		}*/
	}
	//forr(i,1,6) cout << i << ' ' << vans[i] << '\n';
	//return 0;
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		cout << vans[n] << '\n';
	}
	return 0;
}
