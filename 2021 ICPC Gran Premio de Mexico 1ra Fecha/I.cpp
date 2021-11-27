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
	ll k,t;
	cin >> n >> k >> t;
	vector<ll> vpos(n);
	forn(i,n) cin >> vpos[i];
	vector<ll> vdist(n), acum(n+1,0);
	dforn(i,n)
	{
		vdist[i] = vpos[n-1]-vpos[i];
		assert(vdist[i] >= 0);
		acum[i] = acum[i+1]+vdist[i];
	}
	ll a=-1,b=-1,c=acum[0];
	forn(i,n)
	{
		int j = int(ub(vpos.begin(), vpos.end(), vpos[i]+k)-vpos.begin())-1;
		assert(j >= i);
		if(i == j) continue;
		ll save = vpos[j]-vpos[i]-t;
		if(save <= 0) continue;
		if(acum[0]-save*(i+1) < c)
		{
			a = i;
			b = j;
			c = acum[0]-save*(i+1);
		}
	}
	if(a == -1) cout << "-1\n";
	else cout << a+1 << ' ' << b+1 << ' ' << c << '\n';
	return 0;
}

