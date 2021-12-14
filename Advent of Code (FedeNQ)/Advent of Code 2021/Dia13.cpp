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

#define MAXN 1400
char mx[MAXN][MAXN];

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
	
	int a,b; char c;
	int n = 983; // 983
	int maxi = -1;
	forn(i,1390){
		forn(j,1390){
			mx[i][j] = '.';
		}
	}
	forn(i,n){
		cin >> a >> c >> b;
		mx[a][b] = '#';
	}
	string p;
	ll cont =0;
	int cotaY = 1380, cotaX=1380;
	forn(x,12){
		cin >> p >> p;
		char o;
		cin >> o >> c;
		int val; cin >> val;
		if(o == 'y'){
			int oth = val*2;
			cotaY = val;
			forr(j,0,val){
				forn(i,1350){
					if(mx[i][j] == '#' || mx[i][oth] == '#') mx[i][j] = '#';
				}
				oth--;
			}
		}
		else{
			cotaX = val;
			int oth = val*2;
			forr(i,0,val){
				forn(j,1350){
					if(mx[i][j] == '#' || mx[oth][j] == '#') mx[i][j] = '#';
				}
				oth--;
			}
		}
	}
	cout << cotaX << " " << cotaY << '\n';
	forn(j,cotaY+2){
		forn(i,cotaX+2){
			cout << mx[i][j];
		}
		cout << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


