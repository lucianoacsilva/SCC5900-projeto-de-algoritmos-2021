#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
#define MAX 6

int peso[6] = {2, 4, 4, 7, 2, 1};
int p[6] = {0, 0, 1, 0, 3, 3};
int MEMO[MAX];

int wispREC(int j) {
    if (j == 0)
    {
        return 0;
    }

    return max(peso[j] + wispREC(p[j]), wispREC(j - 1));
    
}

int wispRECPD(int j) {
    if (j == 0)
    {
        return 0;
    }

    // if has already calculated, returns value and does not calculate agian
    if (MEMO[j] != -1)
    {
        return MEMO[j];
    }
    
    MEMO[j] = max(peso[j] + wispREC(p[j]), wispREC(j - 1));
    return MEMO[j];
    
}

int main(int argc, char const *argv[])
{
    cout << "O maior valor do WISP é " << wispREC(MAX - 1) << endl;
    memset(MEMO, -1, sizeof MEMO);

    cout << "O maior valor do WISPPD é " << wispRECPD(MAX - 1) << endl;
    memset(MEMO, -1, sizeof MEMO);
    return 0;
}
