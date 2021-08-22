#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
#define MAX 10

int moedas[MAX] = {1, 3, 4};
int V = 10;
int MEMO[MAX];

void printMEMO(int vet[]) {
    for (int i = 0; i < MAX; i++)
    {
        cout << vet[i] << endl;
    }

    cout << endl;
    
}

int moedaREC(int v) {
    if (v == 0)
    {
        return 0;
    }

    if (v < 0)
    {
        return INT_MAX - 1;
    }

    int menor = INT_MAX;
    for (int i = 0; i < MAX; i++) // for all coins
    {
        menor = min(menor, 1 + moedaREC(v - moedas[i]));    
    }
    
    return menor;
}

int moedaPD(int v) {
    if (v == 0)
    {
        return 0;
    }

    if (v < 0)
    {
        return INT_MAX - 1;
    }

    if (MEMO[v] != -1) // already calculated ...
    {
        return MEMO[v];
    }
    

    int menor = INT_MAX;
    for (int i = 0; i < MAX; i++) // for all coins
    {
        menor = min(menor, 1 + moedaPD(v - moedas[i]));    
    }
    
    MEMO[v] = menor;
    return menor;
}

int moedaIter () {
    for (int j = 0; j < V; j++)
    {
        MEMO[j] = INT_MAX;
        for (int i = 0; i < MAX; i++) // for all coins
        {
            MEMO[j] = min(1 + MEMO[j - moedas[i]], MEMO[j]);    
        }

    }

    return MEMO[V];
    
}

int main(int argc, char const *argv[])
{
    memset(MEMO, -1, sizeof MEMO);
    cout << "A quantidade mínima de moedas é " << moedaIter() << endl;
    printMEMO(MEMO);
    return 0;
}
