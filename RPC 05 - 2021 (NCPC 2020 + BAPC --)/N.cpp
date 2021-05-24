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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	int ans = -1;
	forn(i,n)
	{
		string auxs = "";
		forn(j,n) if(j != i)
		{
			int x = j+1;
			stringstream ss;
			ss << x;
			string xs;
			ss >> xs;
			forall(it,xs) auxs.pb(*it);
		}
		if(auxs == s)
		{
			ans = i+1;
			break;
		}
	}
	assert(ans != -1);
	cout << ans << '\n';
	return 0;
}
