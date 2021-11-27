#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
#define forr(i,a,b) for(ll i=(a);i<(b);i++)
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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll tipo;

#define MAXN 400010
#define operacion1(x, y) min(x, y)
#define operacion2(x, y) max(x, y)


const tipo neutro1=LLONG_MAX;
struct RMQmin {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro1;
	}
	void updall() {dforn(i, sz) t[i]=operacion1(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro1;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion1(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion1(t[p*2], t[p*2+1]);
		}
	}
};

const tipo neutro2=LLONG_MIN;
struct RMQmax {
	int sz;
	tipo t[4*MAXN];
	tipo &operator[](int p) {return t[sz+p];}
	void init(int n) {//O(nlgn)
		sz = 1 << (32 - __builtin_clz(n));
		forn(i, 2*sz) t[i] = neutro2;
	}
	void updall() {dforn(i, sz) t[i]=operacion2(t[2*i], t[2*i+1]);} //O(n)
	tipo get(int i, int j) {return get(i,j,1,0,sz);}
	tipo get(int i, int j, int n, int a, int b) {//O(lgn), [i, j)
		if(j<=a || i>=b) return neutro2;
		if(i<=a && b<=j) return t[n];//n = node of range [a,b)
		int c = (a+b)/2;
		return operacion2(get(i, j, 2*n, a, c), get(i, j, 2*n+1, c, b));
	}
	void set(int p, tipo val) {//O(lgn)
		p += sz;
		while(p>0 && t[p]!=val) {
			t[p] = val;
			p /= 2;
			val = operacion2(t[p*2], t[p*2+1]);
		}
	}
};


int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,c; cin>>n>>c;
	RMQmin stmin; stmin.init(n);
	RMQmax stmax; stmax.init(n);
	vector<ll> arr(n),m(n);
	vector<ii> oarr(n); 
	forn(i,n){
		cin>>arr[i];
		oarr[i]={arr[i],i};
	}
	sort(oarr.begin(),oarr.end());
	forn(i,n) m[oarr[i].snd]=i;
	
	forn(i,n){
		stmin.set(m[i],arr[i]-c*(i+1));
		stmax.set(m[i],arr[i]+c*(i+1));
		ll mini = stmin.get(0,m[i]);
		ll maxi = stmax.get(m[i],n+1);
		cout << max(arr[i]-mini,maxi-arr[i]) - c*(i+1);
		if(i!=n-1) cout<<" ";
	}
	cout << "\n";
	
	return 0;
}




