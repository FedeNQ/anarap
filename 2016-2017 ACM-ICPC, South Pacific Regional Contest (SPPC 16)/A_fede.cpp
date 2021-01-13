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

ii solve(int goal){
	int x=0, y=0, actual=1, cont, move=2;
	bool continuar = 1;
	while(continuar){
		cont=0;
		if(actual==goal) break;
		if(cont==0) {actual++, y--, move--;}
		if(actual==goal) break;
		while(cont < 4){
			//~ cout << actual << " " << goal << " " << move << '\n';
			if(actual+move>=goal){
				if(cont==0) x+=goal-actual;
				else if(cont==1) y+=goal-actual;
				else if(cont==2) x-=goal-actual;
				else y-=goal-actual;
				continuar = 0;
				break;
			}
			else{
				if(cont==0) x+=move;
				else if(cont==1) y+=move;
				else if(cont==2) x-=move;
				else y-=move;
				actual+=move;
			}
			if(cont == 0) move++;
			cont++;
		}
		move+=2;
	}
	
	return mp(x, y);
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
	int a,b; cin >> a >> b;
	ii ca = solve(a), cb = solve(b);
	//~ cout << ca.fst << " " << ca.snd << " " << cb.fst << " " << cb.snd << '\n';
	cout << abs(ca.fst-cb.fst)+abs(ca.snd-cb.snd) << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
