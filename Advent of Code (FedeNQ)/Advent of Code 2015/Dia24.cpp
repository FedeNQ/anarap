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
	int x,sum=0;
	vector<int> v;
	while(cin >> x) v.pb(x);
	sort(v.rbegin(), v.rend());
	forall(it,v) sum+=*it;
	int val = sum/4;
	int maxi = (1<<28);
	int mini = 28;
	//~ forn(bm,maxi){
		//~ if(__builtin_popcount(bm) >= mini) continue;
		//~ int act = 0;
		//~ vector<int> v2;
		//~ forn(j,28){
			//~ if((1<<j)&bm) act += v[j];
			//~ else v2.pb(j);
		//~ }
		//~ if(act != val) continue;
		//~ bool ret = 0;
		//~ int maxi2 = 1<<sz(v2);
		//~ forn(bm2, maxi2){
			//~ vector<int> v3;
			//~ int act2 = 0;
			//~ forn(j,sz(v2)){
				//~ if((1<<j)&bm2) act2 += v[v2[j]];
				//~ else v3.pb(v2[j]);
				//~ if(act2 > val) break;
			//~ }
			//~ if(act2 != val) continue;
			//~ int maxi3 = 1<<sz(v3);
			//~ forn(bm3, maxi3){
				//~ int act3 = 0;
				//~ forn(j,sz(v3)){
					//~ if((1<<j)&bm3) act3 += v[v3[j]];
					//~ if(act3 > val) break;
				//~ }
				//~ if(act3 == val) ret = 1;
			//~ }
		//~ }
		//~ if(ret) mini=min(mini, __builtin_popcount(bm));
	//~ }
	//~ cout << mini << '\n';
	ll qe = LLONG_MAX;
	forn(bm,maxi){
		if(__builtin_popcount(bm) != 5) continue;
		int act = 0;
		vector<int> v2;
		ll actqe = 1;
		forn(j,28){
			if((1<<j)&bm){
				act += v[j];
				actqe *= v[j];
			}
			else v2.pb(j);
		}
		if(actqe>=qe || act != val) continue;
		bool ret = 0;
		int maxi2 = 1<<sz(v2);
		forn(bm2, maxi2){
			int act2 = 0;
			vector<int> v3;
			forn(j,sz(v2)){
				if((1<<j)&bm2) act2 += v[v2[j]];
				else v3.pb(v2[j]);
				if(act2 > val) break;
			}
			if(act2 == val){
				int maxi3 = 1<<sz(v3);
				forn(bm3, maxi3){
					int act3 = 0;
					forn(j,sz(v3)){
						if((1<<j)&bm3) act3 += v[v3[j]];
						if(act3 > val) break;
					}
					if(act2 == val){ret=1; break;}
				}
			}
			if(ret) break;
		}
		if(ret) qe=min(actqe, qe);
	}
	cout << qe << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

