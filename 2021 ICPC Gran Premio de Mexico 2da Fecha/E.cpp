
// ANARAP 💙💛💙
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

ll getNumber(string p){
	ll ret = 0;
	forn(i,sz(p)-1){
		ret*=10;
		ret+=(p[i]-'0');
	}
	//~ cout << ret << '\n';
	char auxp = p.back();
	if(auxp == 'G') ret = ret * 1024;
	else if(auxp == 'T') ret = ret * 1024 * 1024;
	return ret;
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
	
	int n; cin >> n;
	string p; cin >> p;
	ll cap = getNumber(p);
	//~ cout << cap << '\n';
	vector<ll> v(n), acum(n+1);
	forn(i,n) cin >> v[i];
	acum[0] = 0;
	forn(i,n) acum[i+1] = acum[i]+v[i];
	//~ forn(i,n+1) cout << acum[i] << " ";
	//~ cout << '\n';
	int cota = n;
	int cota2 = -1;
	forn(i,n){
		int L=1, R=n;
		if(i+cota > n) break;
		while(L<R){
			int M = (L+R+1)/2;
			if(i+M > n) R = M-1;
			else if((acum[i+M] - acum[i]) <= cap) L=M;
			else R = M-1;
		}
		cota = min(cota, L);
	}
	forn(i,n){
		if(i+cota+1 > n || i+cota > n) break;
		//~ cout << i << " " << acum[i+cota+1] << " " << acum[i] << " " << acum[i+cota+1]-acum[i] << endl;
		if(acum[i+cota+1] - acum[i] > cap){ cota2=i+1; break;}
	}
	cout << cota << " " << cota2 << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


