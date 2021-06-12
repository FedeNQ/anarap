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

#define MAXN 1003

ll dp[MAXN][MAXN];

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
	
	string p; cin >> p;
	reverse(p.begin(), p.end());
	int szp = sz(p);
	dp[0][0]=0; // pago 0;
	dp[0][1]=1; // pague 1 ya
	forn(i,szp){
		dp[i+1][0] = min(dp[i][0]+int(p[i]-'0'), dp[i][1]-int(p[i]-'0')+10); //pruebo pagar todo, o bien pago para arriba
		dp[i+1][1] = min(dp[i][0]+int(p[i]-'0')+1, dp[i][1]-int(p[i]-'0')+9);
	}
	cout << dp[szp][0] << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


