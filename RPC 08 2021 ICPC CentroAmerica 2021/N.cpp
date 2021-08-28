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
	
	vector<int> grades(6);
	vector<int> tot(6);
	int t; cin >> t;
	forn(i,6) tot[i] = 0;
	forn(T,t){
		int n; cin >> n;
		forn(i,6) grades[i] = 0;
		forn(i,n) {char x; cin >> x; grades[x-'A']++; tot[x-'A']++;}
		cout << "A:" << grades[0] << " B:" << grades[1] << " C:" << grades[2];
		cout << " D: " << grades[3] << " E:" << grades[4] << " F:" << grades[5] << '\n';
	}
	cout << "TOTAL: ";
	forn(i,6) grades[i] = tot[i];
	cout << "A:" << grades[0] << " B:" << grades[1] << " C:" << grades[2];
	cout << " D: " << grades[3] << " E:" << grades[4] << " F:" << grades[5] << '\n';
		
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


