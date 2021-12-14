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

#define MAXN 1000
int mx[MAXN][MAXN];

ii get(string p){
	ii ret = mp(-1,-1);
	int val = 0;
	forn(i,sz(p)){
		if(p[i] == ','){
			ret.fst = val;
			val=0;
		}
		else{
			val*=10;
			val += p[i]-'0';
			if(i==sz(p)-1) ret.snd=val;
		}
	}
	return ret;
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
	
	string p1, mas, p2;
	while(cin >> p1 >> mas >> p2){
		ii v1 = get(p1), v2 = get(p2);
		if(v1.fst > v2.fst || v1.snd > v2.snd) swap(v1,v2);
		if(v1.fst == v2.fst || v1.snd == v2.snd){
			//~ cout << v1.fst << " " << v1.snd << " " << v2.fst << " " << v2.snd << '\n';
			if(v1.fst == v2.fst){
				forr(j,v1.snd,v2.snd+1) mx[v1.fst][j]++;
			}
			else{
				forr(i,v1.fst,v2.fst+1) mx[i][v1.snd]++;
			}
		}
		else{
			if(v1.fst > v2.fst) swap(v1,v2);
			while(1){
				mx[v1.fst][v1.snd]++;
				//~ cout << v1.fst << " " << v1.snd << " " << v2.fst << " " << v2.snd << '\n';
				if(v1 == v2) break;
				v1.fst++; 
				if(v1.snd<v2.snd) v1.snd++;
				else v1.snd--;
			}
		}
	}
	int cont = 0;
	forn(i,MAXN){
		forn(j,MAXN){
			if(mx[i][j] >= 2) cont++;
		}
	}
	//~ forn(i,MAXN){
		//~ forn(j,MAXN){
			//~ cout << mx[i][j] << " ";
		//~ }
		//~ cout << '\n';
	//~ }
	cout << cont << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


