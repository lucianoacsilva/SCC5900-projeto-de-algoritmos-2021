#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>


#define SEMCOR -1

using namespace std;

// usando STL para representar grafos

// o par.first -> vértice u, par.second -> peso da aresta
typedef pair<int, int> ii;   

// um vetor de pares
typedef vector<ii> vii;

// vetor apenas. uso genérico... marcar visitados, etc..
typedef vector<int> vi;

// a lista de adjacencia é um vetor de vetor de pares
// seja um vertice (u,v)
// first representa v, e second o peso da aresta !!
// u é cada item do vetor AdjList !! 
vector<vii> AdjList(100);

// um vetor de vértices
vi cor;

int n; // numero de vertices do grafo...

bool bipartite(int u){
	queue<int> q;

	cor[u] = 0; // comecaremos com a cor 0
	q.push(u);  // coloca u na fila.....
	while (!q.empty()) {

		int k = q.front(); q.pop(); // retira o vertice da fila...

		for (int i = 0; i < (int) AdjList[k].size(); ++i) // para todos adj v de k
		{
			ii v = AdjList[k][i]; // aqui v é um par...
			if (cor[v.first] == SEMCOR){
				cor[v.first] = 1 - cor[k];
				q.push(v.first);
			}
			else if (cor[v.first] == cor[k])
				return false;
		}
	}
	return true;
}


int main(int argc, char const *argv[])
{
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}

		// Reinicializa lista de adjacências e vetor de cores
		AdjList.assign(n, vii());
		cor.assign(n, SEMCOR);
		
		int e, u, v;

		// marca todos como não visitados..
		for (int i = 0; i < n; ++i)
			cor.push_back(SEMCOR);

		// ler número de arestas
		cin >> e;

		for (int i = 0; i < e; i++) { // o grafo é NAO direcionado e nao arestas nao tem peso!
			cin >> u >> v;
			AdjList[u].push_back(make_pair(v,0));			
			AdjList[v].push_back(make_pair(u,0));
		}
		
		if (bipartite(0)) {
			cout << "BICOLORABLE." << endl;
		}
			
		else {
			cout << "NOT BICOLORABLE." << endl;
		}	
	}
	
	
	

	return 0;
}