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
	string p,a,b;
	map<string, vector<string>> g;
	map<string, int> in;
	while(cin >> p){
		cin >> a >> p >> p >> p >> p >> p >> b >> p >> p;
		g[a].pb(b);
		if(!in.count(a)) in[a] = 0;
		if(!in.count(b)) in[b] = 0;
		in[b]++;
	}
	set<string> q;
	forall(it, in) cout << it->fst << " " << it->snd << '\n';
	forall(it, in) if(it->snd == 0) q.insert(it->fst);
	vector<string> ans;
	
	int tt = 0;
	int n = 2;
	vector<int> elf(n,0);
	vector<string> celf(n);
	while(1){
		forn(i,n){
			if(elf[i] > 0){
				elf[i]--;
				if(elf[i] == 0){
					string aux = celf[i];
					forall(it, g[aux]){
						if(in[*it] > 0){
							in[*it]--;
							if(in[*it] == 0) q.insert(*it);
						}
					}	
				}
			}
		}
		int cont = 0;
		forn(i,n){
			if(elf[i] == 0){
				if(!q.empty()){
					string aux = *(q.begin());
					q.erase(q.begin());
					celf[i] = aux;
					elf[i] = 0 + celf[i][0]-'A'+1;
				}
				else cont++;
			}
		}
		if(cont == 2) break;
		tt++;
	}
	cout << tt << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


