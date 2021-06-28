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

int v[9][9];
bitset<10> good[9][9];

// single possible value for a pos
bool f1()
{
	forn(i,9)forn(j,9)if(v[i][j] == 0)
	{
		good[i][j].set();
		good[i][j].reset(0);
		forn(k,9)
		{
			if(v[i][k] != 0) good[i][j].reset(v[i][k]);
			if(v[k][j] != 0) good[i][j].reset(v[k][j]);
		}
		int auxr = i/3, auxc = j/3;
		forn(r,3)forn(c,3) if(v[auxr*3+r][auxc*3+c] != 0) good[i][j].reset(v[auxr*3+r][auxc*3+c]);
		assert(good[i][j].count() >= 1);
		if(good[i][j].count() == 1)
		{
			int aux = -1;
			forn(k,10) if(good[i][j][k]) aux = k;
			assert(aux > 0);
			v[i][j] = aux;
			return true;			
		}
	}
	return false;
}

// single possible pos for a value
bool f2()
{
	// look in rows
	forn(i,9)
	{
		vector<int> where(10, -1);
		forn(j,9) forn(k,10) if(good[i][j][k])
		{
			if(where[k] != -1) where[k] = -2;
			else where[k] = j;
		}
		forn(k,10) if(where[k] >= 0)
		{
			v[i][where[k]] = k;
			return true;
		}
	}
	
	// look in cols
	forn(j,9)
	{
		vector<int> where(10, -1);
		forn(i,9) forn(k,10) if(good[i][j][k])
		{
			if(where[k] != -1) where[k] = -2;
			else where[k] = i;
		}
		forn(k,10) if(where[k] >= 0)
		{
			v[where[k]][j] = k;
			return true;
		}
	}
	
	// look in squares
	forn(auxr,3)forn(auxc,3)
	{
		vector<ii> where(10, {-1,-1});
		forn(r,3)forn(c,3) forn(k,10) if(good[auxr*3+r][auxc*3+c][k])
		{
			if(where[k] != mp(-1, -1)) where[k] = {-2, -2};
			else where[k] = {auxr*3+r, auxc*3+c};
		}
		forn(k, 10) if(where[k].fst >= 0)
		{
			v[where[k].fst][where[k].snd] = k;
			return true;
		}
	}
	return false;
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
	int n0=0;
	forn(i,9)forn(j,9)
	{
		cin >> v[i][j];
		if(v[i][j] == 0) n0++;
	}
	while(n0 > 0)
	{
		forn(i,9)forn(j,9) good[i][j].reset();
		if(f1()) n0--;
		else if(f2()) n0--;
		else break;
	}
	if(n0 > 0) cout << "Not easy\n";
	else cout << "Easy\n";
	forn(i,9)
	{
		forn(j,9)
		{
			if(j) cout << ' ';
			if(v[i][j] == 0) cout << '.';
			else cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}
