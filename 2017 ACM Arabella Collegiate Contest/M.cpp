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

	int t; cin >> t;
	unordered_map<string, double> cambio;
	int n, m; 
	forn(T,t){
		scanf("%d%d",&n,&m);
		char s[11];
		double val;
		string p;
		forn(i,n){
			scanf("%s%lf",s,&val);
			p=s;
			cambio[p] = val;
		}
		cambio["JD"]=1.0;
		double ans = 0;
		forn(i,m){
			scanf("%lf%s",&val,s);
			p=s;
			ans += val*cambio[p];
		}
		printf("%.6lf\n",ans);
		cambio.clear();
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
