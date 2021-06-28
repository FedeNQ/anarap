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

inline ll gauss(ll x)
{
	return x*(x+1)/2;
}

#define MAXX 100

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k,dd[3]={-1,0,1};
	cin >> n >> m >> k;
	map<ii,int> mm;
	queue<ii> q;
	forn(i,n)forn(j,m)
	{
		char c;
		cin >> c;
		if(c == '#') mm[mp(i,j)] = 0, q.push(mp(i,j));
	}
	ll aux = 0;
	while(!q.empty())
	{
		int r = q.front().fst, c = q.front().snd;
		q.pop();
		int t = mm[mp(r,c)];
		if(t+1 <= min(k,MAXX)) forn(i,3)forn(j,3)
		{
			int rr = r+dd[i], cc = c+dd[j];
			if(!mm.count(mp(rr,cc)))
			{
				if(t+1 == MAXX) aux++;
				mm[mp(rr,cc)] = t+1;
				q.push(mp(rr,cc));
			}
		}
	}
	ll ans = sz(mm);
	if(k > MAXX && sz(mm))
	{
		ans += gauss(k-MAXX)*8 + (k-MAXX)*aux;
	}
	cout << ans << '\n';
	return 0;
}
