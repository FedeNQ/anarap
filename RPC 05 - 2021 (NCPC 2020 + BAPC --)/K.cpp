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

int n;

string solve(string &a, string &b, int pos)
{
	string sa = a;
	int goodPos = -1;
	dforn(i,pos+1)
	{
		if(a[i]+b[i]-2*'0'+(i != pos) < 10)
		{
			goodPos = i;
			break;
		}
	}
	assert(goodPos < pos && goodPos >= 0);
	assert(sa[goodPos] < '9');
	string ret = "";
	int rmnotzero = n-1;
	while(a[rmnotzero] == '0') rmnotzero--;
	assert(rmnotzero >= 0);
	bool notzero = false;
	forr(i, goodPos+1, rmnotzero)
	{
		if(notzero || '9'-a[i]+'0' > '0')
		{
			notzero = true;
			ret.pb('9'-a[i]+'0');
		}
	}
	ret.pb('9'-a[rmnotzero]+'1');
	forr(i,rmnotzero+1,n) ret.pb('0');
	return ret;
}

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a,b;
	cin >> a >> b;
	reverse(a.begin(), a.end());	
	reverse(b.begin(), b.end());
	while(sz(a) < sz(b)) a.pb('0');
	while(sz(b) < sz(a)) b.pb('0');
	a.pb('0');
	b.pb('0');
	reverse(a.begin(), a.end());	
	reverse(b.begin(), b.end());
	n = sz(a);
	int pos = -1;
	forn(i,n)
	{
		if(a[i] + b[i] - 2*'0' > 9)
		{
			pos = i;
			break;
		}
	}
	if(pos == -1)
	{
		cout << "0\n";
		return 0;
	}
	string s1 = solve(a,b,pos), s2 = solve(b,a,pos);
	//cout << a << ' ' << b << ' ' << s1 << '\n';
	//cout << b << ' ' << a << ' ' << s2 << '\n';
	if(sz(s1) < sz(s2)) cout << s1 << '\n';
	else if(sz(s2) < sz(s1)) cout << s2 << '\n';
	else cout << min(s1,s2) << '\n';
	return 0;
}

