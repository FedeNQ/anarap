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
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(T,t)
	{
		int q,aux,x;
		multiset<int> s;
		stack<int> st;
		cin >> q;
		forn(i,q)
		{
			cin >> aux;
			if(aux == 1)
			{
				cin >> x;
				s.insert(x);
				st.push(x);
			}
			else if(aux == 2)
			{
				if(!st.empty())
				{
					s.erase(s.find(st.top()));
					st.pop();
				}
			}
			else
			{
				if(s.empty()) cout << "Empty!\n";
				else cout << *s.rbegin() - *s.begin() << '\n';
			}
		}
	}
	return 0;
}
