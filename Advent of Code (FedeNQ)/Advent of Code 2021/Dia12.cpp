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

map<string, int> val;
map<int, string> ix;
map<int, vector<int>> g;
map<int, bool> used;
set<int> big;
int st;
int cont = 0;
bool esp = 0;
void dfs(int node){
	//~ cout << node << " " << ix[node] << '\n';
	if(ix[node] == "end"){cont++; return;}
	forall(it, g[node]){
		if(*it == st) continue;
		if(big.count(*it)) dfs(*it);
		else{
			if(used[*it] == 1){
				if(!esp){
					esp = 1;
					dfs(*it);
					esp = 0;
				}
			}
			else{
				used[*it]=1;
				dfs(*it);
				used[*it]=0;
			}
		}
	}
	return;
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
	string p;
	while(cin >> p){
		bool isA = 1;
		string a, b;
		forn(i,sz(p)){
			if(p[i] == '-') isA=false;
			else{
				if(isA) a+=p[i];
				else b+=p[i];
			}
		}
		int ia, ib;
		if(!val.count(a)) val[a]=val.size()-1;
		if(!val.count(b)) val[b]=val.size()-1;
		ia = val[a], ib = val[b];
		g[ia].pb(ib);
		g[ib].pb(ia);
		cout << ia << " " << ib << '\n';
	}
	forall(it,val) cout << it->fst << " " << it->snd << '\n';
	forall(it, val) ix[it->snd] = it->fst;
	forall(it, val) if(it->fst[0] >= 'A' && it->fst[0]<='Z') big.insert(it->snd);
	st = val["start"];
	used[st] = 1;
	dfs(st);
	cout << cont << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


