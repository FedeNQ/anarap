
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

vector<ll> v;

bool sigo(int nextl, int nextr, int pos){
	if(pos <= nextr && pos>=nextl) return true;
	return false;
}

bool bs(int l, int r, int pos, ll num){
	if(l<r){
		int M = (l+r)/2;
		//~ cout << l << " " << r << " " << M << " " << v[M] << " " << num << '\n';
		if(v[M] == num) return true;
		else{
			int nextl, nextr;
			if(v[M] > num){
				nextl = l;
				nextr = M-1;
				if(sigo(nextl,nextr,pos)) return bs(nextl, nextr, pos, num);
				else return false;
			}
			else{
				nextl = M+1;
				nextr = r;
				if(sigo(nextl,nextr,pos)) return bs(nextl, nextr, pos, num);
				else return false;
			}
			
		}
	}
	if(l==r && v[l] == num) return true;
	return false;
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
	int n,m,a,c,s;
	cin >> n >> m >> a >> c >> s;
	v.resize(n+1);

	v[0] = s;
	forr(i,1,n+1)v[i] = (v[i-1]*a + c)%m;
	//~ forn(i,n+1) cout << v[i] << " ";
	//~ cout << '\n';
	int ans =0;

	forr(i,1,n+1){
		//~ cout << " EMPIEZO " << '\n';
		if(bs(1,n,i,v[i])){
			//~ cout << 1 << " " << n << " " << i << " " << v[i] << '\n';
			ans++;
		}
	}
	cout << ans << '\n';
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

