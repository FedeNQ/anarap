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

vector<int> ans;
string mx[3][3];
int v[6];
bool used[10];

void solve(int r, int c, int pos){
	if(c==3){
		int auxans = 0;
		forn(i,6){ auxans*=10; auxans+=v[i];}
		ans.pb(auxans);
		return;
	}
	if(r==3){
		int aux[3];
		forn(i,3){
			if(sz(mx[i][c])==2) aux[i]=v[mx[i][c][0]-'A']*10+v[mx[i][c][1]-'A']; 
			else aux[i]=v[mx[i][c][0]-'A'];
		}
		//~ cout << " R " << aux[0] << " " << aux[1] << " " << aux[2] << endl;
		if((aux[0]-aux[1])!=aux[2]) return;
		solve(0,c+1,0);
		return;
	}
	if(pos==sz(mx[r][c])){
		if(c==2){
			int aux[3];
			forn(j,3){
				if(sz(mx[r][j])==2) aux[j]=v[mx[r][j][0]-'A']*10+v[mx[r][j][1]-'A']; 
				else aux[j]=v[mx[r][j][0]-'A'];
			}
			//~ cout << " S " <<  aux[0] << " " << aux[1] << " " << aux[2] << endl;
			if((aux[0]+aux[1])!=aux[2]) return;
		}
		solve(r+1, c, 0);
	}
	else{
		if(v[mx[r][c][pos]-'A'] == -1){
			forn(x, 10){
				if(used[x] == 0){
					used[x]=1;
					v[mx[r][c][pos]-'A']=x;
					solve(r,c,pos+1);
					//~ cout << "ACA " << endl;
					used[x]=0;
					v[mx[r][c][pos]-'A']=-1;
				}
			}
		}
		else solve(r,c,pos+1);
	}
}

string tostring(int aux){
	string ret ="";
	forn(_, 6){
		ret+=char(aux%10+'0');
		aux/=10;
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
	int t; cin >> t;
	memset(v, -1, sizeof(v));
	forn(T,t){
		ans.clear();
		forn(i,3)forn(j,3)cin >> mx[i][j];
		solve(0,0,0);
		//~ cout << "HOLA" << endl;
		sort(ans.begin(), ans.end());
		cout << "Case #" << T+1 << ":\n";
		forall(it, ans){
			string aux = tostring(*it);
			dforn(i,6) {if(i<5) cout << " "; cout << aux[i];}
			cout << '\n';
		}
		cout << '\n';
	}
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

