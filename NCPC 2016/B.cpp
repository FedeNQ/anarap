#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#define MAXN 1000
#else
#define MAXN 100010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

string vs[MAXN];

struct trie{
	map<char,trie> m;
	int prid = 1e9;
	void add(const string &s, int pr, int p)
	{
		if(p < sz(s)) m[s[p]].add(s,pr,p+1);
		prid = min(prid, pr);
	}
	int dfs(const string &s, int mustType, int p)
	{
		//cout << s << ' ' << mustType << ' ' << p << '\n';
		if(p >= sz(s)) return 0;
		int cost = 0, aux = p;
		if(mustType == 0) while(aux < sz(s) && aux < sz(vs[prid]) && s[aux] == vs[prid][aux]) aux++, cost++;
		if(mustType || cost == 0)
		{
			if(!m.count(s[p])) return sz(s)-p-mustType;
			return (mustType == 0)+m[s[p]].dfs(s, max(0, mustType-1), p+1);
		}
		cost = min(cost, 1+sz(vs[prid])-aux) + (sz(s) > aux);
		//cout << "down " << s << ' ' << p << ' ' << aux << ' ' << cost << '\n';
		return cost+m[s[p]].dfs(s, aux-p+(sz(s) > aux)-1, p+1);		
	}
};

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,q;
	cin >> n >> q;
	trie root;
	forn(i,n)
	{
		cin >> vs[i];
		root.add(vs[i], i,0);
	}
	forn(_,q)
	{
		string s;
		cin >> s;
		cout << 1+root.dfs(s, 1, 0) << '\n';
	}
	return 0;
}
