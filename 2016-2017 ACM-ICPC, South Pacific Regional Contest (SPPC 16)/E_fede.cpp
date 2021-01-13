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
#define MAXN 100
#else
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

char cool[MAXN];
int color[MAXN];
vector<int> g[2][MAXN];

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
	forn(i,n){
		color[i] = -1;
		cin >> cool[i];
		int t; cin >> t;
		if(cool[i] == 'C'){
			forn(j, t){
				int x; cin >> x; x--;
				g[0][i].pb(x);
				g[0][x].pb(i);
			}
		}
		else{
			forn(j, t){
				int x; cin >> x; x--;
				g[1][i].pb(x);
			}
		}
	}
	forn(i,n){g[1][i].pb(i); sort(g[1][i].begin(), g[1][i].end());}
	bool ans = 1;
	forn(i,n){
		if(ans){
			if(color[i] == -1){
				if(cool[i] == 'C'){
					if(sz(g[0][i]) == 0) ans = 0;
					else{
						int col = color[g[0][i][0]];
						if(col == -1){
							color[g[0][i][0]] = 1;
							color[i] = 0;
						} 
						else if(col == 1) color[i]=0;
						else color[i]=1;
					}
				}
				else{
						if(sz(g[1][i]) == n) ans = 0;
						else{
							int aux = 0;
							int szg = sz(g[1][i]);
							int act = 0;
							while(act<szg && g[1][i][act]==aux){
								aux++;
								act++;
							}
							int col = color[aux];
							if(col == -1){
								color[aux] = 1;
								color[i] = 0;
							} 
							else if(col == 1) color[i]=0;
							else color[i]=1;
						}
				}
			}
		}
	}
	if(ans==0) cout << "Impossible\n";
	else forn(i,n){
		if(color[i] == 1) cout << 'S';
		else cout << 'V';
		assert(color[i] != -1);
	}
	if(ans) cout << '\n';
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
