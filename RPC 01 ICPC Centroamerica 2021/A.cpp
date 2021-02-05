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

typedef ll tipo;

struct frac{
	tipo p,q; 
	frac(tipo p=0, tipo q=1):p(p),q(q){norm();}
	void norm(){
		tipo a=__gcd(q,p);
		if(a) p/=a, q/=a;
		else q=1;
		if(q<0) q=-q, p=-p;
	}
	frac operator+(const frac& o){
		tipo a=__gcd(o.q,q);
		return frac(p*(o.q/a)+o.p*(q/a),q*(o.q/a));
		
	}
	frac operator-(const frac& o){
		tipo a=__gcd(o.q,q);
		return frac(p*(o.q/a)-o.p*(q/a),q*(o.q/a));
	}
	frac operator*(frac o){
		tipo a=__gcd(o.p,q), b=__gcd(p,o.q);
		return frac((p/b)*(o.p/a),(q/a)*(o.q/b));
	}
	frac operator/(frac o){
		tipo a=__gcd(o.q,q), b=__gcd(p,o.p);
		return frac((p/b)*(o.q/a),(q/a)*(o.p/b));
	}
	bool operator<(const frac &o) const{return p*o.q<o.p*q;}
	bool operator==(frac o){return p==o.p&&q==o.q;}
	bool operator<=(frac o){return *this == o || *this < o;}

};

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(T,t)
	{
		int ne, ns, sum = 0;
		cin >> ne >> ns;
		vector<int> ve(ne);
		forn(i,ne)
		{
			cin >> ve[i];
			sum += ve[i];
		}
		forn(_,ns)
		{
			frac grade(0,1);
			forn(i,ne)
			{
				int x;
				cin >> x;
				grade = grade+frac(x*ve[i], 100);
			}
			grade = grade*frac(100,sum);
			for(int i = 0; i <= 100; i += 5)
			{
				if(grade <= frac(i*10+25, 10))
				{
					cout << i << ' ';
					if(grade < frac(i,1)) cout << "UP\n";
					else if(grade == frac(i,1)) cout << "SAME\n";
					else cout << "DOWN\n";
					break;
				}
			}
		}
		cout << '\n';
	}
	return 0;
}
