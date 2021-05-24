#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
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

typedef long double tipo;

const tipo EPS = 1e-6;

struct pto{
	tipo x,y;
	pto(tipo x=0, tipo y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(tipo a){return pto(x+a,y+a);}
	pto operator*(tipo a){return pto(x*a,y*a);}
	pto operator/(tipo a){return pto(x/a,y/a);}
	tipo operator*(pto a){return x*a.x+y*a.y;}
	tipo operator^(pto a){return x*a.y-y*a.x;}
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator==(pto a){return(x-a.x)<EPS && abs(y-a.y)<EPS;}
	tipo norm(){return sqrt(x*x+y*y);}
	tipo norm_sq(){return x*x+y*y;}
};

tipo dist(pto a, pto b){return (b-a).norm();}
tipo dist_sq(pto a, pto b){return (b-a).norm_sq();}
typedef pto vec;

struct segm{
	pto s,f;
	segm(pto s, pto f): s(s), f(f) {}
	pto closest(pto p){
		tipo l2=dist_sq(s,f);
		if(l2==0.) return s;
		tipo t = ((p-s)*(f-s))/l2;
		if(t<0.) return s;
		else if(t>1.) return f;
		return s+((f-s)*t);
	}
	bool inside(pto p){return abs(dist(s,p)+dist(p,f)-dist(s,f))<EPS;}
};

struct event{
	int t, id;
	tipo d;
};

bool cmp(event &a, event &b)
{
	return a.d < b.d;
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);

	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	tipo d1 = 0, d2 = 0;
	vector<event> ve;
	ve.reserve(200000);
	int n,m;
	cin >> n;
	vector<pto> v1(n);
	forn(i,n)
	{
		int x,y;
		cin >> x >> y;
		v1[i] = pto(x,y);
		if(i > 0) d1 += dist(v1[i-1], v1[i]);
		ve.pb({1,i,d1});
	}
	cin >> m;
	vector<pto> v2(m);
	forn(i,m)
	{
		int x,y;
		cin >> x >> y;
		v2[i] = pto(x,y);
		if(i > 0) d2 += dist(v2[i-1], v2[i]);
		ve.pb({2,i,d2});
	}
	sort(ve.begin(), ve.end(), cmp);
	tipo d = 0, ans = dist(v1[0], v2[0]);
	pto curpoint = v2[0];
	int pos = 2, posv1 = 1, posv2 = 1;
	while(posv1 < n || posv2 < m)
	{
		if(pos >= sz(ve)) break;
		tipo curd = ve[pos].d;
		tipo t = curd-d;
		vec aa = v1[posv1]-v1[posv1-1], bb = v2[posv2]-v2[posv2-1];
		aa = aa/aa.norm()*t;
		bb = bb/bb.norm()*t;
		pto nxtpoint = curpoint+(bb-aa);
		segm seg(curpoint, nxtpoint);
		ans = min(ans, dist(v1[0], seg.closest(v1[0])));
		d = curd;
		curpoint = nxtpoint;
		if(ve[pos].t == 1) posv1++;
		else posv2++;
		pos++;
	}
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}
