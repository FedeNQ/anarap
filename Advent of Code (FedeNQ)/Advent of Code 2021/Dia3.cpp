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
	
	int cota = 12;
	string p; int tot=0;
	vector<int> cont(cota,0);
	vector<string> todos;
	vector<int> pos, nxt;
	while(cin >> p){todos.pb(p);pos.pb(tot); tot++;}
	
	ll pot2 = 1, gamma=0, eps=0;
	int posGamma=0, posEps=0;
	forn(i,cota){
		nxt.clear();
		int c0 = 0, c1 = 0;
		forall(it, pos){
			if(todos[*it][i] == '1') c1++; 
			else c0++;
		}
		forall(it, pos){
			if(c1 >= c0 && todos[*it][i] == '1') nxt.pb(*it);
			else if(c0 > c1 && todos[*it][i] == '0') nxt.pb(*it);
		}
		pos.clear();
		forall(it, nxt) pos.pb(*it);
	}
	assert(sz(pos)==1);
	posGamma = pos[0];
	pos.clear();
	forn(i,tot) pos.pb(i);
	forn(i,cota){
		nxt.clear();
		int c0 = 0, c1 = 0;
		forall(it, pos){
			if(todos[*it][i] == '1') c1++; 
			else c0++;
		}
		forall(it, pos){
			if(c1 >= c0 && todos[*it][i] == '0') nxt.pb(*it);
			else if(c0 > c1 && todos[*it][i] == '1') nxt.pb(*it);
		}
		pos.clear();
		forall(it, nxt) pos.pb(*it);
		if(sz(pos) == 1) break;
	}
	//~ assert(sz(pos)==1);
	posEps = pos[0];
	//~ cout << todos[posGamma] << " " << todos[posEps] << '\n';
	
	dforn(i,cota){
		if(todos[posGamma][i] == '1') gamma += pot2;
		if(todos[posEps][i] == '1') eps += pot2;
		pot2 = pot2*2LL;
	}
	cout << gamma*eps << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


