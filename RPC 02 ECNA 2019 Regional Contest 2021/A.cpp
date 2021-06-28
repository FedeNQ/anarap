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

double dist(pair<double,double> p1,pair<double,double> p2){
	return sqrt((p1.fst-p2.fst)*(p1.fst-p2.fst) + (p1.snd-p2.snd)*(p1.snd-p2.snd));
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m,p;
	cin>>n>>m>>p;
	vector<pair<double,double>> judges(n), repos(m), stores(p);
	forn(i,n) cin>>judges[i].fst>>judges[i].snd;
	forn(i,m) cin>>repos[i].fst>>repos[i].snd;
	forn(i,p) cin>>stores[i].fst>>stores[i].snd;
	
	priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>> pq1,pq2;
	
	forn(i,n){
		forn(j,m){
			pq1.push({dist(judges[i],repos[j]),{i,j}});
		}
		forn(j,p){
			pq2.push({dist(judges[i],stores[j]),{i,j}});
		}
	}
	
	vector<bool> ujudges(n,false), urepos(m,false), ustores(p,false); 
	double ans = 0;
	while(!pq1.empty()){
		pair<double,pair<int,int>> act = pq1.top();
		int judge = act.snd.fst, repo = act.snd.snd; 
		pq1.pop();
		if(!ujudges[judge] && !urepos[repo]){
			ujudges[judge]=true;
			urepos[repo]=true;
			ans+=act.fst;
		}
	}
	ujudges.clear();
	ujudges.resize(n,false);
	while(!pq2.empty()){
		pair<double,pair<int,int>> act = pq2.top();
		int judge = act.snd.fst, store = act.snd.snd; 
		pq2.pop();
		if(!ujudges[judge] && !ustores[store]){
			ujudges[judge]=true;
			ustores[store]=true;
			ans+=act.fst;
		}
	}
	
	cout<<fixed<<setprecision(8)<<ans<<"\n";
	
	return 0;
}




