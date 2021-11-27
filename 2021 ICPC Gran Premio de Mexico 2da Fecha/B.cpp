#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#ifdef ANARAP
#define MAXM 2000
#else
#define MAXM 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define MOD 998244353

ll expMod(ll b,ll e) //O(log b)
{
	if(!e) return 1;
	ll q=expMod(b,e/2);
	q=q*q%MOD;
	return e%2? b*q%MOD : q;
}

ll inverso(ll x) //O(log x)
{
	return expMod(x, MOD-2);//si mod es primo
}

ll vways[MAXM], acum[MAXM];
ll fac[MAXM], ifac[MAXM];

inline ll comb(int n, int k)
{
	assert(n >= k);
	return fac[n] * ifac[k]%MOD * ifac[n-k]%MOD;
}

inline int toInt(string s)
{
    int p = sz(s);
    int ret = 0 ;
    forn(i,p){
        ret *= 10;
        ret += s[i]-'0';
    }
	return ret;
}

inline string toString(int x)
{
	stringstream ss;
	ss << x;
	string ret;
	ss >> ret;
	return ret;
}

int cgoup = 0;
void goup(string &s, bool fst)
{
	if(s[0] == '9')
	{
		s[0] = '0';
		s = "1"+s;
	}
	else s[0]++;
	if(fst){cgoup++; forr(i,1,sz(s)) s[i] = '0';}
	assert(s[0] > '0');
}

void pre(){
	fac[0] = 1;
	forr(i,1,MAXM-2) fac[i] = (fac[i-1]*i)%MOD;
	ifac[MAXM-3] = inverso(fac[MAXM-3]);
	dforn(i, MAXM-3) ifac[i] = (ifac[i+1]*(i+1))%MOD;
	return;
}

void build(int n, int m)
{
	pre();
	vector<ll> vaux(m+1);
	vaux[m] = 1;
	dforn(i,m) vaux[i] = vaux[i+1]*(n-1)%MOD;
	forn(i,m+1)
	{
		//vways[i] = fways(n-1, m-i);
		vways[i] = vaux[i]*comb(m,i)%MOD;
		//cout << vways[i] << ' ';
		acum[i+1] = (acum[i]+vways[i])%MOD;
	}
	//cout << '\n';
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	if(n == 1)
	{
		int x;
		cin >> x;
		x += m;
		string s = toString(x);
		forr(i,1,10) if(s[0] == i+'0') cout << "1\n"; else cout << "0\n";
		return 0;
	}
	vector<int> v(n);
	build(n, m);
	vector<ll> ans(10,0);
	forn(i,n)
	{
		string scur;
		cin >> scur;
		int used = 0, togo = m+1;
		//cout << "\nfor pos " << i << ", " << scur << ":\n";
		int cont = 0;
		cgoup=0;
		while(togo > 0)
		{
		    cont++;
		    assert(cont < 70);
			int pos = scur[0]-'0';
			int cur = toInt(scur);
			goup(scur, used == 0);
			int nxt = min(cur+togo, toInt(scur));
			int k = nxt-cur;
			//cout << cur << ' ' << nxt << ' ' << k << ' ' << pos << '\n';
			//cout << "add " << used << ' ' << used+k << ' ' << acum[used+k]-acum[used] << '\n';
			ans[pos] = (ans[pos]+acum[used+k]-acum[used]+MOD)%MOD;
			used += k;
			togo -= k;
		}
		assert(cgoup < 100);
	}
	ll aux = 1;
	forn(i,m) aux = aux*n%MOD;
	//forr(i,1,10) cout << ans[i] << ' ' << fways(n,m) << ' ' << ans[i]*inverso(fways(n,m))%MOD << '\n';
	forr(i,1,10) cout << ans[i]*inverso(aux)%MOD << '\n';
	return 0;
}
