#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// par de inteiros: guarda o vertice v e o peso da aresta
typedef pair<int, int> ii;

// todos os vertices v adjacentes a u
typedef vector<ii> vii;

// lista de adjacencia para todo vertice u do meu grafo..
vector<vii> AdjList(200);

typedef vector<int> vi;

int testCases;
int numberPoints;
int A;
int V;
vi visitado;
priority_queue<ii> pq;

void printAdjList(int nv)
{
    for (int u = 0; u < nv; ++u)
    { // para todo vertice u
        printf("%d -> ", u);
        for (int i = 0; i < AdjList[u].size(); ++i)
        { // para todo adjacente v de u
            ii v = AdjList[u][i];
            printf("(%d, %d) -> ", v.first, v.second);
        }
        printf("\n");
    }
}

void process(int u)
{
    visitado[u] = 1;
    // para todo v adjacente a u
    for (int i = 0; i < AdjList[u].size(); ++i)
    {
        ii v = AdjList[u][i];
        if (!visitado[v.first])
        {
            // lembre-se de que PQ em C++ é MAX HEAP
            pq.push(make_pair(-v.second, -v.first));
        }
    }
}

int main(int argc, char const *argv[])
{
    // cin >> A;
    // cin >> V;

    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        cin >> numberPoints;

        int v, u, w;
        // cria a lista de arestas, onde o peso é o list.first !!!!
        for (int i = 0; i < numberPoints - 1; ++i)
        {
            cin >> u >> v >> w;
            AdjList[u].push_back(make_pair(v, w));
            AdjList[v].push_back(make_pair(u, w));
        }

        printAdjList(V);

        int custo = 0;

        //memset(visitado, 0, sizeof visitado);
        visitado.assign(V, 0);
        process(0); // comece por um vertice arbitrario do grafo

        while (!pq.empty())
        {
            ii el = pq.top();
            pq.pop();

            printf("(%d,%d) *** ", el.first, el.second);
            int w = -el.first;
            int u = -el.second;

            // evite ciclos...
            if (!visitado[u])
            {
                custo += w; // atualiza o custo
                process(u);
            }
        }

        printf("O custo da arvore geradora minima = %d\n", custo);
    }
    return 0;
}