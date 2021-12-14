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
typedef pair<string,string> s2;
typedef pair<s2, string> s3;

int get(string p){
	int ret = 0;
	forall(it, p){
		ret*=10;
		ret += *it-'0';
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
	
	string a,b,c,d,e;
	map<string, int> val;
	vector<s2> stos, nega;
	vector<s3> opor, opand, ls, rs;
	val["b"] = 3176;
	
	while(cin >> a){
		cin >> b;
		if(b == "->"){
			cin >> c;
			if(a == "44430") continue;
			if(a[0]>='0' && a[0]<='9') val[c] = get(a);
			else stos.pb(mp(a,c));
		}
		else{
			cin >> c >> d;
			if(a=="NOT"){
				if(val.count(b)) val[d] = val[b] ^ ((1<<16)-1);
				else nega.pb(mp(b,d));
			}
			else{
				cin >> e;
				assert(e[0]>='a' && e[0]<='z'); 
				if(b=="RSHIFT"){
					assert(a[0] >= 'a' && a[0]<='z');
					assert(c[0] >= '0' && c[0]<='9');
					if(val.count(a)) val[e] = val[a]>>get(c);
					else rs.pb(mp(mp(a,c),e));
				}
				else if(b =="LSHIFT"){
					assert(a[0] >= 'a' && a[0]<='z');
					assert(c[0] >= '0' && c[0]<='9');
 					if(val.count(a)) val[e] = val[a]<<get(c);
					else ls.pb(mp(mp(a,c),e));
				}
				else{
					if(a[0] >= '0' && a[0]<='9' && c[0]>='0' && c[0]<='9'){
						int vala = get(a), valc = get(c);
						if(b == "OR") val[e] = vala|valc;
						else val[e] = vala&valc;
					}
					else if(a[0]>='0' && a[0]<='9'){
						int vala = get(a);
						if(val.count(c)){
							if(b == "OR") val[e] = vala|val[c];
							else val[e] = vala&val[c];
						}
						else{
							if(b == "OR") opor.pb(mp(mp(a,c), e));
							else opand.pb(mp(mp(a,c), e));
						}
					}
					else if(c[0]>='0' && c[0] <= '9'){
						int valc = get(c);
						if(val.count(a)){
							if(b == "OR") val[e] = val[a]|valc;
							else val[e] = val[a]&valc;
						}
						else{
							if(b == "OR") opor.pb(mp(mp(a,c), e));
							else opand.pb(mp(mp(a,c), e));
						}
					}
					else{
						if(val.count(a) && val.count(c)){
							if(b == "OR") val[e] = val[a]|val[c];
							else val[e] = val[a]&val[c];
						}
						else{
							if(b == "OR") opor.pb(mp(mp(a,c), e));
							else opand.pb(mp(mp(a,c), e));
						}
					}
				}
			}
		}
	}
	while(sz(stos)+sz(nega)+sz(opand)+sz(opor)+sz(ls)+sz(rs) > 0){
		vector<s2> nxt;
		vector<s3> nxtt;
		forall(it, stos){
			if(val.count(it->fst)) val[it->snd] = val[it->fst];
			else nxt.pb(*it);
		}
		stos.clear();
		forall(it,nxt) stos.pb(*it);
		nxt.clear();
		forall(it, nega){
			if(val.count(it->fst)) val[it->snd] = val[it->fst] ^ ((1<<16)-1);
			else nxt.pb(*it);
		}
		nega.clear();
		forall(it,nxt) nega.pb(*it);
		nxt.clear();
		
		forall(it, opand){
			if(it->fst.fst[0] <= '9' && it->fst.fst[0] >= '0'){
				if(val.count(it->fst.snd)) val[it->snd] = get(it->fst.fst) & val[it->fst.snd];
				else nxtt.pb(*it);
			}
			else if(it->fst.snd[0] <= '9' && it->fst.snd[0] >= '0'){
				if(val.count(it->fst.fst)) val[it->snd] = val[it->fst.fst] & get(it->fst.snd);
				else nxtt.pb(*it);
			}
			else{
				if(val.count(it->fst.fst) && val.count(it->fst.snd)) val[it->snd] = val[it->fst.fst]&val[it->fst.snd];
				else nxtt.pb(*it);
			}
		}
		opand.clear();
		forall(it,nxtt) opand.pb(*it);
		nxtt.clear();
		forall(it, opor){
			if(it->fst.fst[0] <= '9' && it->fst.fst[0] >= '0'){
				if(val.count(it->fst.snd)) val[it->snd] = get(it->fst.fst) | val[it->fst.snd];
				else nxtt.pb(*it);
			}
			else if(it->fst.snd[0] <= '9' && it->fst.snd[0] >= '0'){
				if(val.count(it->fst.fst)) val[it->snd] = val[it->fst.fst] | get(it->fst.snd);
				else nxtt.pb(*it);
			}
			else{
				if(val.count(it->fst.fst) && val.count(it->fst.snd)) val[it->snd] = val[it->fst.fst]|val[it->fst.snd];
				else nxtt.pb(*it);
			}
		}
		opor.clear();
		forall(it,nxtt) opor.pb(*it);
		nxtt.clear();
		
		forall(it, ls){
			if(val.count(it->fst.fst)) val[it->snd] = val[it->fst.fst] << get(it->fst.snd);
			else nxtt.pb(*it);
		}
		ls.clear();
		forall(it,nxtt) ls.pb(*it);
		nxtt.clear();
		
		forall(it, rs){
			if(val.count(it->fst.fst)) val[it->snd] = val[it->fst.fst] >> get(it->fst.snd);
			else nxtt.pb(*it);
		}
		rs.clear();
		forall(it,nxtt) rs.pb(*it);
		nxtt.clear();
		
	}
	
	forall(it,val) cout << it->fst << ": " << it->snd << '\n';
	//~ cout << val["a"] << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


