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
	
	string p; int cont=0;
	vector<pair<string, pair<char,int>>> v;
	map<char,ll> val;
	while( cin >> p){
		char reg='c', sx; int x=0;
		if(p[0] == 'j'){
			if(p != "jmp"){
				cin >> reg;
				cin >> sx;
			}
			cin >> sx;
			cin >> x;
			if(sx == '-') x*=-1;
		}
		else cin >> reg;
		
		v.pb(mp(p,mp(reg,x)));
		cont++;
	}
	int pos = 0;
	val['a']=1;
	while(pos >= 0 && pos<cont){
		if(v[pos].fst == "hlf"){
			val[v[pos].snd.fst]/=2;
			pos++;
		}
		else if(v[pos].fst == "tpl"){
			val[v[pos].snd.fst]*=3;
			pos++;
		}
		else if(v[pos].fst=="inc"){
			val[v[pos].snd.fst]++;
			pos++;
		}
		else if(v[pos].fst=="jmp"){
			pos+=v[pos].snd.snd;
		}
		else if(v[pos].fst=="jie"){
			if(val[v[pos].snd.fst]%2 == 0) pos+=v[pos].snd.snd;
			else pos++;
		}
		else if(v[pos].fst == "jio"){
			if(val[v[pos].snd.fst] == 1) pos+=v[pos].snd.snd;
			else pos++;
		}
	}
	cout << val['b'] << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


