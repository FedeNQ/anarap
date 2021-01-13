#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
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
typedef pair<ll,int> ii;

struct project{
	int t,p,bm;
};

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n,available[3];
	 cin >> n;
	 forn(i,3) cin >> available[i];
	 vector<vector<project>> vv(n);
	 forn(i,n)
	 {
		 int k;
		 cin >> k;
		 vv[i].rsz(k);
	 }
	 forn(i,n)forn(j,sz(vv[i]))
	 {
		 cin >> skipws >> vv[i][j].t >> vv[i][j].p;
		 vv[i][j].bm = 0;
		 string x = "";
		 char c;
		 while(cin >> noskipws >> c)
		 {
			 if(c == ' ' || c == '\n')
			 {
				 if(x == "Camera") vv[i][j].bm |= 1;
				 if(x == "Camcorder") vv[i][j].bm |= 2;
				 if(x == "Computer") vv[i][j].bm |= 4;
				 x = "";
			 }
			 else x.pb(c);
			 if(c == '\n') break;
		 }
	 }
	 vector<int> vpos(n,0);
	 set<ii> waiting[8];
	 set<ii> working;
	 forn(i,n)
	 {
		// cout << "waiting " << i << ' ' << vv[i][0].p << ' ' << vv[i][0].bm << '\n';
		 waiting[vv[i][0].bm].insert(mp(-vv[i][0].p, i));
	 }
	 int done = 0;
	 vector<ll> ans(n);
	 ll curt = 0;
	 while(done < n)
	 {
		 int startsNow = -1, curp = 0;
		 if(working.empty() || curt < working.begin()->fst) forn(i,8) if(!waiting[i].empty())
		 {
			 bool good = true;
			 forn(j,3) if((i & (1<<j)) && available[j] == 0) good = false;
			 if(!good) continue;
			 ii aux = *waiting[i].begin();
			 aux.fst *= -1;
			 if(aux.fst > curp) curp = aux.fst, startsNow = aux.snd;
		 }
		 //cout << "starts " << startsNow << ' ' << curt << '\n';
		 if(startsNow != -1)
		 {
			 project pr = vv[startsNow][vpos[startsNow]];
			 waiting[pr.bm].erase(mp(-pr.p, startsNow));
			 working.insert(mp(curt+pr.t, startsNow));
			 forn(j,3) if(pr.bm & (1<<j))
			 {
				 assert(available[j] > 0);
				 available[j]--;
			 }
		 }
		 else
		 {
			 assert(!working.empty());
			 ii aux = *working.begin();
			 assert(curt <= aux.fst);
			 curt = aux.fst;
			 working.erase(working.begin());
			 int curbm = vv[aux.snd][vpos[aux.snd]].bm;
			 forn(j,3) if(curbm & (1<<j))
			 {
				 available[j]++;
			 }
			 vpos[aux.snd]++;
			 if(vpos[aux.snd] < sz(vv[aux.snd])) waiting[vv[aux.snd][vpos[aux.snd]].bm].insert(mp(-vv[aux.snd][vpos[aux.snd]].p, aux.snd));
			 else
			 {
				 ans[aux.snd] = curt;
				 done++;
			 }
		 }
	 }
	 forn(i,n)
	 {
		 if(i) cout << ' ';
		 cout << ans[i];
	 }
	 cout << '\n';
	 return 0;
}

