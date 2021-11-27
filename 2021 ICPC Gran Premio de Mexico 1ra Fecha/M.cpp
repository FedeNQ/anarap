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

vector<int> nxt, indg;

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
	vector<int> v(n);
	forn(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	vector<vector<int>> d(n, vector<int>(n,0));
	forn(i,n) forn(j,n) if(i != j)
	{
		if(i < j) d[i][j] = v[j]-v[i];
		else d[i][j] = 360-(v[i]-v[j]);
		assert(d[i][j] > 0 && d[i][j] < 360);
	}
	int ans = 0;
	forr(curd,1,360)
	{
		//cout << "\ntry " << curd << ":\n";
		nxt = vector<int>(n);
		forn(i,n) nxt[i] = i;
		indg = vector<int>(n,0);
		forn(i,n)forn(j,n)if(d[i][j] == curd)
		{
			if(curd == 180 && nxt[j] != j) continue;
			assert(indg[j] == 0);
			assert(nxt[i] == i);
			indg[j]++;
			nxt[i] = j;
			//cout << "edge " << i << ' ' << j << '\n';
		}
		vector<bool> used(n,false);
		int aux = 0;
		forn(i,n) if(indg[i] == 0)
		{
			assert(!used[i]);
			int cnt = 0, node = i;
			while(!used[node])
			{
				cnt++;
				used[node] = true;
				node = nxt[node];
			}
			aux += cnt/2;
			//cout << "starting from " << i << ' ' << cnt << '\n';
		}
		ans = max(ans, aux);
	}
	//cout << endl;
	assert(ans > 0);
	cout << ans << '\n';
	return 0;
}

