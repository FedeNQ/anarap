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

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<ll> powers;
	forr(i,1LL,2000000LL) powers.insert(i*i);
	ll t; cin>>t;
	forn(T,t){
		ll k; cin>>k;
		ll y=2LL; 
		while(powers.find(2*y*y-k)==powers.end() || 2LL*(y*y-k)<=0) y++;
		ll n = 2LL*(y*y-k);
		cout<<"Case "<<T+1<<": "<<n<<"\n"; 
	}
	return 0;
}




