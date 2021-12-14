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

bool nice(string a){
	bool ret = 0;
	int n = sz(a);
	forn(i,n-1){
		if(a[i] == 'a' && a[i+1] == 'b') return 0;
		if(a[i] == 'c' && a[i+1] == 'd') return 0;
		if(a[i] == 'p' && a[i+1] == 'q') return 0;
		if(a[i] == 'x' && a[i+1] == 'y') return 0;
		if(a[i] == a[i+1]) ret = 1;
	}
	if(ret){
		int cont = 0;
		forn(i,n) if(a[i] == 'a'){cont++;}
		forn(i,n) if(a[i] == 'e'){cont++;}
		forn(i,n) if(a[i] == 'i'){cont++;}
		forn(i,n) if(a[i] == 'o'){cont++;}
		forn(i,n) if(a[i] == 'u'){cont++;}
		if(cont >= 3) return 1;
	}
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
	int ans =0;
	while(cin >> p){
		if(nice(p)) ans++;
		cout << nice(p) << '\n';
	}
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

