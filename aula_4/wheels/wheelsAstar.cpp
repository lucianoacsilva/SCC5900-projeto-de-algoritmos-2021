#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>


using namespace std;

int manh[20];

struct state{
	int digit[4];
	int depth;

	bool operator<(const state& other) const {
		return this->depth < other.depth;
	}
};

int moves [8][4]= { {-1, 0, 0, 0 },
					 { 1, 0, 0, 0 },
					 { 0,-1, 0, 0 },
					 { 0, 1, 0, 0 },
					 { 0, 0,-1, 0 }, 
					 { 0, 0, 1, 0 },
					 { 0, 0, 0,-1 },
					 { 0, 0, 0, 1 } };


void next_states(state s, state next[8]){
	int i,j;

	for(i=0; i<8; i++){
		next[i] = s;
		next[i].depth = s.depth+1;
		for(j=0; j<4; j++){
			next[i].digit[j] += moves[i][j];
			if (next[i].digit[j]<0)
				next[i].digit[j] = 9;
			if (next[i].digit[j]>9)
				next[i].digit[j] = 0;
		}
	}

}

int h_man(state& s) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		if (s.digit[i] != 0)
			ret += abs(manh[i] - i);
	}
	
	return ret;
}


int equal(state s, state e){
	int i;
	for (i=0; i<4; i++)
		if (s.digit[i] != e.digit[i])
			return 0;

	return 1;
}

bool comparator (state s1, state s2) {
	return s1.depth > s2.depth;
}

int bfs(state current, state final, int visited[10][10][10][10]){
	state next[8];
	int i;
	priority_queue<pair<int, state>> q;

	// o estado inicial pode ser invalido !!!!
	if (!visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]]){
		visited[current.digit[0]][current.digit[1]][current.digit[2]][current.digit[3]] = 1;
		q.push(make_pair(0,current));

		while(!q.empty()) {
			state current = q.top().second;
			q.pop();
			int g = current.depth;
			// chegou no estado final.. basta terminar (este é o nivel minino!!!) e mostrar o nivel que saiu da árvore...!
			if (equal(current, final))
				return current.depth;
			// nao é igual.. entao, calcula todos os proximos estados e continua a busca em largura.....
			next_states(current, next);
			for (i=0; i<8; i++)
				if (!visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]]){
					visited[next[i].digit[0]][next[i].digit[1]][next[i].digit[2]][next[i].digit[3]] = 1;
					int f = g + h_man(next[i]);
					q.push((make_pair(-f, next[i])));
				}
		}
	}
	return -1;
}


int main (){
	int nr_testes, test, forbidden, i,j,k,l,d;
	int visited[10][10][10][10];
	state initial, final, aux;

	scanf("%d", &nr_testes);
	for (test=0; test<nr_testes; test++){
		scanf("%d %d %d %d", &initial.digit[0], &initial.digit[1], &initial.digit[2], &initial.digit[3]);
		scanf("%d %d %d %d", &final.digit[0], &final.digit[1], &final.digit[2], &final.digit[3]);
		scanf("%d", &forbidden);

		for(i=0; i<10; i++)
			for(j=0; j<10; j++)
				for(k=0; k<10; k++)
					for(l=0; l<10; l++)
						visited[i][j][k][l] = 0;

		for(i=0; i<forbidden; i++) {
			scanf("%d %d %d %d", &aux.digit[0], &aux.digit[1], &aux.digit[2], &aux.digit[3]);
			visited[aux.digit[0]][aux.digit[1]][aux.digit[2]][aux.digit[3]] = 1;
		}
		initial.depth=0;
		printf("%d\n", bfs(initial, final, visited));
	}
	return 0;


}