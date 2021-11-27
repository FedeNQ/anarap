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
	
	ll arr[19]={8LL,
		49LL,
		288LL,
		1681LL,
		9800LL,
		57121LL,
		332928LL,
		1940449LL,
		11309768LL,
		65918161LL,
		384199200LL,
		2239277041LL,
		13051463048LL,
		76069501249LL,
		443365544448LL,
		2584123765441LL,
		15061377048200LL,
		87784138523761LL,
		LLONG_MAX};
	ll n; cin>>n;
	while(n!=0){
		forn(i,19){
			if(n<arr[i]){
				cout<<i<<"\n";
				break;
			}
		}
		cin>>n;
	}
	return 0;
}




