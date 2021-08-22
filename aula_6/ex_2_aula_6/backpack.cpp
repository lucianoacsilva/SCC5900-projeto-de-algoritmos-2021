#include <bits/stdc++.h>
using namespace std;

int price[200];
int weight[200];
int dp[200][200];
int max_weight_per_person, people_in_family, N;

int buying(int index, int current_weight){
	// Runned through all possible objects
	if(index == N) return 0;
	
	// Already exists a solution for that object's price and
    // its weight
	if(dp[index][current_weight] != -1) return dp[index][current_weight];

	int sub_problem_1 = 0;
	int sub_problem_2 = 0;

	// Calculates subproblem 1 considering weight of the item 
	// (only if person affords the weight of new item)
	if(current_weight + weight[index] <= max_weight_per_person){
		sub_problem_1 = price[index] + buying(index + 1, current_weight + weight[index]);
	}
	
	// Calculates subproblem 2 not considering the weight of current item
	sub_problem_2 = buying(index + 1, current_weight);

	// Stores price in the dp table for future use and returns it as solution for the subproblem
	dp[index][current_weight] = max(sub_problem_1, sub_problem_2);

	return dp[index][current_weight];
}

int main() {
	int T;

	// Number of test cases
	cin >> T;
	
	while(T--){
		// Number of products
		cin >> N;

		for(int i = 0; i < N; i++){
			cin >> price[i] >> weight[i];
		}

		int answer = 0;
		int count = 0;

		// Nuber of people_in_family in family
		cin >> people_in_family;
		
		while(count < people_in_family){
			memset(dp, -1, sizeof dp);
			cin >> max_weight_per_person;
			answer += buying(0,0);

			// Increments counter
			count = count + 1;
		}

		cout << answer << endl;
	}

	return 0;
}