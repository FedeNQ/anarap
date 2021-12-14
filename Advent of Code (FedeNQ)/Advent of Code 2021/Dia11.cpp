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

#define MAXN 11
int mx[MAXN][MAXN];
bool used[MAXN][MAXN];

int d[3] = {-1,0,1};

bool valid(int a, int b){
	if(a>=0 && a<10 && b>=0 && b<10) return 1;
	return 0;
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
	int cont = 0;
	while(cin >> p){
		forn(j,sz(p)) mx[cont][j] = p[j]-'0';
		
		cont++;
	}
	ll ans = 0;
	int act = 1;
	while(1){
		ans=0;
		memset(used,0,sizeof(used));
		queue<ii> q;
		forn(i,10) forn(j,10)mx[i][j]++;
		forn(i,10){
			forn(j,10){
				if(mx[i][j] >= 10){
					used[i][j] = 1;
					q.push(mp(i,j));
				}
			}
		}
		while(!q.empty()){
			ii aux = q.front();
			q.pop();
			forn(dx, 3){
				forn(dy,3){
					if(d[dx] == d[dy] && d[dx] == 0) continue;
					int x = aux.fst+d[dx], y = aux.snd+d[dy];
					if(valid(x,y) && !used[x][y]){
						mx[x][y]++;
						if(mx[x][y] >= 10){
							used[x][y]=1;
							q.push(mp(x,y));
						}
					}
				}
			}
		}
		forn(i,10) forn(j,10) if(used[i][j]) ans++;
		if(ans == 100) break;
		forn(i,10) forn(j,10) if(mx[i][j] >= 10) mx[i][j] = 0;
		act++;
	}
	cout << act << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


