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
	cin >> n;
	vector<int> v(1<<n, 0);
	v[1] = 1;
	int nxt = 2, nxtbit = 1;
	while(nxt < (1<<n))
	{
		int aux = nxt;
		dforn(i,aux) v[nxt++] = (1<<nxtbit) + v[i];
		nxtbit++;
	}
	forn(i,(1<<n))
	{
		forn(j,n) cout << ((v[i]&(1<<(n-j-1)))?1:0);
		cout << '\n';
	}
	return 0;
}
