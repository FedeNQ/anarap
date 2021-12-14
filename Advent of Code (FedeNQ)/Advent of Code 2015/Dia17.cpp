
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
	
	vector<int> v;
	int x;
	while(cin >> x) v.pb(x);
	sort(v.rbegin(), v.rend());
	int n = sz(v);
	int cota = 150;
	int ans = 0;
	int mini = n;
	
	forn(bm, 1<<n){
		int acum = 0;
		forn(j,n){
			if((1<<j)&bm){
				acum += v[j];
			}
			if(acum > cota) break;
		}
		if(acum > cota) continue;
		else if(acum == cota){
			int val = __builtin_popcount(bm);
			if(mini == val) ans++;
			else if(mini < val) continue;
			else if(mini > val){mini=val; ans=1;}
		}
	}
	cout << mini << '\n';
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

