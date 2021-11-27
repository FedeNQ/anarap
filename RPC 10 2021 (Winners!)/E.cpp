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

#define MAXN 103
vector<int> g[MAXN];
bool v[MAXN];
int ans = 0;
void increase(int x){
	v[x] = !v[x];
	forall(it, g[x]) increase(*it);
	return;
}
void contar(int x){
	if(v[x]) ans++;
	forall(it,g[x]) contar(*it);
	return;
}

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
	int n;
	while(cin >> n){
		int q; cin >> q;
		forn(i,n-1){
			int a,b;cin>>a>>b;
			g[a].pb(b);
		}
		
			forn(Q,q){
				int t; cin >> t;
				int x; cin >> x;
				if(t == 0) increase(x);
				else{ 
					ans=0;
					contar(x); 
					cout << ans << '\n';
				}
			}
		forn(i,n) g[i].clear();
		forn(i,n) v[i] = 0;
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


