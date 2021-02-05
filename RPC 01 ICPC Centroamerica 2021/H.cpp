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

struct trie{
	map<char,trie*> m;
	void add(const string &s, int p=0){
		if(s[p])
		{
			if(!m.count(s[p])) m[s[p]] = new trie();
			m[s[p]]->add(s,p+1);
		}
	}
	bool dfs(const string &s, int p=0){
		if(!s[p]) return true;
		if(m.count(s[p])) return m[s[p]]->dfs(s,p+1);
		return false;
	}
	
};

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
		int p,r;
		cin >> p >> r;
		vector<trie> vp(p);
		forn(i,p)
		{
			int c;
			cin >> c;
			forn(_,c)
			{
				string s;
				cin >> s;
				vp[i].add(s);
			}
		}
		forn(_,r)
		{
			int n, ans = 0;
			vector<bool> good(p, false);
			cin >> n;
			forn(_,n)
			{
				int found = -1;
				string s;
				cin >> s;
				//cout << "for " << s << '\n';
				forn(i,p) if(vp[i].dfs(s))
				{
					//cout << "found in " << i << '\n';
					if(found != -1)
					{
						found = -1;
						break;
					}
					found = i;
				}
				if(found != -1 && !good[found]) good[found] = true, ans++;
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
