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
vector<vector<bool>> visi;
vector<vector<ll>> mat;
ll ans=0, h, w;

void colorear(ll x, ll y){
	if(visi[x][y]) return;
	visi[x][y]=true;
	if(x>0 && !visi[x-1][y] && mat[x-1][y]<=mat[x][y]) colorear(x-1,y);
	if(x<h-1 && !visi[x+1][y] && mat[x+1][y]<=mat[x][y]) colorear(x+1,y);
	if(y>0 && !visi[x][y-1] && mat[x][y-1]<=mat[x][y]) colorear(x,y-1);
	if(y<w-1 && !visi[x][y+1] && mat[x][y+1]<=mat[x][y]) colorear(x,y+1);
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>h>>w;
	mat.resize(h);
	visi.resize(h);
	vector<pair<ll,ii>> pq;
	forn(i,h){
		mat[i].resize(w);
		visi[i].resize(w,false);
		forn(j,w){
			cin>>mat[i][j];
			pq.pb({mat[i][j],{i,j}});
		}
	}
	sort(pq.begin(),pq.end());
	reverse(pq.begin(),pq.end());
	
	forn(i,pq.size()){
		ll x = pq[i].snd.fst, y=pq[i].snd.snd;
		if(mat[x][y]>1 && !visi[x][y]){
			ans++;
			colorear(x,y);
		}
		
	}
	cout<<ans<<"\n";
	
	return 0;
}




