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

#define MAXN 100
int mx[MAXN][5][5], row[MAXN][5], col[MAXN][5];
bool used[MAXN][5][5];


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
	
	int tam = -1;
	vector<int> orden;
	string p; cin >> p;
	int valNow = 0;
	forn(i,sz(p)){
		if(p[i] == ','){orden.pb(valNow); valNow=0;}
		else {valNow*=10; valNow += p[i]-'0';
			if(i==sz(p)-1) orden.pb(valNow);}
	}
	tam = sz(orden);
	memset(used,0,sizeof(used));
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	forn(pos,MAXN) forn(i,5) forn(j,5) cin >> mx[pos][i][j];
	int winner = -1, val=-1;
	forn(act,tam){
		forn(pos, MAXN){
			int x=-1,y=-1;
			forn(i,5){
				forn(j,5){
					if(orden[act] == mx[pos][i][j]){x=i, y=j;}
					if(x!=-1) break;
				}
				if(x!=-1) break;
			}
			if(x==-1) continue;
			used[pos][x][y] = 1;
			row[pos][x]++;
			col[pos][y]++;
			cout << act << " " << x << " " << y << '\n';
			cout << "for " << pos << " " << row[pos][x] << " " << col[pos][y] << '\n';
			if(row[pos][x] == 5 || col[pos][y] == 5){ val = orden[act]; winner=pos; }
			if(winner!=-1) break;
		}
		if(winner!=-1) break;
	}
	int acum = 0;
	cout << winner << " " << val << '\n';
	forn(i,5){
		forn(j,5){
			if(!used[winner][i][j]) acum += mx[winner][i][j];
		}
	}
	cout << acum*val << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


