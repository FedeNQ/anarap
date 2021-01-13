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
#define MAXN 2000
#else
#define MAXN 200010
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

vector<ii> nxt[MAXN];
vector<int> cycle;
int l,r;

void build(int x, int t)
{
	cycle.pb(x);
	forall(it,nxt[x])
	{
		if(sz(cycle) > r || it->snd <= t) break;
		build(it->fst, it->snd);
	}
}

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n;
	 cin >> n >> l >> r;
	 vector<ii> v(n);
	 forn(i,n) cin >> v[i].fst >> v[i].snd;
	 dforn(i,n) nxt[v[i].fst].pb(mp(v[i].snd,i));
	 build(0, -1);
	 forr(i,l,r)
	 {
		 if(i > l) cout << ' ';
		 cout << cycle[i%sz(cycle)];
	 }
	 cout << '\n';
	 return 0;
	
}

