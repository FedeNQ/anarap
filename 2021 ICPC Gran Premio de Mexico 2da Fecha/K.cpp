
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
#define MAXP 1000
#else
#define MAXP 1000100
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 1000000007
int vpot2[MAXP];
int ans[MAXP];

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vpot2[0] = 1;
	forr(i,1,MAXP) vpot2[i] = vpot2[i-1]*2%MOD;
	forr(i,1,MAXP) for(int x = 2*i; x < MAXP; x += i)
	{
		vpot2[x] = (vpot2[x]-vpot2[i]+MOD)%MOD;
		ans[x] = (ans[x]+vpot2[i])%MOD;
	}
	int t;
	cin >> t;
	forn(T,t)
	{
		int k;
		cin >> k;
		cout << ans[k] << '\n';
	}
	return 0;
}
