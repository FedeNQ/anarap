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
#define SIZE 11

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const ll mod = 1000000007LL;


ll NN;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE])
{
	ll res[SIZE][SIZE] = {{0LL}};
	forn(i, NN) forn(j, NN) forn(k, NN) res[i][j]=((res[i][j]+a[i][k]*b[k][j])%mod+mod)%mod;
	forn(i, NN) forn(j, NN) a[i][j]=res[i][j];
}
void powmat(ll a[SIZE][SIZE], ll n, ll res[SIZE][SIZE])
{
	forn(i, NN) forn(j, NN) res[i][j]=(i==j);
	while(n)
	{
		if(n&1LL) mul(res, a), n--;
		else mul(a, a), n/=2LL;
	}
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t; cin>>t;
	ll mat[SIZE][SIZE],mata[SIZE][SIZE],res[SIZE][SIZE];
	forn(T,t){
		ll p,l; cin>>p>>l;
		NN=p;
		forn(i,NN) forn(j,NN) mat[i][j]=0LL;
		forn(i,l){
			ll u,v; cin>>u>>v; u--,v--;
			mat[u][v]=1LL;
		}
		ll q; cin>>q;
		cout<<"Case "<<T+1<<":\n";
		forn(i,q){
			ll x,y,n; cin>>x>>y>>n; x--,y--;
			forn(j,NN) forn(k,NN) mata[j][k]=mat[j][k];
			powmat(mata,n,res);
			cout<<res[x][y]<<"\n";	
		}
	}
	
	return 0;
}




