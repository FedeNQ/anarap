 
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
//#define ANARAP
#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll d;
	cin>>d;
	vector<ll> price, pricea(d);
	
	forn(i,d) cin>>pricea[i];
	price.pb(LLONG_MAX);
	price.pb(pricea[0]);
	forr(i,1,d){
		if(pricea[i]!=pricea[i-1]) price.pb(pricea[i]);
	}
	price.pb(LLONG_MIN);

	ll money=100;
	ll acciones=0;
	forr(i,1,price.size()-1){
		if(price[i-1]>price[i] && price[i]<price[i+1]){
			acciones=min(money/price[i],100000LL);
			money-=acciones*price[i];
		}
		if(price[i-1]<price[i] && price[i]>price[i+1]){
			money+=acciones*price[i];
			acciones=0;
		}
	}
	cout<<money<<"\n";
	
	return 0;
}

