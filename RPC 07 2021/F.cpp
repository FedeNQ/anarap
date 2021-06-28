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

const int INF = 2; // it doesn't actually have to be infinity or a big number
const int MOD = 37;

int expMod(int b,int e,const int m=MOD) //O(log b)
{
	if(!e) return 1;
	int q=expMod(b,e/2,m);
	q=q*q%m;
	return e%2? b*q%m : q;
}

int inv(int x) //O(log x)
{
	return expMod(x, MOD-2);//si mod es primo
}


int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (a[i][col] > a[sel][col])
                sel = i;
        if (a[sel][col] == 0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = (a[i][col] * inv(a[row][col]))%MOD;
                for (int j=col; j<=m; ++j)
                    a[i][j] = (a[i][j] - a[row][j]*c%MOD + MOD)%MOD;
            }
        ++row;
    }
	ans.clear();
    ans.rsz(m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (a[where[i]][m] * inv(a[where[i]][i]))%MOD;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + ans[j] * a[i][j])%MOD;
        if ((sum - a[i][m] + MOD)%MOD != 0)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

void readline(string &s)
{
	char c;
	while(cin >> c)
	{
		if(c == '\n') break;
		s.pb(c);
	}
}

int toInt(char c)
{
	if(c == ' ') return 36;
	if(c >= 'A' && c <= 'Z') return c-'A';
	assert(c >= '0' && c <= '9');
	return 26+c-'0';
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
	cin >> noskipws;
	char asd;
	cin >> asd;
	assert(asd == '\n');
	string a,b;
	readline(a);
	readline(b);
	assert(sz(a) == sz(b));
	assert(sz(a)%n == 0);
	int pos = 0;
	vector<vector<int>> mat;
	while(pos < sz(a))
	{
		//cout << "pos: " << pos << '\n';
		forn(row, n)
		{
			vector<int> aux(n*n+1, 0);
			forn(col, n)
			{
				aux[row*n+col] = toInt(a[pos+col]);
			}
			aux[n*n] = toInt(b[pos+row]);
			mat.pb(aux);
			//forn(i,n*n+1) cout << aux[i] << ' ';
			//cout << '\n';
		}
		pos += n;
	}
	vector<int> ans;
	int aux = gauss(mat, ans);
	if(aux == INF) cout << "Too many solutions\n";
	else if(aux == 0) cout << "No solution\n";
	else
	{
		forn(i,n)
		{
			forn(j,n)
			{
				if(j) cout << ' ';
				cout << ans[i*n+j];
			}
			cout << '\n';
		}
	}
	return 0;
}
