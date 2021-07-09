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
#define MAX 1000
#else
#define MAX 100010
#endif
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;

int N;

int neg(int x) { return x>=N? x-N : x+N;}

//We have a vertex representing a var and other for his negation.
//Every edge stored in G represents an implication. To add an equation of the form a||b, use addor(a, b)
//MAX=max cant var, n=cant var
#define addor(a, b) (G[neg(a)].pb(b), G[neg(b)].pb(a)) 
vector<int> G[MAX*2];
//idx[i]=index assigned in the dfs
//lw[i]=lowest index(closer from the root) reachable from i
int lw[MAX*2], idx[MAX*2], qidx;
stack<int> q;
int qcmp, cmp[MAX*2];
//verdad[cmp[i]]=valor de la variable i
bool verdad[MAX*2+1];

void tjn(int v){
	lw[v]=idx[v]=++qidx;
	q.push(v), cmp[v]=-2;
	forall(it, G[v]){
		if(!idx[*it] || cmp[*it]==-2){
			if(!idx[*it]) tjn(*it);
			lw[v]=min(lw[v], lw[*it]);
		}
	}
	if(lw[v]==idx[v]){
		int x;
		do{x=q.top(); q.pop(); cmp[x]=qcmp;}while(x!=v);
		verdad[qcmp]=(cmp[neg(v)]<0);
		qcmp++;
	}
}
//remember to CLEAR G!!!
bool satisf(){//O(n)
	memset(idx, 0, sizeof(idx)), qidx=0;
	memset(cmp, -1, sizeof(cmp)), qcmp=0;
	forn(i, N){
		if(!idx[i]) tjn(i);
		if(!idx[neg(i)]) tjn(neg(i));
	}
	forn(i, N) if(cmp[i]==cmp[neg(i)]) return false;
	return true;
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
	int n,m;
	cin >> n >> m;
	N = m;
	forn(i,n)
	{
		int a,b,x;
		char c;
		cin >> c >> x;
		x--;
		if(c == '+') a = x;
		else a = neg(x);
		cin >> c >> x;
		x--;
		if(c == '+') b = x;
		else b = neg(x);
		addor(a, b);
	}
	if(!satisf()) cout << "IMPOSSIBLE\n";
	else
	{
		forn(i,m)
		{
			if(i) cout << ' ';
			if(verdad[cmp[i]]) cout << '+';
			else cout << '-';
		}
	}
	return 0;
}
