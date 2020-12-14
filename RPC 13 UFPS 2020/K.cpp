#include <bits/stdc++.h>
#define forr(i, a,b) for(int i=(a); i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define forall(it, v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int) c.size())
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

int main()
{
	#ifdef ANARAP
		freopen("input.in", "r", stdin);
		//freopen("output.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k,n;
	while(cin >> k >> n)
	{
		int tam = 17*k, winner = -1, cur = 0;
		vector<vector<int>> ans(k);
		//vpos va a guardar la posicion actual de cada jugador, pero sin tomar modulo
		vector<int> vpos(k,-1);
		// key: posicion casilla marron ocupada, value: id del jugador en esa casilla
		map<int,int> m;
		forn(i,n)
		{
			// eliminar
			m.erase(vpos[cur]%tam);
			string s;
			cin >> s;
			int d = s[0]-'0'+s[1]-'0';
			if(vpos[cur] == -1)
			{
				if(s[0] == s[1]) ans[cur].pb(17*cur), vpos[cur] = 17*cur;
				else ans[cur].pb(-1);
			}
			else
			{
				int nxtpos = vpos[cur]+d;
				if(nxtpos - 17*cur == tam+3)
				{
					winner = cur;
					ans[cur].pb(7777);
					break;
				}
				// me paso de 7777, manejar el rebote y actualizar nxtpos
				if(nxtpos - 17*cur > tam+3)
				{
					int extra = nxtpos - 17*cur - (tam+3);
					nxtpos = 17*cur + tam+3 - extra;
				}
				bool already = false;
				// nxtpos es una casilla de la forma 777X, y no 7777
				if(nxtpos - 17*cur > tam-5)
				{
					ans[cur].pb(7769 + nxtpos - 17*cur - (tam-5));
					vpos[cur] = nxtpos;
					already = true;
				}
				else if(nxtpos%17 != 0 && nxtpos%17 != 7 && nxtpos%17 != 12)
				{
					// estoy en una casilla blanca, si ya hay alguien lo tengo que sacar
					if(m.count(nxtpos%tam))
					{
						int aux = m[nxtpos%tam];
						assert(aux != cur);
						ans[aux].pb(-1);
						vpos[aux] = -1;
					}
					m[nxtpos%tam] = cur;
				}
				if(!already)
				{
					ans[cur].pb(nxtpos%tam);
					vpos[cur] = nxtpos;
				}
			}
			assert(vpos[cur] == -1 || vpos[cur] >= 17*cur); // FAILING HERE
			assert(vpos[cur] < 17*cur+tam+3);
			if(s[0] != s[1]) cur = (cur+1)%k;
		}
		forn(i,k)
		{
			cout << "Player " << i+1 << " = {-1";
			forall(it, ans[i]) cout << ',' << *it;
			cout << "}\n";
		}
		if(winner != -1) cout << "The winner is Player " << winner+1 << '\n';
		else cout << "There is no winner yet\n";
	}
	return 0;
}
