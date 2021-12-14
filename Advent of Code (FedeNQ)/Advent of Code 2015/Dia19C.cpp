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
	
	string p; cin >> p;
	int elem = 0;
	int ans = 0; 
	forn(i,sz(p)){
		if(p[i] == 'Y') elem++;
		else if(i+1 < sz(p) && p[i] == 'A' && p[i+1] == 'r'){ elem++; i++;}
		else if(i+1 < sz(p) && p[i] == 'R' && p[i+1] == 'n'){ elem++; i++;}
		else{
			if(p[i] == 'A' || p[i] == 'C' || p[i] == 'M' || p[i] == 'T' || p[i] == 'S'){
				elem++;
				i++;
			}
			else elem++;
		}
	}
	forn(i,sz(p)){
		if(p[i] == 'Y') elem-=2;
		else if(i+1 < sz(p) && p[i] == 'A' && p[i+1] == 'r'){ elem--; i++;}
		else if(i+1 < sz(p) && p[i] == 'R' && p[i+1] == 'n'){ elem--; i++;}
	}
	cout << elem-1 << '\n';
	cout << ans-2 << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


