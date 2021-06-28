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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//<key,mapped type,comparator,...>
typedef tree<int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update> ordered_set;

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
	vector<int> a(n);
	forn(i,n) cin >> a[i];
	ordered_set player; 
	forn(i,n) player.insert(i);
	int cant=n;
	int next=0;
	while(cant > 1){
		int auxi = player.order_of_key(next);
		int giro = (a[next]+auxi)%cant;
		if(giro == 0) giro=n;
		giro--;
		//~ cout << "GIRO " << giro  << '\n';
		auto it = player.find_by_order(giro);
		//~ cout << " MUERE " << *it << "\n";
		auto it2 = it;
		it2++;
		if(it2 == player.end()) it2=player.begin();
		next = *it2;
		//~ cout << "NEXT " << *it2 << '\n';
		player.erase(it);
		cant--;
	}
	cout << *(player.begin())+1 << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

