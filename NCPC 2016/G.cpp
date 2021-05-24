#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
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

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> r(26);
	r[0] = INT_MAX;
	forr(i,1,11) r[i] = 5;
	forr(i,11,16) r[i] = 4;
	forr(i,16,21) r[i] = 3;
	forr(i,21,26) r[i] = 2;
	
	int t; t=1;
	forn(T,t){
			
		int actrank = 25;
		int acum = 0;
		int streak = 0;
		string p; cin >> p;
		int n = sz(p);
		forn(i,n){
			if(actrank == 0) break;
			if(p[i] == 'L'){
				streak=0;
				if(actrank > 20) continue;
				else{
					acum--;
					if(actrank == 20)acum = max(0, acum);
					else{
						if(acum < 0){
							actrank++;
							acum = r[actrank]-1;
						}
					}
				}
			}
			else{
				acum++;
				streak++;
				if(actrank >= 6 && streak>=3)acum++;
				if(acum > r[actrank]){
					acum = acum-(r[actrank]);
					actrank--;
				}
				//~ cout << acum << " " << streak << " " << r[actrank] << '\n';
			}
		}
		if(actrank == 0) cout << "Legend\n";
		else cout << actrank << '\n';
	}
	
	return 0;
}
