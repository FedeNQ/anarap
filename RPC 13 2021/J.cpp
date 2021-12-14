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

struct Game {
	int c,g,id;
};

bool cmp(Game &a, Game &b)
{
	if(a.g*b.c != b.g*a.c) return a.g*b.c > b.g*a.c;
	if(a.g != b.g) return a.g < b.g;
	return a.id < b.id;
}

#define INF 1000100100

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out","w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,b;
	cin >> n >> b;
	vector<Game> v(n);
	forn(i,n)
	{
		cin >> v[i].c >> v[i].g;
		v[i].id = i;
	}
	sort(v.begin(), v.end(), cmp);
	list<ii> l;
	l.insert(l.begin(), mp(b+1,INF));
	l.insert(l.begin(), mp(0,0));
	forn(i,n)
	{
		//cout << "list " << i << ":\n\t"; forall(it,l) cout << "(" << it->fst << "," << it->snd << ") "; cout << '\n';
		queue<ii> q;
		int best = 0;
		forall(it,l)
		{
			if(it->fst + v[i].c <= b)
			{
				//cout << "push " << it->fst + v[i].c << ' ' << it->snd+v[i].g << '\n';
				q.push(mp(it->fst + v[i].c, it->snd+v[i].g));
			}
			if(q.empty()) break;
			while(!q.empty() && q.front().fst < it->fst)
			{
				ii aux = q.front();
				q.pop();
				//cout << "pop " << aux.fst << ' ' << aux.snd << '\n';
				if(aux.snd <= best) continue;
				//assert(aux.snd <= it->snd);
				//cout << "insert " << aux.fst << ' ' << aux.snd << '\n';
				l.insert(it, aux); // is this safe?
			}
			best = it->snd;
		}
	}
	int ans = 0;
	forall(it,l) if(it->fst <= b) ans = max(ans, it->snd);
	cout << ans << '\n';
	return 0;
}
