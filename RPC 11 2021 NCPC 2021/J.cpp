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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const double INF = 1000000000.0;
const double EPS = 0.000000000001;
const double dt = 1000.0;

struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};
double dist(pto a, pto b){return (b-a).norm();}


double maxi(pto oi, pto of, pto ki, pto kf){
	pto vk = (kf-ki)/dt, vo = (of-oi)/dt;
	double l=0.0,r=dt,f1,f2,ans=0.0,m1,m2;
	do{
		m1 = l + (r - l) / 3.0, m2 = r - (r - l) / 3.0;
		pto k1 = ki + (vk*m1);
		pto o1 = oi + (vo*m1);
		pto k2 = ki + (vk*m2);
		pto o2 = oi + (vo*m2);
		f1 = dist(k1,o1), f2 = dist(k2,o2);
		if (f1 < f2){
			l = m1;
			ans=f2;
		}else{
			r = m2;
			ans=f1;
		}
	}while(abs(m2-m1)>EPS);
	
	return ans;
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pto ki,kf,oi,of;
	cin>>ki.x>>ki.y>>oi.x>>oi.y>>kf.x>>kf.y>>of.x>>of.y;
	double a1 = maxi(oi,of,ki,kf);
	double a2 = maxi(ki,kf,oi,of);
	cout<<fixed<<setprecision(8)<<max(a1,a2)<<"\n";
	
	return 0;
}




