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
#define MAXN 10
#else
#define MAXN 20
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
ll vbm[1<<MAXN], x;
int vbig[1<<MAXN], vsmallest[1<<MAXN];

int solve(int n)
{
	vector<int> d(1<<n, -1);
	d[(1<<n)-1] = 0;
	queue<int> q;
	q.push((1<<n)-1);
	while(!q.empty())
	{
		int bm = q.front();
		q.pop();
		if(bm == 0) return d[0];
		for(int s = bm; s >= vbig[bm]; s = (s-1)&bm) if(vbm[s] <= x && d[bm^s] == -1 && x-vbm[s] < vsmallest[bm^s])
		{
			d[bm^s] = d[bm]+1;
			q.push(bm^s);
		}
	}
	assert(false);
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
	int n;
	cin >> n >> x;
	vector<ll> v(n);
	forn(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	memset(vsmallest, -1, sizeof(vsmallest));
	vsmallest[0] = x+1;
	forn(bm,(1<<n)) forn(i,n) if(bm & (1<<i))
	{
		vbm[bm] += v[i], vbig[bm] = 1<<i;
		if(vsmallest[bm] == -1) vsmallest[bm] = v[i];
	}
	cout << solve(n) << '\n';
	return 0;
}
