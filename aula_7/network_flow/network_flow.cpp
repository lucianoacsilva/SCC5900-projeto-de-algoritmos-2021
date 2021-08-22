#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define V 4

using namespace std;

int graph[V][V] = {{0, 3, 2, 0},
                   {0, 0, 5, 2},
                   {0, 0, 0, 3},
                   {0, 0, 0, 0}};

int residualGraph[V][V];
int pai[V];

bool caminho(int s, int t){
	queue<int> q;
    int visitado[V];
    memset(visitado, 0, sizeof(visitado));

	q.push(s);  // coloca u na fila.....
    pai[s] = -1;
    visitado[s] = 1;

	while (!q.empty()) {

		int u = q.front(); q.pop(); // retira o vertice da fila...
        visitado[u] = 1;

		for (int v = 0; v < V; ++v) // para todos adj v de k
		{
            // Only enters in queue if it has residual
			if (residualGraph[u][v] > 0 && visitado[v] == 0)
            {
                q.push(v);
                pai[v] = u;
                visitado[v] = 1;
            }
            
		}
	}
	
    // verifies if exists path from s to t
    return (visitado[t] == 1);
}

int ff()
{
    int u, v;

    // Copies original graph to residual graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            residualGraph[i][j] = graph[i][j];
        }
    }

    int s = 0;
    int t = 3;
    pai[s] = -1;
    int maxFlow = 0;

    while (caminho(s, t))
    {
        int bottleneck = 100000;

        // Calculates limitant bottleneck
        for (int v = t; v != s; v = pai[v])
        {
            u = pai[v];
            bottleneck = min(bottleneck, residualGraph[u][v]);
        }

        // Updates forward and backward edges
        for (int v = t; v != s; v = pai[v])
        {
            u = pai[v];
            residualGraph[u][v] -= bottleneck;
            residualGraph[v][u] += bottleneck;
        }   

        maxFlow += bottleneck;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
