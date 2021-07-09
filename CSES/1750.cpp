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
#define MAXN 2000
#else
#define MAXN 200010
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;

int go[MAXN][30];

int move(int node, int k)
{
	dforn(i,30) if((1<<i) <= k)
	{
		k -= 1<<i;
		node = go[node][i];
	}
	assert(k == 0);
	return node;
}
 
int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin >> n >> q;
	forn(i,n)
	{
		cin >> go[i][0];
		go[i][0]--;
	}
	forr(k,1,30) forn(i,n) go[i][k] = go[go[i][k-1]][k-1];
	forn(_,q)
	{
		int x,k;
		cin >> x >> k;
		x--;
		cout << move(x,k)+1 << '\n';
	}
	return 0;
}
