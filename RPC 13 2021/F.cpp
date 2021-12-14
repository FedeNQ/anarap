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

#define MAXN 2200 
char mx[MAXN][MAXN];
 
void solve(int tam, int x, int y){
	forn(i,tam){
		forn(j,tam){
			mx[i+x][j+y] = mx[i][j];
		}
	}
	return;
}
 
void recursivo(int tam){
	int x = 0, y=0+tam*2;
	solve(tam,x,y);
	x = tam, y = tam;
	solve(tam,x,y);
	x = tam*2, y = 0;
	solve(tam,x,y);
	x = tam*2, y = tam*2;
	solve(tam,x,y);
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
	
	int n; cin >> n;
	if(n==0) cout << "#\n";
	else{
		int tam = 1;
		forn(i, MAXN-2) forn(j,MAXN-2) mx[i][j] = '.';
		mx[0][0] = '#';
		while(n--){
			recursivo(tam);
			tam*=3;
		}
		forn(i,tam){
			forn(j,tam){
				if(mx[i][j] == '#') cout << mx[i][j];
				else cout << " ";
			}
			cout << '\n';
		}
	}
	
	
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


