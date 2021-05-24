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
typedef pair<ll,ll> ii;



int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	vector<pair<ll,ii>> a(n);
	forn(i,n)cin >> a[i].fst >> a[i].snd.fst >> a[i].snd.snd;
	ll maxflow = 0, minflow = 0;
	forn(i,n){
		minflow += a[i].snd.fst;
		maxflow += a[i].snd.snd;
	}
	sort(a.begin(), a.end());
	int k; cin >> k;
	vector<ll> fix(n);
	forn(i,n) fix[i] = a[i].snd.snd-a[i].snd.fst;
	ll minit = 0;
	forn(i,n) minit = minit+(a[i].fst * a[i].snd.fst);
	forn(_,k){
		ll td, fd; cin >> td >> fd;
		if(fd >= minflow && fd <= maxflow){
			ll maxtd = minit, mintd = minit;
			ll auxfd = fd-minflow;
			//~ cout << minit << '\n';
			bool can = 1;
			forn(i,n){
				if(auxfd>fix[i]){
					mintd+=fix[i]*a[i].fst;
					auxfd-=fix[i];
				}
				else{
					mintd += auxfd * a[i].fst;
					auxfd=0;
				}
			}
			//~ cout << mintd << '\n';
			if(auxfd != 0) can = 0;
			auxfd = fd-minflow;
			dforn(i,n){
				if(auxfd>fix[i]){
					maxtd += fix[i]*a[i].fst;
					auxfd-=fix[i];
				}
				else{
					maxtd += auxfd * a[i].fst;
					auxfd=0;
				}
			}
			if(auxfd != 0) can = 0;
			if(can){
				if((td*fd)>=mintd && (td*fd)<=maxtd) cout << "yes\n";
				else cout << "no\n";
			}
			else cout << "no\n";
		}
		else cout << "no\n";
	}
	
	return 0;
}

