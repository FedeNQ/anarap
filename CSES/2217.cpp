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
	int q; cin >> q;
	vector<int> a(n);
	set<int> seen;
	int ans = 1;
	vector<int> pos(n+1);
	forn(i,n){
		cin >> a[i];
		pos[a[i]] = i;
		if(a[i]-1 != 0){ if(!seen.count(a[i]-1)) ans++;}		
		seen.insert(a[i]);
	}
	//~ cout << ans << '\n';
	forn(i,q){
		int psa, psb; cin >> psa >> psb;
		psa--; psb--;
		int na = a[psa], nb = a[psb];
		if(na > nb){swap(na, nb), swap(psa, psb);}
		//~ cout << "na " << na << " nb " << nb << '\n';
		if(na-1 > 0){
			if(pos[na-1] > pos[na]){
				if(pos[na-1] < pos[nb]) ans--; 
			}
			else{
				if(pos[na-1] > pos[nb]) ans++;
			}
		}
		if(nb-1 > 0 && nb-1 != na){
			if(pos[nb-1] > pos[nb]){
				if(pos[nb-1] < pos[na]) ans--; 
			}
			else{
				if(pos[nb-1] > pos[na]) ans++;
			}
		}
		if(na+1 <= n){
			if(na+1 == nb){
				if(pos[na] < pos[nb]) ans++;
				else ans--;
			}
			else{
				if(pos[na+1] < pos[na]){
					if(pos[na+1] > pos[nb]) ans--;
				}
				else{
					if(pos[na+1] < pos[nb]) ans++;
				}
			}
		}
		if(nb+1 <= n){
			if(pos[nb+1] < pos[nb]){
				if(pos[nb+1] > pos[na]) ans--;
			}
			else{
				if(pos[nb+1] < pos[na]) ans++;
			}
		}
		swap(pos[na], pos[nb]);
		swap(a[psa], a[psb]);
		cout << ans << '\n';
	}
			
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


