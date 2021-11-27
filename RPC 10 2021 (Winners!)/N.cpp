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

#define MAXN 10'000'000'000'000'000

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;

struct Num {
	int ve[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
	ll x = 1, cd = 1;
};

inline bool operator<(const Num& a, const Num& b)
{
	return a.x < b.x;
}

int vp[13] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
vector<ii> vgood;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<Num> s;
	s.insert(Num());
	
	while(!s.empty())
	{
		Num aux = *s.begin();
		s.erase(s.begin());
		if(!vgood.empty() && aux.cd <= vgood.back().snd) continue;
		vgood.pb(mp(aux.x, aux.cd));
		forn(i,13) if(aux.x*vp[i] <= MAXN)
		{
			Num toAdd = aux;
			toAdd.x *= vp[i];
			toAdd.cd /= toAdd.ve[i]+1;
			toAdd.ve[i]++;
			toAdd.cd *= toAdd.ve[i]+1;
			s.insert(toAdd);
		}
	}
	
	int t;
	cin >> t;
	forn(T,t)
	{
		ll n;
		cin >> n;
		vector<ii>::iterator ite = lb(vgood.begin(), vgood.end(), mp(n+1LL, 0LL));
		assert(ite != vgood.begin());
		ite--;
		cout << ite->fst << '\n';
	}
	return 0;
}
