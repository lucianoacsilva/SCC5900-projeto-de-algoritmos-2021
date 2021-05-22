#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define MAX 800

typedef pair<int,int> pi;
pair<int,int> manh[600];


int n;
short int maze[MAX][MAX];
short int sol[MAX][MAX];



int moves[4][2] = {1,0,
                   0,1,
                  -1,0,
                   0,-1};


void printMat (short int mat[MAX][MAX]){

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool valido(int x, int y){
	if (x < n && x >= 0 && y < n && y >= 0 && maze[x][y] == 1 && sol[x][y]==0)
		return true;
	return false;
}

float h_man(int x, int y) {
	int ret = 0;
		
	ret += sqrt(pow(abs(x - (n - 1)), 2) + pow(abs(y - (n - 1)), 2));
	
	return ret;
}

bool achaCaminho(int x, int y){
	int nx, ny;
	pi next[8];
	priority_queue<pair<int, pi>> q;
	q.push(make_pair(0,make_pair(x,y)));
	sol[x][y] = 1;
	pair<int, pi> par;

	while (!q.empty()){
		par = q.top(); q.pop();

		// se chegou ao fim...
		if (par.second.first == n-1 && par.second.second == n-1 && maze[par.second.first][par.second.second] == 1){
			return true;
		}

		//para todos os movimentos possiveis
		for (int i = 0; i < 4; ++i)
		{
			nx = par.second.first + moves[i][0];
			ny = par.second.second + moves[i][1];

			if (valido(nx,ny)){
				sol[nx][ny] = 1;
				float f = h_man(nx, ny);
				q.push(make_pair(-f, make_pair(nx, ny)));
			}
		}

	}

	return false;
}


int main(int argc, char const *argv[])
{
	memset(sol, 0, sizeof sol);
	cin >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> maze[i][j];
		}

	

	if (achaCaminho(0,0))
		cout << "Encontrei um caminho" << endl;
	else cout << "Nao existe um caminho para este caso" << endl;


		printMat(sol);

	return 0;
}