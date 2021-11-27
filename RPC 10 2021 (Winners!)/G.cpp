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
	
	int a; cin>>a;
	forn(A,a){
		vector<int> wei(6); int sum=0;
		forn(i,6){
			cin>>wei[i];
			sum+=wei[i];
		}
		bool ok=false;
		forn(i,64){
			int t1=0;
			forn(j,6) if(i&(1<<j)) t1+=wei[j];
			if(t1==sum-t1) ok=true;
		}
		if(ok) cout<<"Tobby puede cruzar\n";
		else cout<<"Tobby no puede cruzar\n";
	}
	
	return 0;
}




