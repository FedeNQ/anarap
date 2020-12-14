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
	int t; cin >> t;
	forn(T,t){
		int n; cin >> n;
		vector<ii> a(n);
		int cont = 0;
		forn(i,n) cin >> a[i].fst >> a[i].snd;
		sort(a.begin(), a.end());
		forn(i,n){
			forr(j,i+1,n){
				forr(k,j+1, n){
					double m1 = double(a[i].snd-a[j].snd)/(a[i].fst-a[j].fst);
					double m2 = double(a[i].snd-a[k].snd)/(a[i].fst-a[k].fst);
					if(m1 != m2) cont++;
				}
			}
		}
		cout << cont << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

