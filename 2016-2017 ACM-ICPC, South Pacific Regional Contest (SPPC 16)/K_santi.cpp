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
#else
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 string a = "KANGAROO", b = "KIWIBIRD";
	 string s;
	 cin >> s;
	 int xa = 0, xb = 0;
	 forn(i,sz(s))
	 {
		 if(s[i] >= 'a' && s[i] <= 'z') s[i] += 'Z'-(int)'z';
		 forn(j,sz(a)) if(s[i] == a[j]) xa++;
		 forn(j,sz(b)) if(s[i] == b[j]) xb++;
	 }
	 if(xa > xb) cout << "Kangaroos\n";
	 else if(xa < xb) cout << "Kiwis\n";
	 else cout << "Feud continues\n";	
	 return 0;
	
}
