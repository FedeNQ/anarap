
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

int G[115][115];
int N;
void floyd(){//O(N^3)
forn(k, N) forn(i, N) if(G[i][k]!=INT_MAX) forn(j, N) if(G[k][j]!=INT_MAX)
	G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
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
	
	int n, m, q; cin >> n >> m >> q;
	N=n;
	forn(i,N+1) forn(j,N+1){
		if(i==j) G[i][j] = 0;
		else G[i][j] = INT_MAX;
	}
	forn(i,m){
		int a,b; 
		cin >> a >> b;
		int t; cin >> t;
		a--; b--;
		G[a][b] = min(G[a][b], t);
		G[b][a] = min(G[b][a], t);
	}
	floyd();
	forn(i,q){
		int a,b; cin >> a >> b;
		a--; b--;
		cout << G[a][b] << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

