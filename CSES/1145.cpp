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
#define MAXN 100
#else
#define MAXN 200010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int const INF = INT_MAX;
//Para non-increasing, cambiar comparaciones y revisar busq binaria
//Given an array, paint it in the least number of colors so that each color turns to a non-increasing subsequence.
//Solution:Min number of colors=Length of the longest increasing subsequence
int N, a[MAXN];//secuencia y su longitud
ii d[MAXN+1];//d[i]=ultimo valor de la subsecuencia de tamanio i
int p[MAXN];//padres
vector<int> R;//respuesta
void rec(int i){
	if(i==-1) return;
	R.push_back(a[i]);
	rec(p[i]);
}
int lis(){//O(nlogn)
	d[0] = ii(-INF, -1); forn(i, N) d[i+1]=ii(INF, -1);
	forn(i, N){
		int j = upper_bound(d, d+N+1, ii(a[i], INF))-d;
		if (d[j-1].first < a[i]&&a[i] < d[j].first){
			p[i]=d[j-1].second;
			d[j] = ii(a[i], i);
		}
	}
	R.clear();
	dforn(i, N+1) if(d[i].first!=INF){
		rec(d[i].second);//reconstruir
		reverse(R.begin(), R.end());
		return i;//longitud
	}
	return 0;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	forn(i,N) cin >> a[i];
	cout << lis() << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

