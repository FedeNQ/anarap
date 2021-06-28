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

#define MAXN 101
#define MAXR 51

#define INF 1000100100

int r,s,n;
ll sumr, sums;
int vr[MAXR], vs[MAXR], vn[MAXN];
vector<vector<int>> gmodr(200*MAXR), gmods(200*MAXR);
vector<int> distgr(200*MAXR, INF), distgs(200*MAXR, INF);

void bfs(vector<vector<int>> &g, vector<int> &dist)
{
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		forall(it, g[node]) if(dist[*it] == INF)
		{
			dist[*it] = dist[node]+1;
			q.push(*it);
		}
	}
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
	cin >> r >> s >> n;
	forn(i,r)
	{
		cin >> vr[i];
		sumr += vr[i];
	}
	forn(i,s)
	{
		cin >> vs[i];
		sums += vs[i];
	}
	forn(i,n) cin >> vn[i];
	forn(i,sumr) gmodr[i].pb((i+sums)%sumr);
	forn(i,sums) gmods[i].pb((i+sumr)%sums);
	bfs(gmodr, distgr);
	bfs(gmods, distgs);
	
	bool dp[2][MAXR][MAXR];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = true;
	forn(pn,n)
	{
		forn(i,r)forn(j,s) dp[1-pn%2][i][j] = false;
		int cnt = 0;
		forn(pr,r)
		{
			if(cnt == r*s) break;
			forn(ps,s)if(dp[pn%2][pr][ps])
			{
				if(cnt == r*s) break;
				int curr = vn[pn];
				forn(i,r)
				{
					if(curr < 0) break;
					int cur = curr;
					forn(j,s)
					{
						if(cur < 0) break;
						ll d = min(distgr[cur%sumr]*sums, distgs[cur%sums]*sumr);
						//cout << cur << ' ' << d << '\n';
						if(d <= cur && !dp[1-pn%2][(pr+i)%r][(ps+j)%s]) dp[1-pn%2][(pr+i)%r][(ps+j)%s] = true, cnt++;
						cur -= vs[(ps+j)%s];
					}
					curr -= vr[(pr+i)%r];
				}
			}
		}
		if(cnt == 0)
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}
