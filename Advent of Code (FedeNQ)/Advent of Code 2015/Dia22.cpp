// ANARAP 💙💛💙
// 💧🙌🏻
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

int m[5] = {53,73,113,173,229};

int dmg = 8;

int solve(int pos, vector<int> v, int mana, int hp, int armor, int hp2){
	if(hp2 <= 0) return 0;
	if(pos%2 == 0){
		hp--;
		if(hp<=0) return 300000;
	}
	if(pos == 30) return 300000;
	
	int ret = 300000;
	forn(i,4){
		if(i==1){
			if(v[i] > 0){
				v[i]--;
				if(v[i] == 0) armor-=7;
			}
		}
		if(i==2){
			if(v[i] > 0){
				v[i]--;
				hp2-=3;
			}
		}
		if(i==3){
			if(v[i] > 0){
				v[i]--;
				mana+=101;
			}
		}
	}
	if(hp2 <= 0) return 0;
	if(pos%2){
		hp-=max(1,dmg-armor);
		ret=3000000;
		if(hp > 0) ret = min(ret, solve(pos+1, v, mana, hp, armor,hp2));
	}
	else{
		if(hp>0){
			forn(i,5){
				if(mana-m[i] >= 0){
					if(i == 0){
						ret = min(ret, m[i]+solve(pos+1, v, mana-m[i], hp, armor,hp2-4));
					}
					if(i==1){
						ret = min(ret, m[i]+solve(pos+1, v, mana-m[i], hp+2, armor, hp2-2));
					}
					if(i==2){
						if(v[1] == 0){
							v[1] = 6;
							ret = min(ret, m[i]+solve(pos+1, v, mana-m[i], hp, armor+7, hp2));
							v[1] = 0;
						}
					}
					if(i==3){
						if(v[2] == 0){
							v[2] = 6;
							ret = min(ret, m[i]+solve(pos+1, v, mana-m[i], hp, armor, hp2));
							v[2] = 0;
						}
					}
					if(i==4){
						if(v[3] == 0){
							v[3]=5;
							ret = min(ret, m[i]+solve(pos+1, v, mana-m[i], hp, armor, hp2));
							v[3]=0;
						}
					}
				}
			}
		}
	}
	//~ forall(it, v) cout << *it << " ";
	//~ cout << endl;
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
	
	vector<int> v(4,0);
	cout << solve(0, v, 500, 50, 0, 55) << '\n';
	
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


