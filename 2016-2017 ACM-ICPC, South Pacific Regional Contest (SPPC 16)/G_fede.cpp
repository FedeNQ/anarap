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

struct project{
	int imp, timee, bm;
};

bool comp(project a, project b){
	if(a.imp > b.imp) return true;
	return false;
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
	int cam, cr, pc;
	cin >> cam >> cr >> pc;
	vector<vector<project>> student(n);
	vector<int> total(n), actual(n, 0);
	forn(i,n){int k; cin >> k; total[i]=k; student[i].resize(k);}
	//~ cout << "XD" << endl;
	forn(i,n){
		forn(j, sz(student[i])){
			cin >> student[i][j].timee >> student[i][j].imp;
			student[i][j].imp *= -1;
			string s;
			getline(cin, s);
			istringstream is(s);
			student[i][j].bm=0;
			while(is >> s){
				if(s=="Camera") student[i][j].bm|=1;
				else if(s=="Camcorder") student[i][j].bm|=2;
				else student[i][j].bm|=4;
			}
		}
	}
	
	set<ii> towork[8];
	set<pair<ll,int>> finish;
	vector<ll> ans(n);
	int done = 0;
	forn(i,n) if(actual[i] < total[i]) towork[student[i][0].bm].insert(mp(student[i][0].imp, i));
	forn(i,n) if(actual[i] == total[i]){ done++; ans[i] = 0;}
	ll act=0;
	while(done<n){
		if(!finish.empty()){
			auto it = finish.begin();
			ll auxtime = it->fst;
			act=auxtime;
			int st = it->snd;
			int bitm = student[st][actual[st]].bm;
			if((bitm&1) == 1) cam++;
			if((bitm&2) == 2) cr++;
			if((bitm&4) == 4) pc++;
			actual[st]++;
			int now = actual[st];
			if(now < total[st]) towork[student[st][now].bm].insert(mp(student[st][now].imp, st));
			else {ans[st] = auxtime; done++;}
			
			finish.erase(it);
			it = finish.begin();
			while(!finish.empty() && auxtime==it->fst){
				st = it->snd;
				bitm = student[st][actual[st]].bm;
				if((bitm&1) == 1) cam++;
				if((bitm&2) == 2) cr++;
				if((bitm&4) == 4) pc++;
				actual[st]++;
				now = actual[st];
				if(now < total[st]) towork[student[st][now].bm].insert(mp(student[st][now].imp, st));
				else {ans[st] = auxtime; done++;}
				finish.erase(it);
				it = finish.begin();
			}
		}
		set<ii> letsgo;
		int bitm = 0;
		if(cam) bitm|=1; 
		if(cr) bitm|=2;
		if(pc) bitm|=4;
		forn(i,8){
			if(!towork[i].empty()){
				if((bitm&i) == i){
					auto it = towork[i].begin();
					letsgo.insert(*it);
				}
			}
		}
		while(!letsgo.empty()){
			auto it = letsgo.begin();
			int actst = it->snd;
			int nowst = actual[actst];
			int actbm = student[actst][nowst].bm;
			towork[actbm].erase(towork[actbm].begin());
			finish.insert(mp(student[actst][nowst].timee+act, actst));
			if(actbm&1) cam--;
			if(actbm&2) cr--;
			if(actbm&4) pc--;
			letsgo.clear();
			bitm = 0;
			if(cam) bitm|=1;
			if(cr) bitm|=2; 
			if(pc) bitm|=4;
			forn(i,8){
				if(!towork[i].empty()){
					if((bitm&i) == i){
						auto it2 = towork[i].begin();
						letsgo.insert(*it2);
					}
				}
			}
		}
	}
	forn(i,n) cout << ans[i] << " ";
	cout << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

