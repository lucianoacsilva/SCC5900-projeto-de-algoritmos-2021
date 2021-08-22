#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define MAXT 100000
#define MAXP 10000

char texto[MAXT];
char pattern[MAXP];


int main(int argc, char const *argv[])
{
	fgets(texto, MAXT, stdin);
	fgets(pattern, MAXP, stdin);

	texto[strlen(texto)-1] = '\0'; // troca o \n por \0 (fim de string)
	pattern[strlen(pattern)-1] = '\0'; // troca o \n por \0 (fim de string)


	int tamt = strlen(texto);
	int tamp = strlen(pattern);


	// agora vamos a busca....

	for (int i = 0; i < tamt; ++i) { // pra todo caracter do texto....
		bool achei = true;  
		for (int j = 0; j < tamp && achei; ++j) {
			if (i+j>=tamt || texto[i+j] != pattern[j])
				achei = false;            // para a busca.. reseta j....
		}
		if (achei)
			printf("Encontrei o padrao na posicao %d\n", i);

	}

	return 0;
}