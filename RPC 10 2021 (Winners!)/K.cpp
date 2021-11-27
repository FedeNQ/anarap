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
	
	vector<int> div(2501);
	forr(i,1,2501){
		for(int j=i;j>0;j--) if(i%j==0) div[i]++;
	}
	vector<int> ans(2501);
	int maxi=1;
	forr(i,1,2501){
		if(div[maxi]<div[i]) maxi=i;
		ans[i]=maxi;
	}
	int a; cin>>a;
	forn(A,a){
		int n; cin>>n; cout<<ans[n]<<"\n";
	}
	return 0;
}




