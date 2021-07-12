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
typedef pair<ii,int> iii;

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
	vector<iii> a(n);
	forn(i,n){cin >> a[i].fst.fst >> a[i].fst.snd; a[i].snd = i;}
	sort(a.begin(), a.end());
	set<int> room;
	priority_queue<ii> onUse;
	vector<int> ans(n);
	int nxt = 0;
	forn(i,n){
		while(!onUse.empty()){
			ii aux = onUse.top();
			//~ cout << "HOLA " << i << " " << a[i].fst.fst << " " << aux.fst << '\n';
			if(a[i].fst.fst > (aux.fst * -1)){room.insert(aux.snd); onUse.pop();}
			else break;
		}
		if(room.empty()) {ans[a[i].snd] = nxt++; onUse.push(mp(a[i].fst.snd * -1, ans[a[i].snd] ));}
		else{
			auto it = room.begin();
			ans[a[i].snd] = *it;
			onUse.push(mp(a[i].fst.snd * -1, ans[a[i].snd] ));
			room.erase(it);
		}
	}
	cout << nxt << '\n';
	forn(i,n){ 
		if(i) cout << " "; 
		cout << ans[i]+1;
	}
	cout << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


