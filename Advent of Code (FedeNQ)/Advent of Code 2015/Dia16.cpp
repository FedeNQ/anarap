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
	
	map<string, int> stval;
	stval["children"] = 3;
	stval["cats"] = 7;
	stval["samoyeds"] = 2;
	stval["pomeranians"] = 3;
	stval["akitas"] = 0;
	stval["vizslas"] = 0;
	stval["goldfish"] = 5;
	stval["trees"] = 3;
	stval["cars"] = 2;
	stval["perfumes"] = 1;
	int correct = -1;
	string p;
	while(cin >> p){
		int now; cin >> now;
		int val;
		cin >> p;
		bool ret = 1;
		cin >> p >> val;
		p.pop_back();
		if(p == "cats" || p == "trees"){
			if(stval[p] >= val) ret =0;
		}
		else if(p=="pomeranians" || p=="goldfish"){
			if(stval[p] <= val) ret =0;
		}
		else if(stval[p] != val) ret = 0;
		cin >> p;
		cin >> p >> val;
		p.pop_back();
		if(p == "cats" || p == "trees"){
			if(stval[p] >= val) ret =0;
		}
		else if(p=="pomeranians" || p=="goldfish"){
			if(stval[p] <= val) ret =0;
		}
		else if(stval[p] != val) ret = 0;
		cin >> p;
		cin >> p >> val;
		p.pop_back();
		if(p == "cats" || p == "trees"){
			if(stval[p] >= val) ret =0;
		}
		else if(p=="pomeranians" || p=="goldfish"){
			if(stval[p] <= val) ret =0;
		}
		else if(stval[p] != val) ret = 0;
		if(ret) correct = now;
	}
	cout << correct << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


