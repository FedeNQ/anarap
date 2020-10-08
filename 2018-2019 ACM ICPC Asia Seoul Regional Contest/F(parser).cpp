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

int solve(string p){
	bool proper = 1;
	bool good = 1;
	vector<int> prt;
	deque<ii> open;
	bool lastwas = 1;
	bool letter = 0;
	open.pb(mp(0, 0));
	forn(i,sz(p)){
		if(!good) continue;
		else if(isalpha(p[i])){
			if(letter || !lastwas) good = 0;
			else{
				ii aux = open.back();
				open.pop_back();
				aux.fst++;
				if((aux.fst - aux.snd)!= 1) good = 0;
				else{
					open.pb(aux);
					letter = 1;
					lastwas = 0;
				}
			}
		}
		else if(p[i] == '%' || p[i] == '+' || p[i] == '-' || p[i] == '/' || p[i] == '*'){
			if(lastwas || !letter) good = 0;
			else{
				ii aux = open.back();
				open.pop_back();
				aux.snd++;
				if(aux.fst != aux.snd) good = 0;
				else{
					open.pb(aux);
					letter = 0;
					lastwas = 1;
				}
			}
		}
		else if(p[i] == '('){
			if(letter) good = 0;
			else open.pb(mp(0,0));
		}
		else if(p[i] == ')'){
			if(sz(open) == 1) good = 0;
			else{
				ii aux = open.back();
				open.pop_back();
				if(aux.fst-aux.snd != 1) good = 0;
				else{
					if(!(aux.fst == 2 && aux.snd == 1)) proper = 0;
					aux = open.back();
					open.pop_back();
					aux.fst++;
					open.pb(aux);
				}
			}
		}
	}
	int res = 2;
	if(sz(open)==1){
		ii aux = open.back();
		if(aux.fst-aux.snd != 1) good = 0;
		else if(!(aux.fst == 2 && aux.snd == 1)) proper = 0;
		
	}
	else good = 0;
	if(good){
		if(proper) res = 2;
		else res = 1;
	}
	else res = 0;
	return res;
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
	getline(cin, p);
	int rta = solve(p);
	if(rta == 0) cout << "error\n";
	else if(rta == 1) cout << "improper\n";
	else cout << "proper\n";
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
 
