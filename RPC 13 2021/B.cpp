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

#define MAXN 30
bool used[MAXN];

struct Hash{
	size_t operator()(const ii &a)const
	{
		size_t s=hash<int>()(a.fst);
		return hash<int>()(a.snd)+0x9e3779b9+(s<<6)+(s>>2);
	}
	size_t operator()(const vector<int> &v)const
	{
		size_t s=0;
		for(auto &e : v) s^=hash<int>()(e)+0x9e3779b9+(s<<6)+(s>>2);
		return s;
	}
};

unordered_map<vector<int>, bool, Hash> dp;
int goal;
bool check(vector<ii>& v){
	bool ret = 1;
	forr(i,1,10){
		if(v[i-1].snd != v[i].fst) ret = 0;
	}
	ret &= ((v[0].fst == goal) && (v[0].fst == v.back().snd) );
	return ret;
}

bool correct(vector<ii>& v){
	bool ret = 1;
	forr(i,1,10){
		if(v[i-1].snd != v[i].fst) ret = 0;
	}
	return ret;
}

vector<ii> v;
int tsum = 0;
// bm = 0, now = 1, last = 2, sum = 3, par = 4
bool solve(vector<int> val){
	if(dp.count(val)) return dp[val];
	//~ cout << "WAT " << val[0] << '\n';
	if(__builtin_popcount(val[0]) == 10){
		ii aux = v[val[1]];
		ii auxst = v[val[3]];
		if(val[2] == 1) swap(aux.fst, aux.snd);
		if(val[4] == 1) swap(auxst.fst, auxst.snd);
		if(auxst.fst == aux.snd && aux.snd == goal) return 1;
		return 0;
	}
	
	//~ cout << "ENTRO ";
	//~ forall(it,val) cout << *it << " ";
	//~ cout << '\n';
	short ret = 0;
	forn(j, 10){
		if(((1<<j) & val[0]) == 0){
			if(val[1] == 10){
				vector<int> nxt;
				if(v[j].fst == goal){
					//~ cout << "ENTRO1 " << endl;
					nxt.pb(val[0]|(1<<j)); nxt.pb(j); nxt.pb(0); nxt.pb(j), nxt.pb(0);
					ret = solve(nxt);
				}
				nxt.clear();
				if(ret == 1) break;
				if(v[j].snd == goal){
					//~ cout << "ENTRO2 " << endl;
					nxt.pb(val[0]|(1<<j)); nxt.pb(j); nxt.pb(1); nxt.pb(j), nxt.pb(1);
					ret = solve(nxt);
				}
				if(ret == 1) break;
			}
			else{
				ii act = v[val[1]];
				//~ cout << act.fst << " " << act.snd << '\n';
				if(val[2] == 1) act = mp(act.snd, act.fst);
				vector<int> nxt;
				if(v[j].fst == act.snd){
					//~ cout << "ENTRO3 " << endl;
					nxt.pb(val[0]|(1<<j)), nxt.pb(j), nxt.pb(0), nxt.pb(val[3]), nxt.pb(val[4]);
					ret = solve(nxt);
				}
				nxt.clear();
				if(ret == 1) break;
				if(v[j].snd == act.snd){
					//~ cout << "ENTRO4 " << (1<<j) << endl;
					nxt.pb(val[0]|(1<<j)), nxt.pb(j), nxt.pb(1), nxt.pb(val[3]), nxt.pb(val[4]);
					ret = solve(nxt);
				}
				nxt.clear();
				if(ret == 1) break;
			}
			if(ret == 1) break;
		}
		if(ret == 1) break;
	}
	return dp[val] = ret;
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
	string p;
	while(cin >> p){
		bool valid = 0, perfect = 0, p10=0;
		vector<int> cant(7,0);
		set<ii> val;
		v.clear();
		tsum = 0;
		forn(i,sz(p)){
			ii aux = mp(p[i]-'0', p[i+1]-'0');
			v.pb(aux);
			if(aux.fst > aux.snd) swap(aux.fst, aux.snd);
			
			if(aux.fst != aux.snd){cant[aux.fst]++, cant[aux.snd]++;}
			else cant[aux.fst]++;
			tsum += aux.fst + aux.snd;
			val.insert(aux);
			i++;
		}
		if(sz(val) == 10 && correct(v)) valid = 1; // no repeated :), maybe should be a correct game too?
		int can = 0;
		forn(i,7) if(cant[i] == 7){goal=i; can=1;}
		if(can){
			p10 = check(v);
			if(p10 == true) perfect=true;
			else{
				vector<int> vnow;
				vnow.pb(0), vnow.pb(10), vnow.pb(0), vnow.pb(0), vnow.pb(0);
				perfect = (solve(vnow) > 0? 1 : 0);
			}
			cout << (valid? "YES" : "NO") << " " << (perfect? "YES" : "NO") << " " << (p10? "YES" : "NO") << '\n';
		}
		else cout << (valid? "YES" : "NO") << " " << (perfect? "YES" : "NO") << " " << (p10? "YES" : "NO") << '\n';
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}




