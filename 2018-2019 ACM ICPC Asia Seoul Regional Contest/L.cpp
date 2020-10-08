
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin(); it!=v.end();it++)
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

int main()
{
#ifdef ANARAP
freopen("input.in", "r", stdin);
//freopen("output.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int p, d, w, h;
	cin >> p >> d >> w >> h;
	multiset<ii> cual;
	vector<vector<int>> ans(p);
	ll acum = 0;
	forn(i,p){
		int x;
		cin >> x;
		cual.insert(mp(x,i));
		acum += x;
	}
	ll acum2 = 0;
	vector<int> day(d);
	forn(i, d){
		cin >> day[i];
		acum2 += day[i];
	}

	//~ forall(it, day){
		//~ cout << *it << " ";
	//~ }
	//~ cout << endl;
	vector<vector<ii>> next(d);
	bool ok = 1;
	if(acum!=acum2) ok = 0;
	forn(i, d){
		if(day[i] < 0){ok = 0;  break;}
		forall(it, next[i]){cual.insert(*it);	}
		while(day[i] > 0){
			if(cual.empty()){ ok = 0; break;}
			else{
				auto it = cual.end();
				it--;
				ii agrego = *it;
				//~ cout << "LABURA " << agrego.snd << endl;
				forr(j,i,i+w){
					if(j < d){day[j]--;} 
					}
			
				ans[agrego.snd].pb(i+1);
				cual.erase(it);
				if(i+w+h < d){
					if(agrego.fst-w > 0){next[i+w+h].pb(mp(agrego.fst-w, agrego.snd));}
				}
			}
		}
		//~ forn(D,d){
			//~ cout << day[D] << " ";
		//~ }
		//~ cout <<'\n';
		
	}

	
	if(ok) {
		cout << 1 << endl;
		forn(i, p){
		forall(it, ans[i]){
			cout << *it << " ";
		}
		cout << '\n';
		}
	}
	else{
		cout << "-1\n";
	}
	return 0;
}
 

