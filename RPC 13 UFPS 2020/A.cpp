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

#define MAXP 1000000 //no necesariamente primo
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
	ll n, t;
	cin >> n >> t;
	ll S,P,C;
	cin >> S >> P >> C;
	crearCriba();
	int p=0,c=0;
	forr(i,2,n+1){
		if(criba[i]) c++;
		else p++;
	}  
	//~ cout << c <<'\n';
	forn(i, t%n){
		S--;
		if(S==0) S=n;
		if(S!=1){
			if(criba[S]) C++;
			else P--;
		}
	}
	//~ cout << P << " " << C << '\n';
	P -= (t/n)*p;
	C += (t/n)*c;
	
	if(P<0){
		ll aux = (-P+n)/n;
		P = (P + aux*n)%n;
	}
	if(P==0) P=n;
	C = C%n;
	if(C==0) C=n;
	cout << S << " " << P << " " << C << '\n';
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

