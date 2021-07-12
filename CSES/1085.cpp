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
#define MAXN 100
#else
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

ll a[MAXN];
int n, k; 

int need(ll maxi){
	int ans = 1;
	ll acum = 0;
	forn(i,n){
		if(acum + a[i] > maxi){
			ans++;
			acum = a[i];
		} 
		else acum += a[i];
	}
	return ans;
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
	
	cin >> n;
	cin >> k;
	forn(i,n) cin >> a[i];
	ll sum = 0;
	forn(i,n) sum+=a[i];
	ll L=0, R=sum+1;
	forn(i,n) L=max(L,a[i]);
	while(L<R){
		ll M = (L+R)/2;
		ll aux = need(M);
		if(aux <= k && aux!=-1) R=M;
		else L = M+1;
	}
	cout << L << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

