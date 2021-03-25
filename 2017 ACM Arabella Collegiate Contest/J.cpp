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
	
	ll t;
	cin>>t;
	forn(T,t){
		double h,a,pi=acos(-1);
		cin>>h>>a;
		a = (a*2*pi)/360;
		double co = h*sin(a/2);
		double ca = h*cos(a/2);
		double at = ca*co;
		double aa = ((h*h*pi))*(a/(2*pi));
		//cout<<"co "<<co<<" ca "<<ca<<" h "<<h<<" a "<<a<<endl;
		cout<<fixed<<setprecision(6)<<(aa-at)<<"\n";
	}
	
	return 0;
}





