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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,w;
	cin>>n>>w;
	vector<vector<ll>> g(n+1);
	vector<ll> cap(n+1), amo(n+1), maxi(n+1);
	forn(i,n){
		ll u,c,a;
		cin>>u>>c>>a;
		g[u].pb(i+1);
		cap[i+1]=c;
		amo[i+1]=a;
	}
	cap[0]=w;
	amo[0]=0;
	queue<ll>q;
	q.push(0);
	maxi[0]=w;
	ll ans=w;
	while(!q.empty()){
		ll u=q.front();q.pop();
		forn(i,sz(g[u])){
			ll v=g[u][i];
			q.push(v);
			maxi[v]=max(maxi[u]-amo[v],cap[v]-amo[v]);
			ans=min(ans,maxi[v]);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
