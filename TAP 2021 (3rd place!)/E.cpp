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
	
	int t; cin >> t;
	queue<int> v0, v1;
	forn(T,t){
		int x; cin >> x;
		int d; cin >> d;
		if(d) v1.push(x);
		else v0.push(x);
	}
	int act = -1,  ans = -1;
	while(!v0.empty() || !v1.empty()){
		if(act==-1){
			if(v0.empty()){
					ans = max(ans+10, v1.front()+10);
					v1.pop();
					act=1;
			}
			else if(v1.empty()){
					ans = max(ans+10, v0.front()+10);
					v0.pop();
					act = 0;
			}
			else{
				if(v0.front() < v1.front()){
					act = 0; ans = max(ans+10,v0.front()+10);
					v0.pop();
				}
				else{
					act = 1; ans = max(ans+10,v1.front()+10);
					v1.pop();
				}
			}
		}
		else if(act == 0){
			while(!v0.empty()){
				if(v0.front() < ans){
					ans = max(ans, v0.front()+10);
					v0.pop();
				}
				else break;
			}
			act = -1;
		}
		else{
			while(!v1.empty()){
				if(v1.front() < ans){
					ans = max(ans, v1.front()+10);
					v1.pop();
				}
				else break;
			}
			act = -1;
		}
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


