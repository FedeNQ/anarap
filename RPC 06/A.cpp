#include <bits/stdc++.h>
#define bdg(x) cerr<<#x<<"="<<(x)<<endl;
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
//#define ANARAP

#ifdef ANARAP
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<pair<string,ll>,ll> mc;
	
	ll n;
	cin>>n;
	forn(i,n){
		string tipo;
		ll lr;
		cin>>tipo>>lr;
		mc[{tipo,lr}]++;
	}
	vector<vector<ll>> g(sz(mc));
	vector<ll> grad(sz(mc));
	vector<pair<string,ll>> arr(sz(mc));
	ll pos=0;
	forall(it,mc){
		arr[pos]=it->fst;
		pos++;
	}
	
	//~ forall(it,mc){
		//~ pair<string,ll> p = it->fst;
		//~ cout<<p.fst<<" "<<p.snd<<" "<<(it->snd)<<"\n";
	//~ }
	
	forn(i,sz(mc)){
		forn(j,sz(mc)){
			if(i==j) continue;
			if(arr[i].fst=="cube"){
				ll l = arr[i].snd; ll r = arr[j].snd;
				if(arr[j].fst=="cube" && r<=l){
					g[i].pb(j);
					grad[j]++;
				}
				if(arr[j].fst=="cylinder" && r<=l/2){
					g[i].pb(j);
					grad[j]++;
				}
			}else{
				double r = arr[i].snd; double l = arr[j].snd;
				if(arr[j].fst=="cube" && (l*l)/2<=r*r){
					g[i].pb(j);
					grad[j]++;
				}
				if(arr[j].fst=="cylinder" && l<=r){
					g[i].pb(j);
					grad[j]++;
				}
			}
		}
	}
	
	//~ forn(i,sz(g)){
		//~ forn(j,sz(g[i])){
			//~ cout<<g[i][j]<<" ";
		//~ }
		//~ cout<<"\n";
	//~ }
	
	bool ok=true;
	queue<ll> q; ll cant=0;
	vector<ll> ans;
	forn(i,sz(grad)) if(grad[i]==0){ q.push(i);ans.pb(i);cant++;}
	if(cant>1) ok=false;
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		ll cant2=0;
		forn(i,sz(g[u])){
			ll v=g[u][i];
			grad[v]--;
			if(grad[v]==0){ q.push(v); cant2++; ans.pb(v);}
		}
		if(cant2>1) ok=false;
		cant+=cant2;
	}
	
	if(ok && cant==sz(mc)){
		dforn(i,sz(ans)){
			while(mc[arr[ans[i]]]!=0){
				cout<<arr[ans[i]].fst<<" "<<arr[ans[i]].snd<<"\n";
				mc[arr[ans[i]]]--;
			}
		}
	}else{
		cout<<"impossible\n";
	}
	
	return 0;
}




