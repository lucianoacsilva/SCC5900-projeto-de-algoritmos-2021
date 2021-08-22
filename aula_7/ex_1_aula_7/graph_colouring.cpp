#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

#define VISITADO 0
#define NOTVISITADO 1
#define SEMCOR -1

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi vertexes;
vector <vii> lista_adj(100);
vi ts;

// um vetor de vértices
vi cor;

bool bipartite(int u){
	queue<int> q;

	cor[u] = 0; // comecaremos com a cor 0
	q.push(u);  // coloca u na fila.....

	while (!q.empty()) {

		int k = q.front(); q.pop(); // retira o vertice da fila...

		for (int i = 0; i < lista_adj[k].size(); ++i) // para todos adj v de k
		{
			ii v = lista_adj[k][i]; // aqui v é um par...
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

int main() {

	int n, l, i, j;

	while(scanf("%d %d", &n, &l) == 2){
		if (n == 0) {
			break;
		}

		for (int a = 0; a <= n; a++) {
			cor.push_back(SEMCOR);
		}

		for (int b = 0; b < l; b++) {
			scanf("%d %d", &i, &j);
			//inicializar grafo
			lista_adj[i].push_back(make_pair(j , 0));
			lista_adj[j].push_back(make_pair(i , 0));

		}

		if(bipartite(0)) {
			cout << "BICOLORABLE." << endl;
		}

		else {
			cout << "NOT BICOLORABLE." << endl;
		}
		
	}

	return 0;
}