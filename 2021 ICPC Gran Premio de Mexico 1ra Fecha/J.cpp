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
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

vector<int> g[MAXN];
int n, d[MAXN];

void bfs()
{
	memset(d, -1, sizeof(d));
	queue<int> q;
	forr(i,1,n) if(sz(g[i]) == 1)
	{
		d[i] = 1;
		q.push(i);
	}
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		forall(it,g[node]) if(d[*it] == -1)
		{
			d[*it] = d[node]+1;
			q.push(*it);
		}
	}
}

#define MOD 998244353

ll expMod(ll b,ll e,const ll m=MOD) //O(log b)
{
	if(!e) return 1;
	ll q=expMod(b,e/2,m);
	q=q*q%m;
	return e%2? b*q%m : q;
}

ll inverso(ll x) //O(log x)
{
	return expMod(x, MOD-2);//si mod es primo
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
	cin >> n;
	forn(i,n-1)
	{
		int x;
		cin >> x;
		x--;
		g[x].pb(i+1);
		g[i+1].pb(x);
	}
	bfs();
	ll sum = 0;
	forn(i,n)
	{
		assert(d[i] >= 1);
		sum += d[i];
	}
	cout << sum%MOD*inverso(n)%MOD << '\n';
	return 0;
}

