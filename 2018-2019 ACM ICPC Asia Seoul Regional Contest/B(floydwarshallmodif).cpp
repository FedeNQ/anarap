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
#define MAXN 50
#else
#define MAXN 502
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
int mx[MAXN][MAXN];
int zero = 1000003;
int n,m;
int G[MAXN][MAXN];
void floyd(){//O(N^3)
	forn(k, m){
		 forn(i, m){
			  if(G[i][k]!=zero){
				   forn(j, m) {
					   if(G[k][j]!=zero){
						   //~ cout << i << " " << k << " "<< j << endl;
						   //~ cout << G[i][j] << " " << G[i][k] << " " << G[k][j] << endl;
							G[i][j]=max(G[i][j], min(G[i][k], G[k][j]));
						}
					}
				}
			}
		}
}

//~ void calcmax(){
	//~ forn(i,m){
		//~ forn(j,m){
			//~ maxi[i][j] = max(G[i][j], 
		//~ }
		
	//~ }
//~ }

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
	cin >> m >> n;
	forn(i,n) forn(j,m) cin >> mx[i][j];
	forn(i,n) forn(j,m) if(mx[i][j] == 0) mx[i][j] = zero;
	forn(i,m){
		forn(j, m){
			G[i][j] = 0;
		}
	}
	
	forn(i,m){
		
		forr(j, i+1, m){
			int wi = 0, wj = 0;
			forn(k,n){
				if(mx[k][i] > mx[k][j]) wj++;
				if(mx[k][i] < mx[k][j]) wi++;
			}
			//~ cout << i << " " << j << " " << wi << " " << wj << endl;
			if(wi > wj) G[i][j] = wi;
			if(wi < wj) G[j][i] = wj;
			
		}
	}
	//~ forn(i,m){
		//~ forn(j,m){
			//~ if(G[i][j] == zero) cout << 0 << " ";
				//~ else cout << G[i][j] << " ";
		//~ }
		//~ cout << endl;
	//~ }
	//~ cout << endl;
	
	
	//~ forn(i,n){
		//~ forn(j,m){
			//~ cout << mx[i][j] << " ";
		//~ }
		//~ cout << endl;
	//~ }
	//~ forn(i, m){
		//~ cout << "Grafo " << i << ": ";
		//~ forall(it, G[i]){
			//~ cout << it->fst << " ";
		//~ }
		//~ cout << endl;
	//~ }
	
	//~ forn(i,m){
		//~ forn(j,m){
			//~ if(G[i][j] == zero) cout << 0 << " ";
				//~ else cout << G[i][j] << " ";
		//~ }
		//~ cout << endl;
	//~ }
	floyd();	
	//~ cout << "F " << endl;
	//~ forn(i,m){
		//~ forn(j,m){
			//~ if(G[i][j] == zero) cout << 0 << " ";
				//~ else cout << G[i][j] << " ";
		//~ }
		//~ cout << endl;
	//~ }
	
	int act = 0;
	vector<int> ans;
	
	forn(i,m){
		int pans = 0;
		forn(j,m){
			if(G[i][j] >= G[j][i]){
				pans++;
			}
		}
		//~ cout << i << " " << pans << " " << act << endl;
		if(pans > act){
				act = pans;
				ans.clear();
				ans.pb(i+1);
		}
		else if(pans == act) ans.pb(i+1);
	}
	forall(it, ans) cout << *it << " ";
	cout << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 

