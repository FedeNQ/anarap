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

#define MAXN 1003
ll mx[MAXN][MAXN];

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
	forn(i,n) forn(j,n) cin >> mx[i][j];
	vector<ll> todos;
	ll total = 0;
	forn(i,n){
		ll sum = 0;
		forn(j,n) sum += mx[i][j];
		todos.pb(sum);
		total += sum;
	}
	sort(todos.begin(), todos.end());
	//~ forall(it,todos) cout << *it << " ";
	//~ cout << '\n';
	ll malos = 0;
	forn(i,n/2) malos += todos[i];
	cout << (total-2*malos)/2 << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


