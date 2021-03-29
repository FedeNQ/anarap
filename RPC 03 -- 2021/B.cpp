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
	
	
	vector<ll> acum(6);
	forn(i,6)cin >> acum[i];
	ll maxi = 0;
	acum[0]*=1;
	acum[1]*=5;
	acum[2]*=10;
	acum[3]*=20;
	acum[4]*=50;
	acum[5]*=100;
	forn(i,6) maxi = max(maxi, acum[i]);
	if(acum[5] == maxi) cout << 100 << "\n";
	else if(acum[4] == maxi) cout << 50 << "\n";
	else if(acum[3] == maxi) cout << 20 << "\n";
	else if(acum[2] == maxi) cout << 10 << "\n";
	else if(acum[1] == maxi) cout << 5 << "\n";
	else cout << 1 << "\n";
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

