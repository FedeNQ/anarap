// ANARAP 💙💛💙
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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//~ freopen("output.txt", "w", stdout);
		unsigned t0, t1; t0=clock();
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//~ forn(T, 12){
		string a,b;
		getline(cin, a);
		getline(cin, b);
		int ta = sz(a), tb = sz(b);
		//~ cout << a << " xd " << b << '\n';
		string st = "", last = "";
		int pos = -1;
		forn(i,ta){
			if(i < tb && a[i] == b[i]){
				if(a[i] == '/') pos = i;
				else if(i == ta-1 && b[i+1] == '/') pos=i;
				else if(i == tb-1 && a[i+1] == '/') pos=i;
			}
			else break;
		}
		if(pos != -1) forn(i,pos+1) st += a[i];
		int post = -1;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//~ int cont = 0;
		forn(i,ta){
			//~ if(cont < pos) break;
			//~ cont++;
			if(i < tb && a[i] == b[i]){
				if(a[i] == '/') post = i;
				else if(i == ta-1 && b[i+1] == '/') post=i;
				else if(i == tb-1 && a[i+1] == '/') post=i;
			}
			else break;
		}
		if(post != -1) forn(i,post+1) last += a[i];
		if(!last.empty() && last.back() != '/') last+='/';
		if(!st.empty() && st.back() != '/') st+='/';
		reverse(last.begin(), last.end());
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		//~ cout << st << " " << last << '\n';
		string mida = "", midb="";
		//~ cout << pos << " " << post << '\n';
		forr(i,pos+1, ta-post-1) mida+=a[i];
		forr(i,pos+1, tb-post-1) midb+=b[i];
		if(!mida.empty() && mida.back() == '/') mida.pop_back();
		if(!midb.empty() && midb.back() == '/') midb.pop_back();
		reverse(mida.begin(), mida.end());
		reverse(midb.begin(), midb.end());
		if(!mida.empty() && mida.back() == '/') mida.pop_back();
		if(!midb.empty() && midb.back() == '/') midb.pop_back();
		mida+="{";
		reverse(mida.begin(), mida.end());
		reverse(midb.begin(), midb.end());
		midb+="}";
		cout << st << mida << " => " << midb << last << '\n';
	//~ }
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


