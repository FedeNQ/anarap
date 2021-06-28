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
	int k;
	cin >> k;
	vector<int> ans;
	forn(K,k)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		forn(i,n) cin >> v[i];
		vector<int> maxToR(n, v[n-1]);
		dforn(i,n-1) maxToR[i] = max(v[i], maxToR[i+1]);
		set<int> s;
		forn(i,n)
		{
			if(maxToR[i] > v[i])
			{
				set<int>::iterator ite = s.ub(v[i]);
				if(ite != s.end() && *ite < maxToR[i])
				{
					ans.pb(K+1);
					break;
				}
			}
			s.insert(v[i]);
		}
	}
	cout << sz(ans) << '\n';
	forall(it, ans) cout << *it << '\n';
	return 0;
}
