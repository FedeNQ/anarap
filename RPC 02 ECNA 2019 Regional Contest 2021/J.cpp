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

#define EPS 1e-16

int n;
priority_queue<ll> procesar;
vector<pair<ll,ll>> a;

int solve(ll speed){
	int nopuedo = 0;
	while(!procesar.empty()) procesar.pop();
	ll hojas = 0;
	forn(i,n){
		hojas+= a[i].snd;
		procesar.push(a[i].snd);
		if(hojas > speed*a[i].fst){
			ll aux = procesar.top();
			procesar.pop();
			hojas -= aux;
			nopuedo++;
		}
	}
	return nopuedo;
}

int main()
{
	#ifdef ANARAP
		//~ freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> n >> k;
	a.resize(n);
	forn(i,n) cin >> a[i].snd >> a[i].fst;
	sort(a.begin(), a.end());
	ll acum =0;
	forn(i,n) acum+=a[i].snd;
	ll slow = 1, fast = acum+1;
	while(slow<fast){
		ll mid = (fast+slow)/2;
		int actual = solve(mid);
		if(actual > k) slow = mid+1;
		else if(actual<=k)fast = mid;
	}
	
	if(solve(slow) <= k) cout << slow << '\n';
	else cout << slow+1 << '\n';
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
