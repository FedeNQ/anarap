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

#define MAXN 100010

//Para non-increasing, cambiar comparaciones y revisar busq binaria
//Given an array, paint it in the least number of colors so that each color turns to a non-increasing subsequence.
//Solution:Min number of colors=Length of the longest increasing subsequence
int N, a[MAXN];//secuencia y su longitud
ii d[MAXN+1];//d[i]=ultimo valor de la subsecuencia de tamanio i
#define INF 1000100100

int lis(){//O(nlogn)
	d[0] = ii(-INF, -1); forn(i, N) d[i+1]=ii(INF, -1);
	forn(i, N){
		int j = upper_bound(d, d+N+1, ii(a[i], INF))-d;
		if (d[j-1].first < a[i]&&a[i] < d[j].first){
			d[j] = ii(a[i], i);
		}
	}
	dforn(i, N+1) if(d[i].first!=INF){
		return i;//longitud
	}
	return 0;
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
	int n;
	while(cin >> n)
	{
		N = n;
		assert(n < MAXN);
		forn(i,n)
		{
			cin >> a[i];
			assert(a[i] >= 0 && a[i] < INF);
		}
		int l1 = lis();
		reverse(a,a+n);
		int l2 = lis();	
		if(l1 != l2) cout << "Don't worry. I must intervene.\n";
		else cout << "Caution. I will not intervene.\n";
	}
	return 0;
}
