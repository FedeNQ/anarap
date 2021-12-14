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

#define MAXN 1001
int mx[MAXN][MAXN];

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
		if(p=="turn") cin >> p;
		char c; string p2;
		int x,y; cin >> x >> c >> y;
		cin >> p2;
		int gx, gy; cin >> gx >> c >> gy;
		forr(i,x,gx+1){
			forr(j,y,gy+1){
				if(p=="on") mx[i][j]++;
				else if(p=="off") mx[i][j]=max(mx[i][j]-1,0);
				else mx[i][j]+=2;
			}
		}
	}
	int ans = 0;
	forn(i,MAXN-1) forn(j,MAXN-1) ans+=mx[i][j];
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

