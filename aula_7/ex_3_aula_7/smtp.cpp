#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

// par de inteiros: guarda o vertice v e o peso da aresta
typedef pair<int, int> ii;

// todos os vertices v adjacentes a u
typedef vector<ii> vii;

// lista de adjacencia para todo vertice u do meu grafo..
vector<vii> AdjList(200);

typedef vector<int> vi;

#define INF 10000000

vi d; // vetor de distancia....
vi pai;

void dijkstra(int s, int nv)
{
    // cria uma lista MIN HEAP !!!
    priority_queue<ii, vector<ii>, greater<ii>> q;

    d.assign(nv, INF);
    pai.assign(nv, -1);
    d[s] = 0; // a distancia de u para u eh zero.
    q.push(ii(0, s));

    while (!q.empty())
    {
        ii k = q.top();
        q.pop();
        int dist = k.first;
        int u = k.second;

        if (dist == d[u])
        {
            for (int i = 0; i < (int) AdjList[u].size(); ++i)
            { // para todo adjacente v de u
                ii v = AdjList[u][i];
                if (d[u] + v.second < d[v.first])
                {                                 // relaxa o vertice v
                    d[v.first] = d[u] + v.second; // o nivel do adj v eh o do pai k + 1
                    pai[v.first] = u;
                    q.push(ii(d[v.first], v.first)); // coloca o adj na fila...
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int testCases;

    cin >> testCases;

    for (int k = 0; k < testCases; k++)
    {
        int A, V, s, t;

        cin >> V;
        cin >> A;
        cin >> s;
        cin >> t;

        int u, v, w;

        // Reinicializa lista de adjacências
        AdjList.assign(V, vii());

        for (int i = 0; i < A; ++i)
        {
            cin >> u >> v >> w;
            AdjList[u].push_back(make_pair(v, w));
            AdjList[v].push_back(make_pair(u, w));
        }

        dijkstra(s, V);
        
        if (d[t] != INF)
        {
            cout << "Case #" << k + 1 << ": " << d[t] << endl;
        } else {
            cout << "Case #" << k + 1 << ": " << "unreachable" << endl;
        }
    }
    
    return 0;
}
