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
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

bool dp[101][MAXN];
int n; 
vector<int> a;

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
	a.resize(n);
	forn(i,n) cin >> a[i];
	sort(a.begin(), a.end());
	forn(i, n){
		dp[i][0] = 1;
		forn(j, MAXN-1){
			if(dp[i][j]){
				//~ if(j+a[i] == 4) cout << i << " " << j << " " << a[i] << '\n';
				dp[i+1][j+a[i]] = 1;
				dp[i+1][j] = 1;
			}
		}
	}
	int cont =0;
	forr(j,1,MAXN-1) if(dp[n][j]) cont++;
	cout << cont << '\n';
	forr(j,1, MAXN-1){
		if(dp[n][j]) cout << j << " ";
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

