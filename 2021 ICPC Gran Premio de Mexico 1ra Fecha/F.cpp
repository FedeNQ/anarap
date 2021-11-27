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

int n; double v;

int h1, m1, s1, h2, m2, s2;
int geth(string p){
	return (p[0]-'0')*10 + (p[1]-'0');
}
int getm(string p){
	return (p[3]-'0')*10 + (p[4]-'0');
}
int getsec1(string p){
	int ret = 0;
	forr(i,6,12){
		if(p[i] == ',') continue;
		ret*=10;
		ret+=(p[i]-'0');
	}
	//~ cout << ret << endl;
	ret += v;
	if(ret >= 60000){
		int retNow = ret;
		ret %= 60000;
		retNow -= ret;
		m1 += retNow/60000;
		if(m1 >= 60){
			int nm1 = m1;
			m1 %= 60;
			nm1 -= m1;
			h1 += nm1/60;
		}
	}
	return ret;
}
int getsec2(string p){
	int ret = 0;
	forr(i,6,12){
		if(p[i] == ',') continue;
		ret*=10;
		ret+=(p[i]-'0');
	}
	ret += v;
	if(ret >= 60000){
		int retNow = ret;
		ret %= 60000;
		retNow -= ret;
		m2 += retNow/60000;
		if(m2 >= 60){
			int nm2 = m2;
			m2 %= 60;
			nm2 -= m2;
			h2 += nm2/60;
		}
	}
	return ret;
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
	
	cin >> n >> v;
	v *= 1000;
	vector<pair<string, pair<string,string>>> ans(n);
	forn(i,n){
		int x; cin >> x;
		string p1, p2; cin >> p1 >> p2 >> p2;
		string nt1 = "00:00:00,000", nt2 = "00:00:00,000", mid = " --> ";
		h1=geth(p1),m1=getm(p1);
		s1=getsec1(p1);
		h2=geth(p2),m2=getm(p2),s2=getsec2(p2);
		
		if(h1 >= 10) nt1[0] = (h1/10 + '0');
		nt1[1] = (h1%10 + '0');
		
		if(h2 >= 10) nt2[0] = (h2/10 + '0');
		nt2[1] = (h2%10 + '0');
		
		if(m1 >= 10) nt1[3] = (m1/10 + '0');
		nt1[4] = (m1%10 + '0');
		
		if(m2 >= 10) nt2[3] = (m2/10 + '0');
		nt2[4] = (m2%10 + '0');
		
		int pos = sz(nt1)-1;
		int cont = 0;
		while(s1 > 0){
			nt1[pos] = (s1%10 + '0');
			s1/=10;
			pos--;
			cont++;
			if(cont == 3) pos--;
		}
		
		pos = sz(nt1)-1, cont = 0;
		while(s2 > 0){
			nt2[pos] = (s2%10 + '0');
			s2/=10;
			pos--;
			cont++;
			if(cont == 3) pos--;
		}
		
		string rta = nt1 + mid + nt2;
		//~ cout << rta << '\n';
		string f1, f2, f3;
		getline(cin, f1);
		getline(cin, f2);
		if(!f2.empty()) getline(cin, f3);
		ans[x-1] = mp(rta, mp(f2,f3));
	}
	forn(i,n){
		if(i) cout << '\n';
		cout << i+1 << '\n';
		cout << ans[i].fst << '\n';
		cout << ans[i].snd.fst << '\n';
		if(!ans[i].snd.snd.empty()) cout << ans[i].snd.snd << '\n';
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}



