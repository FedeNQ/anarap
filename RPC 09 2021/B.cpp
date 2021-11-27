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
typedef pair<int,int> ii;

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n; cin>>n;
	vector<ll> dice(6);
	vector<vector<ll>> parti(6);
	forn(i,n){
		ll in; cin>>in; dice[in-1]++; parti[in-1].pb(i);
	}
	bool ok=false;
	dforn(i,6){
		if(dice[i]==1){
			ok=true;
			cout<<parti[i][0]+1<<"\n";
			break;
		}
	}
	if(!ok) cout<<"none\n";
	
	return 0;
}




