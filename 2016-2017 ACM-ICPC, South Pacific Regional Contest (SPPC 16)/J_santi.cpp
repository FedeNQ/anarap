
#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second

#ifdef ANARAP
#define MAXN 3000
#else
#define MAXN 300010
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int v[MAXN], n;
ii dp[MAXN][4];

#define INF 2

ii solve(int pos, int cant)
{
	if(cant > 3) return mp(-1,-1);
	if(pos == n)
	{
		assert(cant > 0);
		if(cant == 1) return mp(-1,-1);
		if(cant == 2) return mp(1,0);
		if(cant == 3) return mp(0,1);
		assert(false);
	}
	if(dp[pos][cant] != mp(-3,-3)) return dp[pos][cant];
	ii ret = mp(-1,-1);
	if(pos == 0 || v[pos]-v[pos-1] <= 1000)
	{
		ret = solve(pos+1, cant+1);
	}
	else if(v[pos]-v[pos-1] >= 2000)
	{
		assert(cant > 0);
		if(cant == 2)
		{
			ret = solve(pos+1, 1);
			if(ret.fst >= 0) ret.fst++;
		}
		if(cant == 3)
		{
			ret = solve(pos+1, 1);
			if(ret.fst >= 0) ret.snd++;
		}
	}
	else
	{
		ret = solve(pos+1, cant+1);
		if(ret != mp(-2,-2))
		{
			if(cant == 2)
			{
				ii aux = solve(pos+1, 1);
				if(aux.fst >= 0) aux.fst++;
				if(ret == mp(-1,-1)) ret = aux;
				else if(aux != mp(-1,-1) && aux != ret) ret = mp(-2,-2);
			}
			if(cant == 3)
			{
				ii aux = solve(pos+1, 1);
				if(aux.fst >= 0) aux.snd++;
				if(ret == mp(-1,-1)) ret = aux;
				else if(aux != mp(-1,-1) && aux != ret) ret = mp(-2,-2);
			}
		}
	}
	return dp[pos][cant] = ret;
}

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 cin >> n;
	 forn(i,n) cin >> v[i];
	 sort(v,v+n);
	 forn(i,MAXN)forn(j,4) dp[i][j] = mp(-3,-3);
	 ii ans = solve(0,0);
	 if(ans == mp(-2,-2)) cout << "Ambiguous\n";
	 else if(ans == mp(-1,-1)) cout << "Impossible\n";
	 else cout << "Cars without trailers: " << ans.fst << "\nCars with trailers: " << ans.snd << '\n';
	 return 0;
	
}
