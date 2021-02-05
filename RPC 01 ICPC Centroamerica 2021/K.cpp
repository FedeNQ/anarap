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


#define oper(a,b) a+b
#define NEUT 0
struct STree { // persistent segment tree for min over integers
	vector<int> st, L, R; int n,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	int new_node(int v, int l=0, int r=0){
		int ks=sz(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	int init(int s, int e){ // not necessary in most cases
		if(s+1==e)return new_node(0);
		int m=(s+e)/2,l=init(s,m),r=init(m,e);
		return new_node(oper(st[l],st[r]),l,r);
	}
	int upd(int k, int s, int e, int p, int v){
		int ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=v;return ks;}
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	int query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	int init(){return init(0,n);}
	int upd(int k, int p, int v){return rt=upd(k,0,n,p,v);}
	int upd(int p, int v){return upd(rt,p,v);} // update on last root
	int query(int k,int a, int b){return query(k,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin >> n >> k;
	if(k == 1)
	{
		cout << "0\n";
		return 0;
	}
	vector<int> v(n);
	unordered_map<int,int> comp;
	comp.reserve(1<<20);
	forn(i,n)
	{
		cin >> v[i];
		comp[v[i]]++;
	}
	int aux = 0;
	vector<vector<int>> posOfVal(sz(comp));
	forall(it,comp)
	{
		posOfVal[aux].reserve(it->snd);
		it->snd = aux++;
	}
	vector<int> vpos(aux, 0);
	forn(i,n)
	{
		v[i] = comp[v[i]];
		posOfVal[v[i]].pb(i);
	}
	vector<int> roots(n+1);
	STree st(n);
	roots[0] = st.init();
	forn(i,n)
	{
		if(vpos[v[i]] != 0) roots[i+1] = st.upd(posOfVal[v[i]][vpos[v[i]]-1], 0);
		roots[i+1] = st.upd(posOfVal[v[i]][vpos[v[i]]], 1);
		vpos[v[i]]++;
	}
	int ans = 1e9;
	vpos = vector<int>(aux, 0);
	forn(i,n)
	{
		if(vpos[v[i]]+k-1 < sz(posOfVal[v[i]]))
		{
			int l = posOfVal[v[i]][vpos[v[i]]], r = posOfVal[v[i]][vpos[v[i]]+k-1];
			//cout << l << ' ' << r << ' ' << get(l,r+1,roots[r+1],0,n) << '\n';
			ans = min(ans, st.query(roots[r],l,r)-1);
		}
		vpos[v[i]]++;
	}
	if(ans > 1e6) ans = -1;
	cout << ans << '\n';
	return 0;
}
