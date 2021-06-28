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
#else
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<string> exam;
int n, aux;

int match(string p, string a){
	int ret = 0;
	forn(i,aux) if(p[i] == a[i]) ret++;
	return ret;
}

int getmaxmin(string p){
	int rta = aux;
	forn(i,n)rta = min(rta, match(p, exam[i]));
	return rta;
}


int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> aux;
	exam.resize(n);
	forn(i,n) cin >> exam[i];
	int ans = 0;
	forr(bm, 0, 1<<aux){
		string act = "";
		forn(i, aux){
			if(bm&(1<<i)) act+='T';
			else act+='F';
		}
		ans = max(ans, getmaxmin(act));
	}
	cout << ans << '\n';
	
	return 0;
}
