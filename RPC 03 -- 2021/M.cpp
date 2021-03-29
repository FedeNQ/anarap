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
		vector<int> a(n);
		vector<int> b(n);
		vector<int> c(n);
		forn(i,n) cin >> a[i];
		forn(i,n) cin >> b[i];
		forn(i,n) cin >> c[i];
		forn(i,n){
			if(i) cout << " ";
			vector<int> aux(3);
			aux[0] = a[i]; aux[1] = b[i]; aux[2] = c[i];
			sort(aux.begin(), aux.end());
			cout << aux[1];
		}
		cout << "\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

