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
#define MAXN 100
#else
#define MAXN 10010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> g[MAXN];
bool used[MAXN];
int total;

void solve(int node){
	if(used[node]) return;
	used[node]=1;
	total++;
	forall(it, g[node]) if(used[*it] == 0) solve(*it);
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
	int n,m;
	while(cin >> n >> m){
		forn(i,n) used[i] = 0;
		forn(i,m){
			int a,b; cin >> a >> b; a--;b--;
			g[a].pb(b);
			g[b].pb(a);
		}
		forn(i,n){
			total=0;
			if(used[i] == 0){
				solve(i);
				cout << i+1 << " " << total << '\n';
			}
		}
		forn(i,n) g[i].clear();
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

