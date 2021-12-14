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

#define l 2503

map<string, ll> vel, tim, rest, pos, score;
vector<string> todos;
ll winner(){
	ll ret = 0;
	forr(now,0,l){
		ll act = 0;
		forall(it,todos){
			ll val = now%(tim[*it]+rest[*it]);
			if(val < tim[*it]) pos[*it]+=vel[*it];
			act = max(pos[*it], act);
		}
		forall(it,todos) if(pos[*it] == act) score[*it]++;
		//~ forall(it,todos) cout << pos[*it] << " ";
		//~ cout << '\n';
	}
	//~ forall(it,todos){
		//~ cout << score[*it] << " ";
		//~ cout << '\n';
		
	//~ }
	forall(it,todos) ret=max(ret,score[*it]);
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
	
	string a, c;
	int v,t,r;
	//~ map<string, ll> ans;
	while(cin >> a){
		cin >> c >> c >> v >> c >> c >> t >> c >> c >> c >> c >> c >> c >> r >> c;
		vel[a] = v, tim[a] = t, rest[a] = r;
		todos.pb(a);
	}
	
	cout << winner() << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


