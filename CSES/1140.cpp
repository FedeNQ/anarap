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
#define MAXN 100
#else
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> l2;

int n;
ll dp[MAXN];
vector<pair<l2,pair<ll,int>>> v;

ll solve(int pos){
	if(pos >= n) return 0;
	if(dp[pos] != -1) return dp[pos];
	ll ret  = solve(pos+1);
	auto it = lower_bound(v.begin(), v.end(), mp(mp(v[pos].fst.snd+1, 0LL), mp(0LL,0)));
	//~ if(it!=v.end()){
		//~ cout << "lb " << (it->fst).fst << " " << v[pos].fst.snd << '\n';
		 //~ cout << "Pos " << pos << " going to " << (it->snd).snd << '\n';
		 
	 //~ }
	if(it!=v.end()) dp[pos] = max(ret, v[pos].snd.fst + solve((it->snd).snd));
	else dp[pos] = max(ret, v[pos].snd.fst);
	return dp[pos];
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
	
	cin >> n;
	v.resize(n);
	forn(i,n) cin >> v[i].fst.fst >> v[i].fst.snd >> v[i].snd.fst;
	forn(i,n) v[i].snd.snd=1;
	memset(dp,-1,sizeof(dp));
	sort(v.begin(), v.end());
	forn(i,n) v[i].snd.snd=i;
	cout << solve(0) << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


