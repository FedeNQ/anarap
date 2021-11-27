#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MAXP 1000010
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

void fact2(ll n,map<ll,ll> &f) 
{ 
	while (criba[n])
	{
		f[criba[n]]++;
		n/=criba[n];
	}
	if(n>1) f[n]++;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	crearCriba();
	vector<ll> div(1000010),ans(1000010);
	forr(i,1,1000010){
		map<ll,ll> f;
		fact2(i,f);
		div[i]=1;
		forall(it,f) div[i] *= ((it->snd)+1);
	}
	ll idx=1;
	forr(i,1,1000010){
		if(div[idx]<div[i]) idx=i;
		ans[i]=idx;
	}
	ll a; cin>>a;
	forn(i,a){
		ll n; cin>>n;
		cout<<ans[n]<<"\n";
	}
	
	return 0;
}




