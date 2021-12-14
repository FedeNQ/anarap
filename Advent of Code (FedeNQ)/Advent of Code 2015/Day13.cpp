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
	string a, c, t, b;
	int v;
	map<pair<string,string>, int> val;
	set<string> todo;
	while(cin >> a){
		cin >> c >> t >> v;
		cin >> c >> c >> c >> c >> c >> c;
		cin >> b;
		b.pop_back();
		if(t == "lose") v*=-1;
		cout << a << " " << t << " " << v << " " << b << '\n';
		todo.insert(a); todo.insert(b);
		val[mp(a,b)] = v;
	}
	vector<string> va;
	forall(it,todo) va.pb(*it);
	va.pb("HOLA");
	ll ans  = 0;
	do{
		ll act = 0;
		forn(i,9){
			act += val[mp(va[i],va[(i+1)%9])];
			act += val[mp(va[(i+1)%9],va[i])];
		}
		ans = max(act,ans);
		
	}while(next_permutation(va.begin(), va.end()));
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


