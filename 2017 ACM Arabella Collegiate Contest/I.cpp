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

#define MAXN 2050

int d1[MAXN];//d1[i] = max odd palindrome centered on i
int d2[MAXN];//d2[i] = max even palindrome centered on i
//s  aabbaacaabbaa
//d1 1111117111111
//d2 0103010010301

set<char> aux = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

void manacher(string &s) { // O(|S|) - find longest palindromic substring
	int l=0, r=-1, n=s.size();
	forn(i, n) { // build d1
		if(aux.count(s[i])){
			int k = i>r? 1 : min(d1[l+r-i], r-i);
			//~ cout << k << endl;
			while(i+k<n && i-k>=0 && s[i+k]==s[i-k] && aux.count(s[i-k])) k++;
			 d1[i] = k--;
			if(i+k > r) l=i-k, r=i+k;
		}
		else{
			 l=i; r=i;
			 d1[i] = 0;
		 }
	}
	l=0, r=-1;
	forn(i, n) { // build d2
		if(aux.count(s[i])){
			int k = (i>r? 0 : min(d2[l+r-i+1], r-i+1))+1;
			while(i+k<=n && i-k>=0 && s[i+k-1]==s[i-k] && aux.count(s[i-k])) k++;
			d2[i] = --k;
			if(i+k-1 > r) l=i-k, r=i+k-1;
		}
		else{
			 d2[i] = 0;
			 l=i; r=i;
			 
		 }
	}
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
	//~ cout << atan(-1)*4 << '\n';
	int t; cin >> t;
	forn(T,t){
		string s; cin >> s;
		manacher(s);
		int ans = 0;
		forn(i,sz(s))
		{
			//~ cout << d1[i] << " " << d2[i] << '\n';
			ans = max({ans, d1[i]+d1[i]-1, d2[i]*2});
		}
		cout << ans << '\n';
	}
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

