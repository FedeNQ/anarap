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
	
	string p; cin >> p;
	int s = sz(p);
	map<string, int> aux;
	int tot = s/3;
	int pos = 0;
	int cont = 0;
	forn(i,3){
		cont=0;
		string nuevo = "";
		while(cont<tot){
			nuevo+=p[pos];
			cont++;
			pos++;
		}
		aux[nuevo]++;
		//~ cout << nuevo << '\n';
	}
	int correct = -1;
	forall(it, aux){
		correct = max(correct, it->snd);
	}
	forall(it, aux){
		if(it->snd == correct){ cout << it->fst << '\n'; break;}
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


