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

#define MAXN 100010
vector<int> g[MAXN];
int gr[MAXN], used[MAXN];
int n,m;

bool solve(){
	bool can = 0;
	queue<int> q;
	forn(i,n) if(gr[i] == 0){ used[i] = 1; q.push(i);}
	vector<int> ans;
	while(!q.empty()){
		int aux = q.front(); q.pop(); ans.pb(aux);
		used[aux] = 1;
		forall(it, g[aux]){
			gr[*it]--;
			if(gr[*it] == 0) q.push(*it);
		}
	}
	if(sz(ans) == n){
		forn(i,n){if(i) cout << " "; cout << ans[i]+1;}
		can=1;
		cout << '\n';
	}
	return can;
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
	cin >> n >> m;
	forn(i,m){
		int a,b; cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		gr[b]++;
	}
	if(!solve()) cout << "IMPOSSIBLE\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


