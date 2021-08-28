#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(ll i=n-1;i>=0;i--)
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
const ll MOD = 1000000007;
const ll MAXMOD = 2010;

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

ll invFact[MAXMOD],fact[MAXMOD];
ll inverso(ll x){
	return expMod(x, MOD-2);//si mod es primo
}

void prec(){
	fact[0]=1;
	forr(i,1,MAXMOD-2) fact[i]=(fact[i-1]*i)%MOD;
	invFact[MAXMOD-3]=inverso(fact[MAXMOD-3]);
	dforn(i,MAXMOD-3) invFact[i] = (invFact[i+1]*(i+1))%MOD;
	return;
}


ll comb(ll n, ll k){
	if(k==n) return 1;
	else if(k>n) return 0; 
	else return (fact[n]*invFact[k]%MOD)*invFact[n-k]%MOD;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	bool criba[2010];
	forn(i,2010) criba[i]=true;
	criba[0]=false;
	criba[1]=false;
	forr(i,2,2010){
		if(criba[i]) for(ll j=i+i;j<2010;j+=i){
			criba[j]=false;
		}
	}
	
	prec();
	
	vector<ll> pre(2010);
	forr(i,1,2010){
		forn(j,i+1){
			if(criba[j] && criba[i-j]) pre[i]=((pre[i]+comb(i,j))%MOD+MOD)%MOD;
		}
	}
	forr(i,1,2010) pre[i]=((pre[i]+pre[i-1])%MOD+MOD)%MOD;
	
	int q; cin>>q;
	forn(i,q){
		int x,y; cin>>x>>y;
		cout<<((pre[y]-pre[x-1])%MOD+MOD)%MOD<<"\n";
	}
	
	return 0;
}




