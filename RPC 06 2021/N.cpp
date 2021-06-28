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
//prueba
#else
//real
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

struct UnionFind{
	vector<int> f, setSize; //the array f contains the parent of each node
	int cantSets;
	void init(int n)
	{
		f.clear(); setSize.clear();
		cantSets = n;
		f.rsz(n, -1);
		setSize.rsz(n, 1);
	}
	int comp(int x) {return (f[x]==-1? x : f[x]=comp(f[x]));}//O(1)
	bool join(int i,int j) //devuelve true si ya estaban juntos
	{
		int a = comp(i), b = comp(j);
		if(a != b)
		{
			cantSets--;
			if(setSize[a] > setSize[b]) swap(a,b);
			setSize[b] += setSize[a];
			f[a] = b; //el grupo mas grande (b) ahora representa al mas chico (a)
		}
		return a == b;
	}
};

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
	
	int n; cin >> n;
	vector<int> a(n),ans(n, -1);
	vector<bool> used(n,0);
	set<int> notUsed;
	forn(i,n) notUsed.insert(i);
	forn(i,n) cin >> a[i];
	forn(i,n) a[i]--;
	UnionFind uf;
	uf.init(n);
	
	forn(i,n-1){
		if(used[a[i]] == 0){
				if(uf.join(i, a[i])){
					forall(it, notUsed){
						if(!uf.join(i,*it)){
							used[*it]=1;
							ans[i] = *it;
							notUsed.erase(it);
							break;
						}
					}
				}
				else{
					used[a[i]]=1;
					ans[i] = a[i];
					notUsed.erase(a[i]);
				}
		}
		else{
			forall(it, notUsed){
				if(!uf.join(i,*it)){
						used[*it]=1;
						ans[i] = *it;
						notUsed.erase(it);
						break;
				}
			}
		}
	}
	int nouse = -1;
	forn(i,n) if(used[i] == 0) nouse = i;
	ans[n-1] = nouse;
	forn(i,n) {
		if(i) cout << " ";
		 cout << ans[i]+1;}
	cout << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


