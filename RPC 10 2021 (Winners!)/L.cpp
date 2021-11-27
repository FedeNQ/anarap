#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	while(cin>>n){
		vector<ii> inp(n);
		forn(i,n) cin>>inp[i].fst>>inp[i].snd;
		sort(inp.begin(),inp.end());
		ll idx=0, maxi=0;
		forn(i,n){
			ii p = {inp[i].fst+inp[i].snd,-1};
			ll mi = (lower_bound(inp.begin(),inp.end(),p)-inp.begin()-i-1);
			if(mi>maxi) idx=i,maxi=mi;
			//~ cout<<mi<<" ";
		}
		//~ cout<<endl;
		cout<<inp[idx].fst<<" "<<maxi<<"\n";
		//~ cout<<"\n";
	}
	return 0;
}




