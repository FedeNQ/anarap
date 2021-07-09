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
typedef pair<int,ii> iii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	vector<iii> vv;
	vv.reserve(n*(n-1)/2);
	forn(i,n)forn(j,i) vv.pb(mp(v[i]+v[j], mp(i,j)));
	sort(vv.begin(), vv.end());
	forn(i,n)forn(j,i)
	{
		int aux = x-v[i]-v[j];
		vector<iii>::iterator ite = lb(vv.begin(), vv.end(), mp(aux, mp(0,0)));
		while(ite != vv.end() && ite->fst == aux)
		{
			if(ite->snd.fst == i || ite->snd.fst == j || ite->snd.snd == i || ite->snd.snd == j)
			{
				ite++;
				continue;
			}
			cout << i+1 << ' ' << j+1 << ' ' << ite->snd.fst+1 << ' ' << ite->snd.snd+1 << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
