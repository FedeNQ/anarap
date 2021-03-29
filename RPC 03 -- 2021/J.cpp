#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
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
#define EPS 0.000001
#define INF 1000000
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef double tipo;

struct pto{
	double x,y;
	pto(double x=0,double y=0): x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x,y+a.y);}
	pto operator-(pto a){return pto(x-a.x,y-a.y);}
	pto operator+(double a){return pto(x+a,y+a);}
	pto operator*(double a){return pto(x*a,y*a);}
	pto operator/(double a){return pto(x/a,y/a);}
	
	double operator*(pto a){return x*a.x+y*a.y;}
	double operator^(pto a){return x*a.y-y*a.x;}
	
	bool left(pto q,pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const {return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
	bool operator == (pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};

double dist(pto a, pto b){return (b-a).norm();}

typedef pto vec;

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line(){}
	double a,b,c;
	line(double a, double b, double c): a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y),b(p.x-q.x),c(a*p.x+b*p.y){}
	int side(pto p){return sgn(ll(a)*p.x+ll(b)*p.y-c);}
};

pto inter(line l1, line l2){
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF,INF);
	return pto(l2.b*l1.c-l1.b*l2.c,l1.a*l2.c-l2.a*l1.c)/det;
}

vec perp(vec v){return vec(-v.y,v.x);}

line bisector(pto x, pto y){
	line l = line(x,y); pto m = (x+y)/2;
	return line(-l.b,l.a,-l.b*m.x+l.a*m.y);
}

struct Circle{
	pto o;
	double r;
	Circle(pto x, pto y, pto z){
		o=inter(bisector(x,y),bisector(y,z));
		r=dist(o,x);
	}
	pair<pto,pto> ptosTang(pto p){
		pto m = (p+o)/2;
		tipo d =dist(o,m);
		tipo a = r*r/(2*d);
		tipo h = sqrt(r*r-a*a);
		pto m2 = o+(m-o)*a/d;
		vec per = perp(m-o)/d;
		return make_pair(m2-per*h,m2+per*h);
	}
};

bool circle2PtsRad(pto p1, pto p2, double r, pto &c){
	double d2 = (p1-p2).norm_sq(), det=r*r/d2-0.25;
	if(det<0) return false;
	c=(p1+p2)/2+perp(p2-p1)*sqrt(det);
	return true;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	double r;
	cin>>r;
	ll n;
	cin>>n;
	vector<pto> ptos;
	forn(i,n){
		double x,y;
		cin>>x>>y;
		pto p = pto(x,y);
		ptos.pb(p);
	}
	int ans=0;
	forn(i,n){
		forr(j,i+1,n){
			int act=2;
			pto c;
			if(!circle2PtsRad(ptos[i],ptos[j],r,c)) continue;
			forn(k,n){
				if(!(ptos[k]==ptos[i]) && !(ptos[k]==ptos[j])
				&& dist(c,ptos[k])<=r+EPS) act++;
			}
			ans=max(act,ans);
			act=2;
			if(!circle2PtsRad(ptos[j],ptos[i],r,c)) continue;
			forn(k,n){
				if(!(ptos[k]==ptos[i]) && !(ptos[k]==ptos[j])
				&& dist(c,ptos[k])<=r+EPS) act++;
			}
			ans=max(act,ans);
		}
	}
	cout<<max(ans,1)<<"\n";
	
	return 0;
}




