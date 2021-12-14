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

map<string, vector<string>> val;
map<string, ll> dp;
ll ans = LLONG_MAX;
string goal;

ll solve(string p){
	//~ cout << p << endl;
	if(sz(p) > sz(goal)) return sz(goal)*2LL;
	if(dp.count(p)) return dp[p];
	string aux = "";
	ll ret = INT_MAX;
	forn(i,sz(p)){
		string aux3 = "";
		aux3 += p[i];
		if(val.count(aux3)){
			forall(it, val[aux3]){
				string now = aux;
				now += *it;
				forr(j,i+1,sz(p)) now+=p[j];
				ret = min(ret,solve(now));
			}
		}
		if(i+1 < sz(p)){
			string aux2 = "";
			aux2+=p[i];
			aux2+=p[i+1];
			if(val.count(aux2)){
				forall(it, val[aux2]){
					string now = aux;
					now += *it;
					forr(j,i+2,sz(p)) now+=p[j];
					ret = min(ret,solve(now));
				}
			}
		}
		
		aux+=p[i];
	}
	return dp[p] = ret;
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
	string a,p,b; 
	forn(i,43){
		cin >> a >> p >> b;
		val[a].pb(b);
	}
	cin >> goal;
	dp[goal] = 0;
	cout << solve("e") << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



