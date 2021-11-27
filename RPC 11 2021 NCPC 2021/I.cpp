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


vector<int> cant;
int tam; 
string pNow;
string toBool(int num){
	string ret = "";
	forn(j,21){
		if(num & (1<<j)) ret+='1';
		else ret +='0';
	}
	return ret;
}

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
			forr(i, 1, sz(s)+1) {
				h[k][i] = (h[k][i-1] + p*s[i-1]) % MOD[k];
				pi[k][i] = (1LL * pi[k][i-1] * PI[k]) % MOD[k];
				vp[k][i] = p = (p*P) % MOD[k];
			}
		}
	}
	ll actVal = -1;
	ll get(int s, int e) { // get hash value of the substring [s, e)
		if(actVal > -1) return actVal;
		ll H[2];
		forn(i, 2) {
			H[i] = (h[i][e] - h[i][s] + MOD[i]) % MOD[i];
			H[i] = (1LL * H[i] * pi[i][s]) % MOD[i];
		}
		return actVal=(H[0]<<32)|H[1];
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
        return actVal=(h[0]<<32)|h[1];
    }
};

#define mod 1'000'000'007
ll expMod(ll b,ll e,ll m=mod) //O(log b)
{
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=q*q%m;
	return e%2? b*q%m : q;
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
	vector<int> a(n), b(n);
	set<int> val;
	unordered_map<int,int> real;
	forn(i,n) cin >> a[i];
	forn(i,n) cin >> b[i];
	forall(it,a) val.insert(*it);
	forall(it,b) val.insert(*it);
	int cont = 0;
	forall(it, val) real[*it] = cont++;
	forn(i,n) a[i] = real[a[i]], b[i]=real[b[i]]; // compresion de coordenadas
	tam=cont;
	cant.resize(tam);
	forn(i,tam) cant[i] = 1000005; // to handle negatives 
	string b10 = toBool(1000005);
	forn(i,tam) pNow+=b10;
	//~ cout << pNow << '\n';
	unordered_map<ll,int> rep;
	Hash hashNow = Hash(pNow);
	ll act = hashNow.get(0,tam*21);
	forn(i,n){
		if(a[i] != b[i]){
			cant[a[i]]++;
			cant[b[i]]--;
			string aux = toBool(cant[a[i]]);
			int st = a[i]*21;
			forr(j,st,st+21){
				if(aux[j-st] != pNow[j]){
					act = hashNow.getChanged(0, tam*21, j, aux[j-st], pNow[j]);
					pNow[j] = aux[j-st];
				}
			}
			aux = toBool(cant[b[i]]);
			st = b[i]*21;
			forr(j,st,st+21){
				if(aux[j-st] != pNow[j]){
					act = hashNow.getChanged(0, tam*21, j, aux[j-st], pNow[j]);
					pNow[j] = aux[j-st];
				}
			}
		}
		//~ cout << pNow << '\n';
		//~ forn(j,tam) cout << cant[j]-100005 << " ";
		//~ cout << '\n';
		//~ act = hashNow.get(0,tam*21);
		//~ cout << act << '\n';
		rep[act]++;
	}
	ll ans = 0;
	forall(it, rep){
		 if(it->snd > 1) ans = ((ans + expMod(2, it->snd) - it->snd - 1)%mod+mod)%mod;
		 //~ cout << it->snd << '\n';
	 }
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


