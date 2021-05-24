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
	
	string s;
	cin>>s;
	
	vector<vector<ll>> mat(9);
	forn(i,9) mat[i].resize(9,0);
	
	forn(i,s.size()-1){
		int a=s[i]-'1',b=s[i+1]-'1';
		mat[a][b]++;
	}
	
	ll perm=1;
	forr(i,1,10) perm*=i;
	
	vector<ll> arr(9),pos(9);
	forn(i,9) arr[i]=i;
	
	ll ans=LLONG_MAX;
	forn(i,perm){
		ll act=0;
		forn(i,9) pos[arr[i]]=i;
		forn(j,9){
			forn(k,9){
				act+=mat[j][k]*abs(pos[j]-pos[k]);
			}
		}
		act+=pos[s[0]-'1'];
		ans=min(ans,act);
		next_permutation(arr.begin(),arr.end());
	}
	cout<<ans+s.size()<<"\n";
	
	return 0;
}




