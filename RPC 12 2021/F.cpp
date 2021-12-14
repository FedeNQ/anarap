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
typedef pair<ll,ll> ii;

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
	
	int n; cin >> n;
	vector<ii> v(n);
	forn(i,n) cin >> v[i].fst >> v[i].snd;
	ll sum1 = 0, sum2 = 0;
	forn(i,n) sum1 += v[i].fst;
	forn(i,n) sum2 += v[i].snd;
	//~ cout << sum1 << " " << sum2 << '\n';
	if((n%2 == 1) || (sum1%(n/2) != 0)|| (sum2%(n/2) != 0)) cout << "impossible\n";
	else{
		multiset<ii> todo;
		ll goal1 = sum1/(n/2), goal2 = sum2/(n/2);
		forall(it, v) todo.insert(*it);
		while(!todo.empty()){
			auto it = todo.begin();
			ii aux = *it;
			todo.erase(it);
			ii look = mp(goal1-aux.fst, goal2-aux.snd);
			//~ cout << aux.fst << " " << aux.snd << " " << look.fst << " " << look.snd << '\n';
			auto it2 = todo.lb(look);
			if(it2 == todo.end() || *it2 != look) break;
			else todo.erase(it2);
		}
		if(todo.empty()) cout << "possible\n";
		else cout << "impossible\n";
		
	}

	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


