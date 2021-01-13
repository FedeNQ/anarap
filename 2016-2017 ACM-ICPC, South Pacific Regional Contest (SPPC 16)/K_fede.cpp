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
	forn(i, sz(p)) p[i] = tolower(p[i]);
	int cc=0, ck=0;
	string c = "kangaroo", k="kiwibird";
	forn(i, sz(c)){
		forn(j, sz(p)) if(c[i] == p[j]) cc++;
	}
	forn(i, sz(k)){
		forn(j, sz(p)) if(k[i] == p[j]) ck++;
	}
	if(ck > cc) cout << "Kiwis\n";
	else if(ck < cc) cout << "Kangaroos\n";
	else cout << "Feud continues\n";
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

