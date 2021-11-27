// ANARAP 💙💛💙
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
#define MAXN 500010
#else
#define MAXN 500010
#endif

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> ex;

#define cota 500010
vector<ex> edges, q, e;
vector<int> ans;
int color[MAXN], fcolor[MAXN];
vector<int> g[MAXN];

void invertir(int node){
	//invierto colores en la componente mas chiquita :)
	queue<int> qq;
	qq.push(node);
	assert(color[node] != -1);
	if(color[node] == 0) color[node] = 1;
	else color[node] = 0; 
	// seteo el color inverso
	map<int, bool> changed; //unordered???
	changed[node]=1;
	//ya cambie el nodo inicial
	while(!qq.empty()){
		int aux = qq.front();
		qq.pop();
		forall(it, g[aux]){
			if(changed.count(*it)) continue;
			assert(color[*it] != -1);
			//si ya lo cambie, paso al siguiente
			if(color[*it] == 1) color[*it] = 0;
			else color[*it]= 1;
			//seteo el color inverso
			qq.push(*it);
			changed[*it] = 1;
			// lo agrego y lo marco como cambiado
		}
	}
	return;
}


struct UnionFind{
	vector<int> f, setSize; //the array f contains the parent of each node
	int cantSets;
	void init(int n)
	{
		f.clear(); setSize.clear();
		cantSets = n;
		f.rsz(n, -1);
		setSize.rsz(n, 1);
	}
	int comp(int x) {return (f[x]==-1? x : f[x]=comp(f[x]));}//O(1)
	bool join(int i,int j) //devuelve true si los puedo unir
	{
		int a = comp(i), b = comp(j);
		
		if(a != b)
		{
			cantSets--;
			if(setSize[a] > setSize[b]){swap(a,b);swap(i,j);}
			//~ cout << " TAM " << setSize[b] << " " << setSize[a] << endl;
			//~ cout << "BA " << b << " " << a << endl;
			if(setSize[b] == 1){
				assert(color[j] == -1 && color[i] == -1);
				 color[j]=1;
				 color[i]=0;
				 //si la componente mas grande es 1, entonces ambos estan sin pintar, los pinto al azar 1/0
			}
			else if(setSize[a] == 1){
				assert(color[i] == -1 && color[j] != -1);
				if(color[j] == 1) color[i]=0;
				else color[i] = 1;
				// si la componente mas grande > 1 y la mas chica es 1, es un nodo nuevo que agrego a la componente
				// simplemente lo pinto del color contrario al nodo al que lo voy a unir
			}
			else{
				assert(color[i] != -1 && color[j]!=-1);
				if(color[i] == color[j]) invertir(i);
				// son componentes bipartitas individualmente, las uno, pero para unirlas
				// necesito que los nodos a unir sean opuestos
			}
			//~ cout << " color " << color[j] << " " << color[i] << endl;
			setSize[b] += setSize[a];
			f[a] = b; //el grupo mas grande (b) ahora representa al mas chico (a)
			
			return true;
		}
		else{
			assert(color[i]!=-1 && color[j]!=-1);
			if(color[i] != color[j]) return true;
			// quiero agregar una arista dentro de la misma componente, por lo tanto los colores tienen
			// que ser contrarios para mantener que sea bipartito
			return false;
		}
	}
} uf;

bool procesar(){
	bool can = 1;
	forall(it, q){
		//~ cout << " UNO " << it->snd.fst << " " << it->snd.snd << endl;
		can &= uf.join(it->snd.fst, it->snd.snd);
		//si puedo unir y sigue siendo bipartito, agrego la arista
		//~ cout << "POST UNION " << can << '\n';
		if(!can) break;
		g[it->snd.fst].pb(it->snd.snd);
		g[it->snd.snd].pb(it->snd.fst);
		//si efectivamente pude unir, agrego esa arista al grafo
	}
	return can;
}

void resetear(){
	forall(it,e){ 
		fcolor[it->snd.fst] = color[it->snd.fst];
		fcolor[it->snd.snd] = color[it->snd.snd];
	}
	//para todas las aristas, que son del mismo peso, seteo en FCOLOR sus colores oficiales hasta el momento
	return;
}

