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

#define MAXP 2000000 //no necesariamente primo
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
vector<int> primos, p2;
void buscarPrimos()
{
	crearCriba();
	forr (i,2,MAXP+1) if (!criba[i]) primos.push_back(i);
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
	
	buscarPrimos();
	forn(i,sz(primos)-1){
		if(primos[i+1]-primos[i] == 2){
			p2.pb(primos[i]); 
			p2.pb(primos[i+1]);
		}
	}
	int n; cin >> n;
	forn(i,n){
		int x; cin >> x;
		auto it = ub(p2.begin(), p2.end(), x);
		auto it2 = ub(p2.begin(), p2.end(), x);
		if(it2 != p2.begin()){
			it2--;
			if(abs(x-*it) > abs(x-*it2)) cout << *it2 << '\n';
			else cout << *it << '\n';
		}
		else cout << *it << '\n';
		
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


