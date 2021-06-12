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

int n,m,k, dd[3] = {-1,0,1};
char vv[51][51];

inline bool good(int r, int c)
{
	return r < n && c < m && r >= 0 && c >= 0 && vv[r][c] != '#';
}

struct Node{
	int r,c,vr,vc,nxt;
	bool operator ==(const Node &x) const
	{
		return r == x.r && c == x.c && vr == x.vr && vc == x.vc && nxt == x.nxt;
	}
};

struct Hash{
	size_t operator()(const Node &x)const
	{
		return x.r + x.c*n + x.vr*n*m + x.vc*n*m*n + x.nxt*n*m*n*m;
	}
};

void bfs()
{
	unordered_map<Node,int,Hash> md;
	deque<Node> q;
	forn(i,n)forn(j,m) if(vv[i][j] == '0')
	{
		md[{i,j,0,0,1}] = 0;
		q.pb({i,j,0,0,1});
	}
	while(!q.empty())
	{
		Node node = q.front();
		q.pop_front();
		int d = md[node];
		assert(node.nxt < k);
		if(node.nxt == k-1)
		{
			if(node.nxt == vv[node.r][node.c]-'0' && node.vr == 0 && node.vc == 0)
			{
				cout << d << '\n';
				return;
			}
		}
		else
		{
			if(node.nxt == vv[node.r][node.c]-'0')
			{
				Node aux = node;
				aux.nxt++;
				//assert(!md.count(aux));
				md[aux] = d;
				q.push_front(aux);
			}
		}
		int r = node.r, c = node.c, vr = node.vr, vc = node.vc;
		forn(i,3)forn(j,3)
		{
			int vvr = vr+dd[i], vvc = vc+dd[j];
			int rr = r+vvr, cc = c+vvc;
			if(good(rr,cc))
			{
				Node aux = {rr,cc,vvr,vvc,node.nxt};
				if(!md.count(aux))
				{
					md[aux] = d+1;
					q.pb(aux);
				}
			}
		}
	}
	cout << "impossible\n";
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
	cin >> n >> m >> k;
	k += 2;
	forn(i,n)forn(j,m) cin >> vv[i][j];
	bfs();
	return 0;
}
