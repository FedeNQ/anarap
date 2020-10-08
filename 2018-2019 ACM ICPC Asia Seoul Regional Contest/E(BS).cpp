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
typedef pair<ll,ll> l2;

vector<l2> p;
	
bool solve(ll M){
	ll actual = 0;
	int subi = 0;
	bool ok = 1;
	ll cotamin = 0;
	forn(i, sz(p)){
		if(!ok) break;
		
		if(actual == p[i].snd) continue;
		else if(actual > p[i].snd){
			if(actual - p[i].snd > M) ok = 0;
			else cotamin = min(cotamin, p[i].snd);
		}
		else if(actual < p[i].snd){
			if(p[i].snd - actual <= M){cotamin = min(cotamin, p[i].snd); continue;}
			else{
				if(subi == 0){
					actual = p[i].snd - M;
					cotamin = p[i].snd;
					subi++;
				}
				else{
					if(p[i].snd - M <= cotamin + M){
						actual = p[i].snd-M;
					}
					else{
						subi++;
						if(subi > 2) ok = 0;
						else{
							actual = p[i].snd - M;
							cotamin = p[i].snd;
						}
					} 
				}	
			}
		}
		//~ if(M==19) cout << i << " x " << actual << " " << lastdif << " " << subi << endl;
		
	}
	return ok;
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
	cin >> n;

	forn(i,n){
		ll x,y;
		cin >> x >> y;
		p.pb(mp(x,y*10));
	}
	sort(p.begin(), p.end());
	ll L=0, R=10000000005;
	if(p[0].fst == 0) L = p[0].snd;
	while(L<R){
		ll M = (L+R)/2;
		bool ok = solve(M);
		//~ cout << M << " " << ok << endl;
		if(ok) R = M;
		else L = M+1;
	}
	
	cout << L/10 << "." << L%10 << endl;
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 

