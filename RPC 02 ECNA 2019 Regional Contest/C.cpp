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

#define EPS 1e-15

vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;
void pivot(int x,int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	forr(i,0,m)if(i!=y)A[x][i]/=A[x][y];
	A[x][y]=1/A[x][y];
	forr(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
		b[i]-=A[i][y]*b[x];
		forr(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	forr(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
	c[y]=-c[y]*A[x][y];
}
double simplex(){ // maximize c^T x s.t. Ax<=b, x>=0){
	// returns pair (maximum value, solution vector)
	//~ A=_A;b=_b;c=_c;
	n=b.size();m=c.size();z=0.;
	X=vector<int>(m);Y=vector<int>(n);
	forr(i,0,m)X[i]=i;
	forr(i,0,n)Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		double mn=-EPS;
		forr(i,0,n)if(b[i]<mn)mn=b[i],x=i;
		if(x<0)break;
		forr(i,0,m)if(A[x][i]<-EPS){y=i;break;}
		assert(y>=0); // no solution to Ax<=b
		pivot(x,y);
		//~ cout << z << '\n';
	}
	//~ int it = 0;
	while(1){
		double mx=EPS;
		int x=-1,y=-1;
		forr(i,0,m){
			if(c[i]>mx) {mx=c[i],y=i;}
			
		}
		if(y<0){break;}
		double mn=1e200;
		forr(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
		assert(x>=0); // c^T x is unbounded
		pivot(x,y);
		//~ cout << z << endl;
	}
	vector<double> r(m);
	forr(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
	return z;
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
	//~ cin >> m >> n;
	int an, am; cin >> an >> am;
	b.resize(an); forn(i,an) cin >> b[i];
	forn(i,n) b[i]*=100;
	c.resize(am);
	A.resize(an);
	forn(i,an) A[i].resize(am);
	forn(i,am){
		forn(j, an){ cin >> A[j][i]; A[j][i]/=100.0;}
		cin >> c[i];
		//~ c[i] = -c[i];
	}
	cout << fixed << setprecision(2) <<  simplex() << endl;
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}
