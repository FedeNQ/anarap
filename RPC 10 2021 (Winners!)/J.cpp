// ANARAP 💙💛💙
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
	int n;
	while(cin>>n){
		int q; cin >> q;
		vector<ll> acum(n,0);
		vector<ll> v(n);
		forn(i,n) cin >> v[i];
		acum[0] = 1;
		forr(i,1,n) acum[i] = acum[i-1]+v[i];
		forn(i,q){
			ll x; cin >> x;
			if(i) cout << " ";
			auto it = upper_bound(acum.begin(), acum.end(), x);
			int ans = abs(distance(acum.begin(), it));
			cout << ans;
		}
		cout << '\n';
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


