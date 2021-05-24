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
typedef long double ldt;

const ldt PI = acosl(-1);
const ldt EPS = 1e-9;
const ldt INF = 1e9;

struct pto{
	ldt x, y;
	pto(ldt xx=0, ldt yy=0):x(xx),y(yy){}
};

pto rotate(pto p, ldt theta) {
	return pto(p.x*cosl(theta) - p.y*sinl(theta), p.x*sinl(theta) + p.y*cosl(theta));
}

struct Machine {
	pto p;
	char c;
};

bool cmp(Machine &a, Machine &b)
{
	if(fabsl(a.p.x - b.p.x) > EPS) return a.p.x < b.p.x;
	if(fabsl(a.p.y - b.p.y) > EPS) return a.p.y < b.p.y;
	assert(false);
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<Machine> v(n);
	forn(i,n)
	{
		int x,y;
		char c;
		cin >> x >> y >> c;
		v[i].p = rotate(pto(2*x, y), (360-45)*PI/180);
		v[i].c = c;
	}
	sort(v.begin(), v.end(), cmp);
	ldt minyN = INF;
	vector<Machine> vp;
	vp.reserve(n);
	forn(i,n)
	{
		if(v[i].c == 'P')
		{
			if(v[i].p.y > minyN-EPS)
			{
				cout << "impossible\n";
				return 0;
			}
			vp.pb(v[i]);
		}
		if(v[i].c == 'N')
		{
			minyN = min(minyN, v[i].p.y);
		}
		if(v[i].c == '-')
		{
			if(v[i].p.y > minyN-EPS) v[i].c = 'N';
		}
	}
	int posvp = sz(vp)-1;
	ldt maxy = -INF, auxmaxy = -INF;
	int ans = 0, i = n-1;
	while(posvp >= 0)
	{
		assert(i >= 0);
		while(i >= 0 && vp[posvp].p.x < v[i].p.x+EPS)
		{
			if(v[i].c == 'N')
			{
				i--;
				continue;
			}
			auxmaxy = max(auxmaxy, v[i].p.y);
			i--;
		}
		if(vp[posvp].p.y-EPS > maxy)
		{
			ans++;
			maxy = auxmaxy;
		}
		posvp--;
	}
	cout << ans << '\n';
	return 0;
}
