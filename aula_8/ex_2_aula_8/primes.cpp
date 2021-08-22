#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<int> vi;

ll tamCrivo;

bitset<10000010> crivo;    // 10^7 é um tamanho bom para a MAIORIA dos casos...
vector<ll> primos;         // vetor que armazena os primo....

void criaCrivo(ll max){
	tamCrivo = max+1;

	crivo.set();  // todos os bits em 1...
	crivo[0] = crivo[1] = 0;

	for (ll i = 2; i < max+1; ++i) {  // para todos os valores
		if (crivo[i]){   // este nro é primo... marca como primo e apaga os seus multiplos...
			primos.push_back(i);
			for (ll j = i*i; j < max+1; j+=i) // para todo multiplo de i
				crivo[j] = 0;  // diz que nao eh primo
		}
	}
}


vi fatoresPrimos(ll N){
	vi fatores;

	int ind = 0; int fp = primos[ind];  // fp contem o primo...

	while (N != 1 && (fp*fp <= N)){    // fp = 2, 3, 5, 7,,,,,,
		while (N % fp == 0) {
			N =  N / fp;
			fatores.push_back(fp);
			fp = primos[++ind];
		}

	}

	return fatores;
}


bool isPrime(ll n){
	if (n <= tamCrivo)
		return crivo[n];      // Verifica se eh primo em O(1) !!!!

	for (int i = 0; i < primos.size() && primos[i]*primos[i] <= n; ++i){  // para todos os primos calculados na faixa do crivo
		if (n % primos[i] == 0){
			cout << "divisor = " << primos[i] << endl;
			return false;
		}
	}
	return true;
}



int main(int argc, char const *argv[])
{
	criaCrivo(10000000);   // cria o crivo....

	// faca o que quiser....

	printf("%d\n", isPrime(13));
	printf("%d\n", isPrime(9999900101132311LL));


	return 0;
}