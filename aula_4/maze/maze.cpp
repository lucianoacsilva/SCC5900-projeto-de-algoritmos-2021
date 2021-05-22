#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

#define MAX 800

typedef pair<int,int> pi;


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

bool achaCaminho(int x, int y){
	int nx, ny;
	queue<pi> q;
	q.push(make_pair(x,y));
	sol[x][y] = 1;
	pi par;

	while (!q.empty()){
		par = q.front(); q.pop();

		// se chegou ao fim...
		if (par.first == n-1 && par.second == n-1 && maze[par.first][par.second] == 1){
			return true;
		}

		//para todos os movimentos possiveis
		for (int i = 0; i < 4; ++i)
		{
			nx = par.first + moves[i][0];
			ny = par.second + moves[i][1];

			if (valido(nx,ny)){
				sol[nx][ny] = 1;
				q.push(make_pair(nx,ny));
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