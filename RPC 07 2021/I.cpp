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
#define MAXN 3000
#else
#define MAXN 300010
#endif

using namespace std;

typedef long long ll;
//typedef pair<int,int> ii;

typedef long double td;

typedef pair<td, int> di;

const td INF = 1e18, EPS = 1e-9;

int N;
vector<di> G[MAXN];
//To add an edge use
#define add(a, b, w) G[a].pb(make_pair(w, b))
vector<td> dijkstra(int s){
	priority_queue<di, vector<di>, greater<di> > Q;
	vector<td> dist(N, INF);
	vector<bool> processed(N, false);
	Q.push(make_pair(0, s)); dist[s] = 0;
	while(sz(Q)){
		di p = Q.top(); Q.pop();
		if(processed[p.snd]) continue;
		processed[p.snd] = true;
		forall(it, G[p.snd])
			if(dist[p.snd]+it->first+EPS < dist[it->snd]) {
				dist[it->snd] = dist[p.snd] + it->fst;
				Q.push(make_pair(dist[it->snd], it->snd));
			}
	}
	return dist;
}

struct pto{
	td x, y;
	pto(td x=0, td y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(td a){return pto(x+a, y+a);}
	pto operator*(td a){return pto(x*a, y*a);}
	pto operator/(td a){return pto(x/a, y/a);}
	//dot product, producto interno:
	td operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	td operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	td norm(){return sqrt(x*x+y*y);}
	td norm_sq(){return x*x+y*y;}
};
td dist(pto a, pto b){return (b-a).norm();}
td dist_sq(pto a, pto b){return (b-a).norm_sq();}

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	td a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(td a, td b, td c):a(a),b(b),c(c){}
	// TO DO chequear porque paso problema metiendo negativo el C (-(todo el calculo como esta))
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
};
bool parallels(line l1, line l2){return abs(l1.a*l2.b-l2.a*l1.b)<EPS;}
pto inter(line l1, line l2){//intersection
	td det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}


struct segm{
	pto s,f;
	segm(pto s, pto f):s(s), f(f) {}
	pto closest(pto p) {//use for dist to point
	   td l2 = dist_sq(s, f);
	   if(l2==0.) return s;
	   td t =((p-s)*(f-s))/l2;
	   if (t<0.) return s;//not write if is a line
	   else if(t>1.)return f;//not write if is a line
	   return s+((f-s)*t);
	}
    bool inside(pto p){return abs(dist(s, p)+dist(p, f)-dist(s, f))<EPS;}
};

//NOTA: Si los segmentos son coolineales solo devuelve un punto de interseccion
pto inter(segm s1, segm s2){
    if(s1.inside(s2.s)) return s2.s; //Fix cuando son colineales
    if(s1.inside(s2.f)) return s2.f; //Fix cuando son colineales
	pto r=inter(line(s1.s, s1.f), line(s2.s, s2.f));
    if(s1.inside(r) && s2.inside(r)) return r;
	return pto(INF, INF);
}

map<pto, int> mid;
int nxtid = 0;
td vs;

inline void addEdge(pto a, pto b)
{
	assert(mid.count(a));
	assert(mid.count(b));
	if(mid[a] == mid[b]) return;
	add(mid[a], mid[b], dist(a,b)/vs);
	add(mid[b], mid[a], dist(a,b)/vs);
	//cout << a.x << ' ' << a.y << " --" << (dist(a,b)/vs) << "-- " << b.x << ' ' << b.y << '\n';
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
	int n;
	cin >> n;
	vector<segm> v(n, segm(pto(0,0), pto(0,0)));
	forn(i,n)
	{
		int xa,ya,xb,yb;
		cin >> xa >> ya >> xb >> yb;
		v[i] = segm(pto(xa,ya), pto(xb,yb));
	}
	td xs,ys;
	cin >> xs >> ys >> vs;
	td x1f, y1f, x2f, y2f, vf;
	cin >> x1f >> y1f >> x2f >> y2f >> vf;
	
	mid[pto(xs,ys)] = nxtid++;
	vector<pto> specialPoints;
	
	bool found = false;
	forn(i,n)
	{
		set<pto> s;
		s.insert(v[i].s);
		s.insert(v[i].f);
		forn(j,n) if(i != j)
		{
			pto aux = inter(v[i], v[j]);
			if(aux.x > INF-10) continue;
			s.insert(aux);
		}
		pto aux = inter(v[i], segm(pto(x1f, y1f), pto(x2f, y2f)));
		if(aux.x < INF-10)
		{
			specialPoints.pb(aux);
			s.insert(aux);
		}
		if(v[i].inside(pto(xs,ys)))
		{
			found = true;
			s.insert(pto(xs,ys));
		}
		
		forall(it,s) if(!mid.count(*it)) mid[*it] = nxtid++;
		
		pto prev;
		forall(it,s)
		{
			if(it != s.begin()) addEdge(prev, *it);
			prev = *it;
		}
	}
	assert(found);
	
	N = nxtid;
	
	vector<td> d = dijkstra(0);
	td ans = INF;
	forn(i,sz(specialPoints))
	{
		pto x = specialPoints[i];
		assert(mid.count(x));
		int id = mid[x];
		td ft = dist(x, pto(x1f, y1f))/vf;
		if(ft+EPS > d[id]) ans = min(ans, ft);
	}
	
	if(ans > INF-10) cout << "Impossible\n";
	else cout << fixed << setprecision(10) << ans << '\n';
	
	return 0;
}
