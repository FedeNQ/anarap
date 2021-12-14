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
typedef pair<ll,ll> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k;
	cin >> n >> k;
	unordered_map<string,int> mid;
	mid.reserve(n*4);
	vector<ll> v(n), vneed(n,-1), vcnt(n,0), vcntDone(n,0);
	forn(i,n)
	{
		string s;
		cin >> s >> v[i];
		mid[s] = i;
	}
	int ne;
	cin >> ne;
	vector<ii> ve(ne);
	forn(i,ne)
	{
		string s;
		ll x;
		cin >> s >> x;
		int id = mid[s];
		vneed[id] = max(vneed[id], x);
		vcnt[id]++;
		ve[i] = mp(id,x);
	}
	ll need = 0;
	forn(i,n) need += max(0LL, vneed[i]-v[i]);
	if(need > k)
	{
		cout << "0\n";
		return 0;
	}
	k -= need;
	ll ans = 0;
	ll base = 0;
	ll best = 0;
	forn(i,ne)
	{
		int id = ve[i].fst;
		ll x = ve[i].snd;
		if(v[id] > vneed[id]) continue;
		if(x < vneed[id]) vcntDone[id]++, base += vneed[id];
	}
	set<ii> s;
	forn(i,n) if(vcnt[i])
	{
		if(v[i] <= vneed[i]) s.insert(mp((vcnt[i]-vcntDone[i])*(vneed[i]+1)+vcntDone[i], i));
		else
		{
			base += v[i]*vcnt[i];
			best = max(best, vcnt[i]);
		}
	}
	ans = base+k*best;
	while(k > 0 && !s.empty())
	{
		ll cur = s.rbegin()->fst;
		int id = s.rbegin()->snd;
		s.erase(prev(s.end()));
		k--;
		base += cur;
		best = max(best, vcnt[id]);
		ans = max(ans, base+k*best);
	}
	ans = max(ans, base+k*best);
	cout << ans << '\n';
	return 0;
}
