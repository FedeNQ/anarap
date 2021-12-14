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

int n = 8;
void increase(vector<int>& v){
	dforn(i,n){
		v[i]++;
		if(v[i] == 26) v[i] = 0;
		else break;
	}
	return;
}

bool check(vector<int>& v){
	bool ret = 0;
	forn(i,n){
		char aux = v[i] + 'a';
		if(aux == 'i' || aux == 'o' || aux == 'l') return 0;
	}
	forn(i,n-2){
		if(v[i]+1 == v[i+1] && v[i]+2 == v[i+2]) ret = 1;
	}
	if(ret == 0) return 0;
	int cont = 0;
	forn(i,n-1){
		if(v[i] == v[i+1]){i++; cont++;} 
	}
	if(cont >= 2) return 1;
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
	
	string p; cin >> p;
	vector<int> pass;
	forn(i,8) pass.pb(p[i]-'a');
	while(1){
		increase(pass);
		if(check(pass)) break;
	}
	forn(i,8) cout << char(pass[i]+'a');
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


