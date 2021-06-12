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
//#define ANARAP
#define EPS 0.000000001

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
pair<long double, long double> pint;

bool intersection(long double d, long double a, long double b, long double c){
	if(a==0){
		if(b==0) return false;
		else{
			pint={(d-c)/b,(d-c)/b};
			return true;
		}
	}
	long double sq = b*b-4*a*(c-d);
	if(sq>=0){
		pint = {(-b+sqrt(sq))/(2.0*a),(-b-sqrt(sq))/(2.0*a)};
		return true;
	}else{
		return false;
	}
}

long double ca,cb,cc;
long double f(long double ti){
	return ca*(ti*ti)+cb*ti+cc;
}

long double integral(long double a, long double b, long int n=10000){
	long double area=0, h=(b-a)/n, fa=f(a), fb;
	forn(i, n)
	{
		fb=f(a+h*(i+1));
		area+=fa+ 4*f(a+h*(i+0.5)) +fb, fa=fb;
	}
	return area*h/6.;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,m;
	cin>>n;
	vector<long double> cons(n),int1(n);
	int1[0]=0.0;
	forn(i,n){
		cin>>int1[i];
		cin>>cons[i];
	}
	cin>>m;
	vector<long double> int2(m);
	vector<vector<long double>>cuad(m);
	forn(i,m){
		cuad[i].resize(3);
		cin>>int2[i];
		cin>>cuad[i][0]>>cuad[i][1]>>cuad[i][2];
	}
	
	ll pos1=0,pos2=0;
	long double ti= 0.0;
	long double ans=0.0;
	while(abs(ti-int1[n-1])>EPS){
		long double ini, fin;
		
		ini = ti;
		fin = min(int1[pos1],int2[pos2]);
		//~ cout<<"pos1 "<<pos1<<" pos2 "<<pos2<<endl;
		//~ cout<<cons[pos1]<<" "<<cuad[pos2][0]<< " "<<cuad[pos2][1]<<" "<<cuad[pos2][2]<<endl;
		if(intersection(cons[pos1],cuad[pos2][0],cuad[pos2][1],cuad[pos2][2])){
			//~ cout<<" int1 "<<pint.fst<<" int2  "<<pint.snd<<endl;
			if(ti<pint.fst) fin=min(pint.fst,fin);
			if(ti<pint.snd) fin=min(pint.snd,fin);
		}
		//~ cout<<" ini "<<ini<<" fin "<<fin<<endl;
		ca=cuad[pos2][0],cb=cuad[pos2][1],cc=cuad[pos2][2];
		long double acuad = integral(ini,fin,10000);
		
		ans+=abs(acuad-cons[pos1]*(fin-ini));
		ti=fin;
		//~ cout<<ans<<"\n";
		if(ti>=int1[pos1]) pos1++;
		if(ti>=int2[pos2]) pos2++;
		
	}
	cout<<fixed<<setprecision(8)<<ans<<"\n";
	
	return 0;
}




