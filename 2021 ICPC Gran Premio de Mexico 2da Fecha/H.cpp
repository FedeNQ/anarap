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
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	set<ii> s;
	vector<ii> ans(q,mp(-1,-1));
	forn(i,q)
	{
		int t;
		cin >> t;
		s.insert(mp(t,i));
	}
	forn(i,n)
	{
		int l = 0, r = v[i];
		while(!s.empty() && s.rbegin()->fst+i >= l)
		{
			assert(l < r);
			set<ii>::iterator itl = s.lb(mp(l-i,0));
			set<ii>::iterator itr = s.lb(mp(r-i,0));
			assert(itl != s.end());
			if(itl == itr) l += 2*v[i], r += 2*v[i];
			else
			{
				int t = itl->fst, id = itl->snd;
				s.erase(itl);
				ans[id] = mp(i, t+i);
				l = t+i+1+v[i];
				r = l+v[i];
			}
		}
	}
	forn(i,q) cout << ans[i].fst << ' ' << ans[i].snd << '\n';
	return 0;
}

