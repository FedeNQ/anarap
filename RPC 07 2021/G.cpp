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

int getNumber(string p){
	int ret = 0;
	forr(i,1,sz(p)){
		ret*=10;
		ret+=(p[i]-'0');
	}
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
	int x; cin >> x;
	vector<int> orden(n);
	vector<int> nuevo;
	forn(i,n) orden[i] = i+1;
	forn(_,x){
		string tm1, tm2; cin >> tm1 >> tm2;
		int e1 = getNumber(tm1), e2 = getNumber(tm2);
		int p1 = -1, p2=-1;
		forn(i,n){
			if(e1 == orden[i]){p1 = i; break;}
			if(e2 == orden[i]){p2 = i;}
		}
		if(p2 == -1) continue;
		else{
			forn(i, p1+1){if(orden[i] != e2) nuevo.pb(orden[i]);}
			nuevo.pb(e2);
			forr(i,p1+1, n) nuevo.pb(orden[i]);
			orden.clear();
			forn(i,n) orden.pb(nuevo[i]);
			nuevo.clear();
		}
	}
	forn(i,n){
		if(i) cout << " ";
		cout << "T" << orden[i];
	}
	cout << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

