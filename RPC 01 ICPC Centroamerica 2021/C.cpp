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
	int n,m; 
	while(1){
		cin >> n >> m;
		if(n==0 && m==0) break;
		vector<int> a(n), b(m);
		forn(i,n) cin >> a[i];
		forn(i,m) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
			int iguales=0, difa=0, difb=0, total=0;
			int ita=0, itb=0;
			while(ita<n && itb<m){
				if(a[ita] == b[itb]){
					ita++; itb++;
					iguales++;
				}
				else if(a[ita]<b[itb]) ita++;
				else itb++;
			}
			difa=n-iguales;
			difb=m-iguales;
			
			total = iguales+difb+difa;
			cout << difa << " " << iguales << " " << difb << " " << total <<'\n';
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
