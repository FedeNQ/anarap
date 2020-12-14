#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	
	while(cin >> n){
		
		map<int, string> nameof;
		multiset<ii> orders;
		forn(i,n){
			int t; cin >> t;
			if(t==1){
				int ti, pri;
				cin >> ti >> pri;
				string name;
				cin >> name;
				nameof[ti] = name;
				orders.insert(mp(pri, ti));
			}
			else{
				int ti; cin >> ti;
				if(!orders.empty()){
					auto it = orders.begin();
					ii aux = *it;
					orders.erase(it);
					cout << aux.snd << " " << ti << " " << ti-aux.snd << " " << nameof[aux.snd] << '\n';
				}
				
			}
			
		}
		
	}
	
	
	
	
	return 0;
}

