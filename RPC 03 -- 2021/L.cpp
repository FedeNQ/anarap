#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<(b);i++)
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
#define MAXN (1<<10)
#else
#define MAXN (1<<20)
#endif

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
typedef ll tf;
typedef vector<tf> poly;
// FFT
struct CD {
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);
// NTT
/*
struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mulmod(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(submod(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}
*/
const double EPS = 1e-6;
CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		// CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n; // FFT
	//if(inv){ // NTT
	//	CD z(pm(n,MOD-2)); // pm: modular exponentiation
	//	fore(i,0,n)a[i]=a[i]*z;
	//}
}
void multiply(poly& p1, poly& p2, poly& res, bool special, poly &wanted){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	if(special)
	{
		fore(i,0,p1.size()) if(p1[i] != -1) cp1[i].r = cos(2*pi*p1[i]/28.0), cp1[i].i = sin(2*pi*p1[i]/28.0); 
		fore(i,0,p2.size()) if(p2[i] != -1) cp2[i].r = cos(2*pi*p2[i]/28.0), cp2[i].i = -sin(2*pi*p2[i]/28.0); 
	}
	else
	{
		fore(i,0,p1.size())cp1[i]=p1[i];
		fore(i,0,p2.size())cp2[i]=p2[i];
	}
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	n-=2;
	if(special)
	{
		fore(i,0,n) if(fabs(cp1[i].real()-wanted[i]) < EPS) res[i] = wanted[i]; else res[i] = -1;
	}
	else fore(i,0,n) res[i] = ((tf)floor(cp1[i].real()+0.5)); // FFT
	//fore(i,0,n)res.pb(cp1[i].x); // NTT
}

int main(){
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	string t,p;
	char auxc[4] = {'n','s','e','w'};
	map<pair<char,int>, char> toChar;
	toChar[mp('?', -1)] = '?';
	forn(i,7)forn(j,4) toChar[mp(auxc[j], i+1)] = 'A'+i*4+j;
	forn(i,n)
	{
		char c;
		int x = -1;
		cin >> c;
		if(c != '?') cin >> x;
		t.pb(toChar[mp(c,x)]);
	}
	forn(i,m)
	{
		char c;
		int x = -1;
		cin >> c;
		if(c != '?') cin >> x;
		p.pb(toChar[mp(c,x)]);
	}
	reverse(p.begin(), p.end());
	poly pt(n), pp(m), notSpecial(n+m-1), res(n+m-1);
	forn(i,n) pt[i] = t[i] != '?';
	forn(i,m) pp[i] = p[i] != '?';
	multiply(pt, pp, notSpecial, false, pp);
	forn(i,n) if(t[i] == '?') pt[i] = -1; else pt[i] = t[i]-'A';
	forn(i,m) if(p[i] == '?') pp[i] = -1; else pp[i] = p[i]-'A';
	multiply(pt, pp, res, true, notSpecial);
	int ans = 0;
	//cout << t << '\n' << p << '\n';
	/*forn(i,m+n-1) cout << notSpecial[i] << ' '; cout << '\n';
	forn(i,m+n-1) cout << res[i] << ' '; cout << '\n';
	forr(i,m-1,n) cout << notSpecial[i] << ' '; cout << '\n';
	forr(i,m-1,n) cout << res[i] << ' '; cout << '\n';*/
	forr(i,m-1,n) if(res[i] == notSpecial[i]) ans++;
	cout << ans << '\n';
	return 0;
}
