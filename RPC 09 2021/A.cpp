#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<"="<<(x)<<endl;
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

#ifdef LASCALONETA
//local
#else
//judge
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
string stones[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

ll id(string s){
	int pos=0;
	string tone="";
	forn(i,sz(s)){
		pos++;
		if((s[i]>='A' && s[i]<='Z') || s[i]=='#') tone+=s[i];
		else break;
	}
	pos--;
	//~ cout<<tone<<" ";
	ll ans=0;
	forn(i,12) if(tone==stones[i]) ans+=i;
	ll aux=0;
	forr(i,pos,sz(s)){ aux*=10; aux+=(s[i]-'0');}
	//~ cout<<aux<<" ";
	ans+=(aux-1)*12LL;
	//~ cout<<ans<<endl;
	return ans; 
}

int main()
{
	#ifdef LASCALONETA
		freopen("input.in", "r", stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n; cin>>n;
	string smini,smaxi; cin>>smini>>smaxi;
	vector<string> tones(n);
	forn(i,n) cin>>tones[i];
	
	ll mini=id(smini),maxi=id(smaxi);
	ll minid = LLONG_MAX, maxid = LLONG_MIN; 
	
	vector<ll> num(n);
	forn(i,n){
		num[i]=id(tones[i]);
		minid=min(num[i],minid);
		maxid=max(num[i],maxid);
	}
	//~ dbg(mini);
	//~ dbg(maxi);
	//~ dbg(minid);
	//~ dbg(maxid);
	ll len = maxid-minid+1;
	ll ran = maxi-mini+1;
	ll posi = ran-len+1;
	ll dif = mini-minid;
	forn(i,n) num[i]+=dif;
	ll cacc=LLONG_MAX,ctrans=0;
	forn(i,min(12LL,posi)){
		ll auxcacc=0;
		forn(j,n){
			if((num[j]+i)%12 == 1 
			|| (num[j]+i)%12 == 3 
			|| (num[j]+i)%12 == 6 
			|| (num[j]+i)%12 == 8 
			|| (num[j]+i)%12 == 10) auxcacc++;
		}
		if(auxcacc==cacc) ctrans++;
		else if(auxcacc<cacc){ cacc=auxcacc; ctrans=1;}
	}
	
	ll cant = (posi/12)*ctrans;
	forn(i,posi%12){
		ll auxcacc=0;
		forn(j,n){
			if((num[j]+i)%12 == 1 
			|| (num[j]+i)%12 == 3 
			|| (num[j]+i)%12 == 6 
			|| (num[j]+i)%12 == 8 
			|| (num[j]+i)%12 == 10) auxcacc++;
		}
		if(auxcacc==cacc) cant++;
		else if(auxcacc<cacc){ cacc=auxcacc; cant=1;}
	}
	cout<<cacc<<" "<<cant<<"\n";
	
	return 0;
}




