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


const int MAXN=104, LOGN=20;
//f[v][k] holds the 2^k father of v
//L[v] holds the level of v
int N, f[MAXN][LOGN], L[MAXN];
vector<int> G[MAXN];
int grade[MAXN];
//call before build:
void dfs(int v, int fa=-1, int lvl=0){//generate required data
	f[v][0]=fa, L[v]=lvl;
	forall(it, G[v])if(*it!=fa) dfs(*it, v, lvl+1); }
void build(){//f[i][0] must be filled previously, O(nlgn)
	forn(k, LOGN-1) forn(i, N) f[i][k+1]=f[f[i][k]][k];}
#define lg(x) (31-__builtin_clz(x))//=floor(log2(x))
int climb(int a, int d){//O(lgn)
	if(!d) return a;
	dforn(i, lg(L[a])+1) if(1<<i<=d) a=f[a][i], d-=1<<i;
    return a;}
int lca(int a, int b){//O(lgn)
	if(L[a]<L[b]) swap(a, b);
	a=climb(a, L[a]-L[b]);
	if(a==b) return a;
	dforn(i, lg(L[a])+1) if(f[a][i]!=f[b][i]) a=f[a][i], b=f[b][i];
	return f[a][0]; }
int dist(int a, int b) {//returns distance between nodes
	return L[a]+L[b]-2*L[lca(a, b)];}


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
	
	int n,m; cin >> n >> m;
	map<string,int> id;
	int idNow = 0;
	map<int, string> name;
	
	forn(i,n){
		string a; cin >> a;
		int mid = -1;
		if(id.count(a)) mid = id[a];
		else{ id[a] = idNow; name[idNow] = a; mid = idNow; idNow++;}
		int x; cin >> x;
		forn(_,x){
			int bid = -1;
			string b; cin >> b;
			if(id.count(b)) bid = id[b];
			else{ id[b] = idNow; name[idNow] = b; bid = idNow; idNow++;}
			G[mid].pb(bid);
			G[bid].pb(mid);
			grade[bid]++;
		}
	}
	
	int cont = 0;
	int raiz = -1;
	forn(i,idNow) if(grade[i] == 0){raiz=i; cont++;}
	assert(cont == 1);
	N=idNow;
	dfs(raiz);
	build();
	
	forn(i,m){
		string a; cin >> a; string b; cin >> b;
		int ida = id[a], idb = id[b];
		int lcaNow = lca(ida,idb);
		if(lcaNow == idb || lcaNow == ida){
			if(lcaNow == ida) swap(a,b);
			cout << a << " is the ";
			int dx = dist(ida,idb);
			if(dx == 1) cout << "child of ";
			else {
				dx-=2;
				while(dx>0){dx--; cout << "great ";}
				cout << "grandchild of ";
			}
			cout << b << '\n';
		}
		else {
			int da = dist(ida,lcaNow);
			int db = dist(idb,lcaNow);
			if(da>db) swap(da,db);
			if(da==db){
				if(db==1) cout << a << " and " << b << " are siblings\n";
				else{ cout << a << " and " << b << " are " << da-1;
					if((da-1) == 11 || (da-1)==12 || (da-1)==13) cout << "th";
					else if(((da-1)%10) == 1) cout << "st";
					else if(((da-1)%10) == 2) cout << "nd";
					else if(((da-1)%10) == 3) cout << "rd";
					else cout << "th";
					cout << " cousins\n";
				}
			}
			else {
				cout << a << " and " << b << " are " << da-1;
				if((da-1) == 11 || (da-1)==12 || (da-1)==13) cout << "th";
				else if(((da-1)%10) == 1) cout << "st";
				else if(((da-1)%10) == 2) cout << "nd";
				else if(((da-1)%10) == 3) cout << "rd";
				else cout << "th";
				cout << " cousins, " << db-da;
				if(db-da != 1) cout << " times ";
				else cout << " time ";
				cout << "removed\n";
			}
		}
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}

