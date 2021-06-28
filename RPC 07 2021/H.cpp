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
	int n; cin >> n;
	int s; cin >> s;
	vector<int> need[2];
	forn(i,s){
		int x; cin >> x;
		char p; cin >> p;
		bool ok = 0;
		if(p == 'y') ok = 1;
		need[ok].pb(x);
	}
	sort(need[0].begin(), need[0].end());
	sort(need[1].rbegin(), need[1].rend());
	map<int, bool> used;
	bool can = 1;
	int last = 1000000003;
	forall(it, need[1]){
		int lastnow = min(last-1, *it);
		if(lastnow <= 0){can = 0; break;}
		used[lastnow] = 1;
		last = lastnow;
	}
	if(can == 0) cout << "No\n";
	else{
		int act = 1;
		int cap = n;
		if(used[act]) cap--;
		forall(it,need[0]){
			while(cap <= 0){
				act++;
				cap=n;
				if(used[act]) cap--;
			}
			if(act > *it){can=0; break;}
			else cap--;
		}
		if(can) cout << "Yes\n";
		else cout << "No\n";
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


