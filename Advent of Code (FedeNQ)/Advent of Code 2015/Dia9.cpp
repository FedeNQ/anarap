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
	
	map<string, int> ix;
	map<ii, int> v;
	string a, b, c;
	int na,nb;
	int val;
	cout << sz(ix)  << '\n';
	while(cin >> a >> c >> b >> c >> val){
		cout << a << " " << c << " " << b << " " << c << " " << val << '\n';
		if(!ix.count(a)){
			cout << sz(ix) << '\n';
			ix[a] = sz(ix);
			cout << ix[a] << '\n';
			cout << "XD\n";
		}
		if(!ix.count(b)) ix[b] = sz(ix);
		na=ix[a]-1; nb = ix[b]-1;
		cout << na << " " << nb << '\n';
		v[mp(na,nb)] = val;
		v[mp(nb,na)] = val;
	}
	vector<int> orden;
	forn(i,sz(ix)) orden.pb(i);
	forall(it,orden) cout << *it << " ";
	cout << '\n';
	forall(it,v) cout << it->snd << '\n';
	ll ans = 0;
	do{
		ll act = 0;
		forn(i,sz(orden)-1){
			act += v[mp(orden[i],orden[i+1])];
			//~ cout << " A " << v[mp(orden[i],orden[i+1])] << '\n';
		}
		//~ cout << '\n';
		ans = max(act,ans);
	}while(next_permutation(orden.begin(), orden.end()));
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


