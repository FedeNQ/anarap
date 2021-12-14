// ANARAP 💙💛💙
// 💧🙌🏻
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

#define l 2503

ll simulate(int v, int t, int r){
	ll ret = 0;
	int lnow = l-(l/(r+t))*(r+t);
	ret += t*v * (l/(r+t));
	ret += min(t,lnow)*v;
	return ret;
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
	
	string a, c;
	int v,t,r;
	//~ map<string, ll> ans;
	ll ans = 0;
	while(cin >> a){
		cin >> c >> c >> v >> c >> c >> t >> c >> c >> c >> c >> c >> c >> r >> c;
		cout << a << " " << v << " " << t << " " << r << '\n';
		//~ ans[a] = simulate(v,t,r);
		cout << simulate(v,t,r) << '\n';
		ans = max(ans, simulate(v,t,r));
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

