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
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
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
	
	ll a,b,c,d,e,f,g;
	cin>>a>>b>>c>>d>>e>>f>>g;
	vector<ll> vol;
	ll alto=1;
	a-=2;
	b-=2;
	while(a>=1 && b>=1){
		vol.pb(a*b*alto);
		a-=2;
		b-=2;
		alto++;
	}
	sort(vol.begin(),vol.end());
	reverse(vol.begin(),vol.end());
	ll ini=f;
	while(ini%vol[0]!=c) ini++;
	for(int i=ini;f<g+1;i+=vol[0]){
		if(i%vol[1]==d && i%vol[2]==e){
			cout<<i<<"\n";
			break;
		}
	}
	
	return 0;
}




