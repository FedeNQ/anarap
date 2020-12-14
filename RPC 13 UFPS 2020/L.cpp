#include <bits/stdc++.h>
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

#ifdef ANARAP
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define MAXN 18

double dp[MAXN][MAXN];
int a,b,c,n,k;

double solve(int pos, int obt){
	if(obt==0) return 1.0;
	if(pos==a) return 0;
	if(dp[pos][obt] != -1) return dp[pos][obt];
	double actn = n - (k-obt);
	double actt = (a+b+c)-pos;
	double proba = actn/actt;
	double ret = 0;
	ret += proba*solve(pos+1, obt-1);
	ret += (1-proba)*solve(pos+1, obt);
	return dp[pos][obt] = ret;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	forn(T,t){
		cin >> a >> b >> c >> n >> k;
		forn(i, a+1) forn(j,k+1) dp[i][j] = -1;
		cout << fixed << setprecision(4) << solve(0,k) << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

