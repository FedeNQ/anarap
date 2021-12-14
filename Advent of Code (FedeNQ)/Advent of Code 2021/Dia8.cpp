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
	vector<vector<int>> v(10);
	v[0] = {0,1,2,4,5,6};
	v[1] = {2,5};
	v[2] = {0,2,3,4,6};
	v[3] = {0,2,3,5,6};
	v[4] = {1,2,3,5};
	v[5] = {0,1,3,5,6};
	v[6] = {0,1,3,4,5,6};
	v[7] = {0,2,5};
	v[8] = {0,1,2,3,4,5,6};
	v[9] = {0,1,2,3,5,6};
	
	ll ans = 0;
	while(cin >> p){
		vector<string> aux(10), v2(4);
		aux[0]=p;
		forr(i,1,10) cin >> aux[i];
		cin >> p;
		forn(i,4) cin >> v2[i];
		forn(i,10) sort(aux[i].begin(), aux[i].end());
		forn(i,4) sort(v2[i].begin(), v2[i].end());
		sort(aux.begin(), aux.end());
		vector<char> todo(7);
		todo = {'a','b','c','d','e','f','g'};
		do{
			vector<string> abc;
			forn(i,10){
				p="";
				forall(it, v[i]) p+=todo[*it];
				sort(p.begin(), p.end());
				abc.pb(p);
			}
			bool ok = true;
			forall(it,abc){
				bool ok2=false;
				forn(i,10) if(*it == aux[i]) ok2 = true;
				ok&=ok2;
				if(!ok) break;
			}
			if(ok){
				ll ret = 0;
				forall(it, v2){
					forn(i,10) if(*it == abc[i]){ret*=10; ret += i;}
				}
				ans+=ret;
				break;
			}
		}while(next_permutation(todo.begin(), todo.end()));
		
	}
	cout << ans << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


