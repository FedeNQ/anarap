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

bool right(char x){
	if(x == '[' || x == '(' || x == '{' || x == '<') return 1;
	return 0;
}
bool match(char x, char y){
	if(x == '[' && y == ']') return 1;
	if(x == '(' && y == ')') return 1;
	if(x == '{' && y == '}') return 1;
	if(x == '<' && y == '>') return 1;
	return 0;
}
int score(char x){
	if(x==')') return 3;
	if(x==']') return 57;
	if(x=='}') return 1197;
	if(x=='>') return 25137;
	assert(0);
	return 0;
}

int nscore(char x){
	if(x=='(') return 1;
	if(x=='[') return 2;
	if(x=='{') return 3;
	if(x=='<') return 4;
	assert(0);
	return 0;
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
	ll ans = 0;
	vector<ll> mid;
	while(cin >> p){
		vector<char> v;
		vector<char> rv;
		int pos = -1,cont=0;
		ans=0;
		forall(it,p){
			if(right(*it)) v.pb(*it);
			else if(match(v.back(), *it)) v.pop_back();
			else{pos=cont; break;}
			cont++;
		}
		if(pos == -1){
			dforn(i,sz(v)){
				ans = ans * 5;
				ans += nscore(v[i]);
			}
			mid.pb(ans);
		}
	}
	sort(mid.begin(), mid.end());
	cout << mid[sz(mid)/2] << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


