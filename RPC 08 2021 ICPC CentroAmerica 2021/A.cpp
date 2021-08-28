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
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct Hash {
	//P must be a prime number, could be randomly generated,
	//sometimes is good to make it close to alphabet size
	int P=1777771, MOD[2], PI[2];
	vector<int> h[2], pi[2];
	vector<ll> vp[2]; //Only used if getChanged is used (delete it if not)
	Hash(string& s) {
		//MOD[i] must be a prime of this order, could be randomly generated
		MOD[0]=999727999; MOD[1]=1070777777;
		//PI[i] = P^-1 % MOD[i]
		PI[0]=325255434; PI[1]=10018302;
		forn(k, 2)
			h[k].rsz(s.size()+1), pi[k].rsz(s.size()+1), vp[k].rsz(s.size()+1);
		forn(k, 2) {
			h[k][0] = 0; pi[k][0] = vp[k][0] = 1;
			ll p=1;
			forr(i, 1, s.size()+1) {
				h[k][i] = (h[k][i-1] + p*s[i-1]) % MOD[k];
				pi[k][i] = (1LL * pi[k][i-1] * PI[k]) % MOD[k];
				vp[k][i] = p = (p*P) % MOD[k];
			}
		}
	}
	ll get(int s, int e) { // get hash value of the substring [s, e)
		ll H[2];
		forn(i, 2) {
			H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
			H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
		}
		return (H[0]<<32)|H[1];
	}
	//get hash value of [s, e) if origVal in pos is changed to val
	//Assumes s <= pos < e. If multiple changes are needed, 
    //do what is done in the for loop for every change
    ll getChanged(int s, int e, int pos, int val, int origVal) {
        ll hv = get(s,e), h[2];
        h[1] = hv & ((1LL<<32)-1);
        h[0] = hv >> 32;
        forn(i, 2)
        	h[i] = (h[i] + vp[i][pos] * (val - origVal + MOD[i])) % MOD[i];
        return (h[0]<<32)|h[1];
    }
};

bool cmp(string &a, string &b)
{
	if(sz(a) != sz(b)) return sz(a) > sz(b);
	return a < b;
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
	int n;
	cin >> n;
	vector<string> v(n);
	forn(i,n) cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	map<ll,ll> m;
	ll ans = 0;
	forn(i,n)
	{
		int cnt = 1;
		while(i+1 < n && v[i+1] == v[i]) i++, cnt++;
		ans += cnt*(cnt-1);
		Hash h(v[i]);
		ans += m[h.get(0, sz(v[i]))];
		forn(k,sz(v[i])) m[h.get(0, k+1)]++;
	}
	cout << ans << '\n';
	return 0;
}
