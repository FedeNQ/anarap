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

ll const diez = 1000000000;
ll a[MAXN];
int n;
ll x;

ll ss(){
	ll acum = 0;
	ll ans = 0;
	int l = 0;
	forn(i,n){
		acum += a[i];
		while(l <= i && acum>=x){
			if(acum == x) ans++;
			acum -= a[l];
			l++;
		} 
	}
	return ans; 
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
	
	cin >> n >> x;
	forn(i,n) cin >> a[i];
	forn(i,n) a[i]+=diez;
	x+=diez;
	cout << ss() << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