bool check(){
	bool ok = 0;
	int c0 = 0, c1=0, cm = 0;
	//~ vector<ex> b,w,u;
	// b => aristas(black, no color) 
	// w => aristas(white, no color)
	// u => aristas(no color, no color)
	forall(it, e){
		if(color[it->snd.fst] == color[it->snd.snd]){
			if(color[it->snd.fst] == 1) c1++;
			else if(color[it->snd.fst] == 0) c0++;
			else{ cm++; 
				//u.pb(*it); 
				}
			//si los vertices del edge son iguales, aumento 
			// c1 = ambas uno, c0 = ambas cero, cm = ambas sin color;
		}
		else{
			// son distintos
			if(color[it->snd.fst] == -1 || color[it->snd.snd] == -1){
				//~ if(color[it->snd.fst] == 1 || color[it->snd.snd] == 1) b.pb(*it);
				//~ else w.pb(*it);
			}
			else{
				//colores diferentes en c arista, no pasa nada
			}
		}
		if((c1>0&&c0>0) || (c0>0&&cm>0) || (c1>0&&cm>0)) ok =1;
		// ya existen 2 aristas que tienen/pueden ser de color diferente
		if(ok) break;
	}
	if(ok) return 1;
	//pruebo algo sobre el grafo del dsu?
	map<int, vector<int>> G;
	forall(it,e){
		int a = uf.comp(it->snd.fst);
		int b = uf.comp(it->snd.snd);
		if(color[it->snd.fst] == 1) a+=cota;
		if(color[it->snd.snd] == 1) b+=cota;
		G[a].pb(b);
		if(b!=a) G[b].pb(a);
	}
	ok = 1;
	//~ forall(it,G){
		//~ cout << sz(it->snd) << " " << sz(e) << '\n';
	//~ }
	forall(it, G) if(sz(it->snd) == sz(e)) ok = 0; 
	
	//~ cout << "PASE " << endl;
	//pruebo para aristas que tienen 1vertice de color negro
	//~ int cont = 0;
	//~ while(cont < cota && !b.empty() && !ok){
		//~ cont++;
		//~ ex aux = b.back();
		//~ b.pop_back();
		//~ resetear();
		//~ assert(fcolor[aux.snd.fst] == -1 || fcolor[aux.snd.snd] == -1);
		//~ assert(fcolor[aux.snd.fst] == 1 || fcolor[aux.snd.snd] == 1);
		//~ if(fcolor[aux.snd.fst] == -1) fcolor[aux.snd.fst] = 1;
		//~ else fcolor[aux.snd.snd] = 1;
		//~ forall(it,e){ 
			//~ if(fcolor[it->snd.fst] == -1) fcolor[it->snd.fst] = 0;
			//~ if(fcolor[it->snd.snd] == -1) fcolor[it->snd.snd] = 0;
			//~ if((fcolor[it->snd.snd] == fcolor[it->snd.fst]) && fcolor[it->snd.fst] == 0) ok = 1;
			//~ if(ok) break;
		//~ }
	//~ }
	
	//~ //pruebo para aristas que tienen 1vertice de color blanco
	//~ cont = 0;
	//~ while(cont < cota && !w.empty() && !ok){
		//~ cont++;
		//~ ex aux = w.back();
		//~ w.pop_back();
		//~ resetear();
		//~ assert(fcolor[aux.snd.fst] == -1 || fcolor[aux.snd.snd] == -1);
		//~ assert(fcolor[aux.snd.fst] == 0 || fcolor[aux.snd.snd] == 0);
		//~ if(fcolor[aux.snd.fst] == -1) fcolor[aux.snd.fst] = 0;
		//~ else fcolor[aux.snd.snd] = 0;
		//~ forall(it,e){ 
			//~ if(fcolor[it->snd.fst] == -1) fcolor[it->snd.fst] = 1;
			//~ if(fcolor[it->snd.snd] == -1) fcolor[it->snd.snd] = 1;
			//~ if((fcolor[it->snd.snd] == fcolor[it->snd.fst]) && fcolor[it->snd.fst] == 1) ok = 1;
			//~ if(ok) break;
		//~ }
	//~ }
	//~ //pruebo para aristas que no tienen vertice pintado, capaz ni hace falta xd
	//~ cont = 0;
	//~ while(cont < cota && !u.empty() && !ok){
		//~ cont++;
		//~ ex aux = u.back();
		//~ u.pop_back();
		//~ resetear();
		//~ fcolor[aux.snd.fst] = fcolor[aux.snd.snd] = 0;
		//~ forall(it,e){ 
			//~ if(fcolor[it->snd.fst] == -1) fcolor[it->snd.fst] = 1;
			//~ if(fcolor[it->snd.snd] == -1) fcolor[it->snd.snd] = 1;
			//~ if((fcolor[it->snd.snd] == fcolor[it->snd.fst]) && fcolor[it->snd.fst] == 1) ok = 1;
			//~ if(ok) break;
		//~ }
		//~ resetear();
		//~ fcolor[aux.snd.fst] = fcolor[aux.snd.snd] = 1;
		//~ forall(it,e){ 
			//~ if(fcolor[it->snd.fst] == -1) fcolor[it->snd.fst] = 0;
			//~ if(fcolor[it->snd.snd] == -1) fcolor[it->snd.snd] = 0;
			//~ if((fcolor[it->snd.snd] == fcolor[it->snd.fst]) && fcolor[it->snd.fst] == 0) ok = 1;
			//~ if(ok) break;
		//~ }
	//~ }
	
	return ok;
} //TODO;

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
	
	int n, m; cin >> n >> m;
	uf.init(n);
	map<int, int> rep;
	forn(i,m){
		int a,b,w;cin >> a >> b >> w; a--; b--;
		edges.pb(mp(-w,mp(a,b)));
		rep[-w]++;
	}
	sort(edges.begin(), edges.end());
	memset(color,-1,sizeof(color));
	bool ok = 1;
	forn(i,m){
		int tam = rep[edges[i].fst];
		if(ok == 0) break;
		if(tam > 1){
			//~ cout << " entro aca " << abs(edges[i].fst) << " : " << i << '\n';
			int j = i;
			ok &= procesar(); // aca tengo que chequear si el grafo sigue siendo bipartito
			//~ forn(xd,n) cout << color[xd] << " ";
			//~ cout << endl; 
			//~ cout << ok << endl;
			q.clear();
			if(ok == 0) break;
			//~ cout << "Hasta aca puedo: " << abs(edges[i].fst) << endl;
			while(j < m && edges[i].fst == edges[j].fst){
				q.pb(edges[j]);
				e.pb(edges[j]);
				j++;
			} 
			bool can=check();  //TODO
			e.clear();
			//ahora tengo que ver si estos edges se pueden colocar de manera que haya al menos dos que esten en diferentes colores
			if(can) ans.pb(abs(edges[i].fst));
			i=j-1;
		}
		else q.pb(edges[i]);
	}
	ok&=procesar();
	if(ok) ans.pb(0);
	if(ans.empty()) cout << "IMPOSSIBLE\n";
	else {
		sort(ans.begin(), ans.end());
		forn(i,sz(ans)) cout << ans[i] << '\n';
	}
	
	#ifdef ANARAP
	t1 = clock();double time = (double(t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;
	#endif
	return 0;
}


