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

ll gauss(ll a){
	return (a*(a+1))/2;
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
	
	string p; cin >> p;
	vector<ll> q;
	ll ret = 0;
	for(int i=0; i<sz(p); i++){
		if(p[i] == ','){q.pb(ret); ret=0;}
		else{
			ret *= 10;
			ret += p[i]-'0';
			if(i == sz(p)-1) q.pb(ret);
		}
	}
	ll val1=-1, val2=-1;
	ll sum = 0;
	forall(it,q) sum+=*it; 
	ll tam = sz(q);
	val1 = sum/tam;
	val2 = (sum+tam-1)/tam;
	cout << val1 << " " << val2 << '\n';
	ll ans = LLONG_MAX;
	ll act=0;
	forn(j,sz(q)) act += gauss(abs(val1-q[j]));
	ans = min(ans,act);
	act=0;
	forn(j,sz(q)) act += gauss(abs(val2-q[j]));
	ans = min(ans,act);
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


