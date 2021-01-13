
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

typedef long double tipo;

const tipo INF = 2e30, EPS = 1e-15;

struct pto{
	tipo x,y;
	pto(tipo x=0, tipo y=0): x(x), y(y){}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator/(tipo a){return pto(x/a, y/a);}
	tipo norm(){return sqrt(x*x+y*y);}
};
tipo dist(pto a, pto b){return (b-a).norm();}
struct line {
	line(){}
	tipo a,b,c;
	line(tipo a, tipo b, tipo c): a(a), b(b), c(c) {}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
};
pto inter(line l1, line l2){
	tipo det = l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}
line bisector(pto x, pto y){
	line l = line(x,y); pto m=(x+y)/2;
	return  line(-l.b, l.a, -l.b*m.x+l.a*m.y);
	
}

bool bad;

struct Circle{
	pto o;
	tipo r;
	Circle(){}
	Circle(pto x, pto y, pto z){
		bad = false;
		o = inter(bisector(x,y), bisector(y,z));
		if(o.x > INF/2) bad = true;
		r=dist(o,x);
	}
};

struct point{
	pto p;
	bool inf;
};

int main(){
	#ifdef ANARAP
	 freopen("input.in", "r", stdin);
	 #endif
	 
	 ios::sync_with_stdio(false);
	 cin.tie(NULL);
	 cout.tie(NULL);
	 int n;
	 cin >> n;
	 if(n <= 2)
	 {
		 cout << "No\n";
		 return 0;
	 }
	 vector<point> v(n);
	 forn(i,n)
	 {
		 int x,y;
		 char c;
		 cin >> x >> y >> c;
		 v[i].p = pto(x,y);
		 v[i].inf = c == 'I';
	 }
	 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	 shuffle(v.begin(), v.end(), rng);
	 forn(i,n)forr(j,i+1,n)forr(k,j+1,n)
	 {
		 Circle c(v[i].p, v[j].p, v[k].p);
		 if(bad) continue;
		 bool ok = true;
		 forn(x,n)
		 {
			 if(x == i || x == j || x == k) continue;
			 if(v[x].inf)
			 {
				 if(dist(v[x].p, c.o) - c.r > EPS)
				 {
					 ok = false;
					 break;
				 }
			 }
			 else
			 {
				 if(dist(v[x].p, c.o) - c.r < -EPS)
				 {
					 ok = false;
					 break;
				 }
			 }
		 }
		 if(ok)
		 {
			 //cout << i << ' ' << j << ' ' << k << '\n';
			 cout << "No\n";
			 //cout << c.o.x << ' ' << c.o.y << ' ' << c.r << '\n';
			 return 0;
		 }
	 }
	 forn(i,n)forr(j,i+1,n)
	 {
		 Circle c;
		 c.o = pto((v[i].p.x+v[j].p.x)/2, (v[i].p.y+v[j].p.y)/2);
		 c.r = dist(v[i].p, v[j].p)/2;
		 bool ok = true;
		 forn(x,n)
		 {
			 if(x == i || x == j) continue;
			 if(v[x].inf)
			 {
				 if(dist(v[x].p, c.o) - c.r > EPS)
				 {
					 ok = false;
					 break;
				 }
			 }
			 else
			 {
				 if(dist(v[x].p, c.o) - c.r < EPS)
				 {
					 ok = false;
					 break;
				 }
			 }
		 }
		 if(ok)
		 {
			 cout << "No\n";
			 return 0;
		 }
	 }
	 cout << "Yes\n";
	 return 0;
	
}
