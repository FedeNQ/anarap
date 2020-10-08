#include <bits/stdc++.h>
#define forr(i,a,b) for(int i = (a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i = n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin(); it!=v.end();it++)
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
	forn(T,t){
		string p;
		cin >> p;
		int tam = sz(p)-1;
		if(p[tam] == 'a'){
			p+='s';
		}
		else if(p[tam] == 'i' || p[tam] == 'y'){
			p[tam] = 'i';
			p+='o';
			p+='s';
		}
		else if(p[tam] == 'l'){
			p+='e';
			p+='s';
		}
		else if(p[tam] == 'n'){
			p[tam] = 'a';
			p+= "nes";
		}
		else if(p[tam] == 'e' && p[tam-1] == 'n'){
			p[tam-1] = 'a';
			p[tam] = 'n';
			p+= "es";
		}
		else if(p[tam] == 'o'){
			p+='s';
		}
		else if(p[tam] == 'r'){
			p+= "es";
		}
		else if(p[tam] == 't'){
			p+="as";
		}
		else if(p[tam] == 'u'){
			p+='s';
		}
		else if(p[tam] == 'v'){
			p+="es";
		}
		else if(p[tam] == 'w'){
			p+="as";
		}
		else{
			p+= "us";
		}
		cout << p << endl;
	}

	return 0;
}
 

