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
	vector<ii> v(n);
	forn(i,n)
	{
		cin >> v[i].fst;
		v[i].snd = i;
	}
	sort(v.begin(), v.end());
	forn(i,n)
	{
		int l = 0, r = n-1, aux = x-v[i].fst;
		if(aux < 0) continue;
		while(l < i && i < r)
		{
			while(l < i && aux-v[l].fst-v[r].fst > 0) l++;
			if(l < i && aux-v[l].fst-v[r].fst == 0)
			{
				cout << v[i].snd+1 << ' ' << v[l].snd+1 << ' ' << v[r].snd+1 << '\n';
				return 0;
			}
			r--;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
