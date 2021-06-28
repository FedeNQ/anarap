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
 int dp[30][30][30][9];
#else
 int dp[105][105][105][9];
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int n,m,tam,kinks;
string s;
vector<vector<char>> mat;

int rctn(int r, int c){
	if(r<0 || r>n-1 || c<0 || c>m-1) return -1;
	return m*r+c; 
}

ii ntrc(int n){
	return {n/m,n%m}; 
}

const int ax[8]={0, 0,1,1, 1,-1,-1,-1};
const int ay[8]={1,-1,0,1,-1, 0,-1, 1};


int solve(int cel, int pos, int k, int dir){
	if(dp[cel][pos][k][dir]!=-1) return dp[cel][pos][k][dir];
	
	if(pos==tam-1 && k==kinks) dp[cel][pos][k][dir]=1;
	else if(pos==tam-1 && k!=kinks) dp[cel][pos][k][dir]=0;
	else{
		ii xy = ntrc(cel);
		forn(i,8){
			if(rctn(xy.fst+ax[i],xy.snd+ay[i])==-1 ||
				mat[xy.fst+ax[i]][xy.snd+ay[i]] != s[pos+1]) continue;
				
			if(i==dir || dir==8) dp[cel][pos][k][dir]=max(dp[cel][pos][k][dir],solve(rctn(xy.fst+ax[i],xy.snd+ay[i]),pos+1,k,i));
			else dp[cel][pos][k][dir]=max(dp[cel][pos][k][dir],solve(rctn(xy.fst+ax[i],xy.snd+ay[i]),pos+1,k+1,i));
		}
		dp[cel][pos][k][dir]=max(dp[cel][pos][k][dir],0);
	}
	return dp[cel][pos][k][dir];
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	mat.resize(n);
	forn(i,n) mat[i].resize(m);
	forn(i,n) forn(j,m) cin>>mat[i][j];
	cin>>kinks;
	cin>>s;
	tam=sz(s);
	
	forn(i,n*m+3) forn(j,tam+3) forn(l,tam+3) forn(w,9) dp[i][j][l][w]=-1;
	
	bool ans=false;
	forn(i,n){ 
		forn(j,m){
			if(mat[i][j]==s[0]) if(solve(rctn(i,j),0,0,8)==1) ans=true;
		}
	}
	if(ans) cout<<"Yes\n"; else cout<<"No\n";
	
	return 0;
}




