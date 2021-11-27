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

string s;

bool solve(int x)
{
	int aux10 = 1;
	int rem = 0;
	dforn(i,sz(s))
	{
		rem = (rem+aux10*(s[i]-'0'))%x;
		aux10 = aux10*10%x;
	}
	return rem == 0;
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
	int t;
	cin >> t;
	forn(T,t)
	{
		cin >> s;
		bool ok = false;
		forr(i,2,7) if(solve(i))
		{
			if(ok) cout << ' ';
			else ok = true;
			cout << i;
		}
		if(!ok) cout << "-1\n";
		else cout << '\n';
	}
	return 0;
}

