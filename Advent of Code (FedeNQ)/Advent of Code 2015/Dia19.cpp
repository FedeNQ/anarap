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
	string a,p,b; 
	map<string, vector<string>> val;
	forn(i,43){
		cin >> a >> p >> b;
		val[a].pb(b);
	}
	set<string> todos;
	string big; cin >> big;
	forall(it, val){
		forall(it2, it->snd){
			string act = "", aux = "" ;
			if(sz(it->fst) == 1){
				forn(i, sz(big)){
					if(big[i] == it->fst[0]){
						aux = act;
						aux += *it2;
						forr(j,i+1,sz(big)) aux += big[j];
						todos.insert(aux);
					}
					act+=big[i];
				}
			}
			else{
				forn(i, sz(big)-1){
					if(big[i] == it->fst[0] && big[i+1] == it->fst[1]){
						aux = act;
						aux += *it2;
						forr(j,i+2,sz(big)) aux += big[j];
						todos.insert(aux);
					}
					act+=big[i];
				}
			}
		}
	}
	cout << sz(todos) << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


