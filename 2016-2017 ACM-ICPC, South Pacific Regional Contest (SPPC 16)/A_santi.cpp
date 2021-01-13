
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

int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};

ii solve(int n)
{
	n--;
	int x = 0, y = 0, d = 1, pos = 0;
	bool change = false;
	while(n >= d)
	{
		x += dx[pos]*d;
		y += dy[pos]*d;
		n -= d;
		if(change) d++;
		change = !change;
		pos = (pos+1)%4;
		//cout << x << ' ' << y << '\n';
	}
	//cout << "extra " << n << '\n';
	x += dx[pos]*n;
	y += dy[pos]*n;
	//cout << x << ' ' << y << '\n';
	return mp(x,y);
}

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int a,b;
	 cin >> a >> b;
	 ii xa = solve(a), xb = solve(b);
	 cout << abs(xa.fst - xb.fst) + abs(xa.snd - xb.snd) << '\n';
	 return 0;
	
}
