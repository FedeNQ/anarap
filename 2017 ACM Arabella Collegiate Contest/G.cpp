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
		ll n,m, k; cin >> n >> m >> k;
		ll ans = ((n*(n+1))/2) * ((m*(m+1))/2);
		vector<ii> bomba(k);
		forn(i,k){
			cin >> bomba[i].fst >> bomba[i].snd;
			bomba[i].fst--;
			bomba[i].snd--;
		}
		forr(i,1,(1<<k)){
			int tot=0,maxx=0, maxy=0, minx=n, miny=m;
			forn(j,k){
				if(i&(1<<j)){
					tot++;
					maxx = max(maxx, bomba[j].fst); minx = min(minx, bomba[j].fst);
					maxy = max(maxy, bomba[j].snd); miny = min(miny, bomba[j].snd);
				}
			}
			minx++; miny++;
		//	cout << tot << " " << (n-maxx) << " " << m-maxy << " " << minx << " " << miny << '\n';
			if(tot%2) ans-=1LL*minx*(n-maxx)*miny*(m-maxy);
			else ans+=1LL*minx*(n-maxx)*miny*(m-maxy);
		}	
		cout << ans << '\n';
	}
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

