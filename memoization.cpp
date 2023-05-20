//How does dynamic programming work?
//*The programs use extra memory to store the solution to sub problems and avoid recomputation.
//TOP-DOWN DP:
//  *If a certain state has been computed before, simply return the value from the DP memo table
//  *If the state has not been computed, perform the computation as per normal and then store the comped value in the DP memo table and return it
//In essence, top-down DP is just recursive backtracking with storage to quicken it up.
//BOTTOM-DOWN DP:
//  *Create a DP memo table with known values (base cases) initialized
//  *Now, with the base-case cells in the DP table filled, determine the cells/states that can be filled next. Repeat until the DP table is complete

//UVa 11450-Wedding Shopping
//The abridged problem statement: Given different options for each garment (e.g. 3 shirt models, 2 belt models, 4 shoe models, . . . ) 
//and a certain limited budget, our task is to buy one model of each garment. We cannot spend more money than the given budget, 
//but we want to spend the maximum possible amount.

//The input consists of two integers 1 ≤ M ≤ 200 and 1 ≤ C ≤ 20, where M is the budget and C is the number of garments that you have to buy, 
//followed by some information about the C garments. For the garment g ∈ [0..C-1], we will receive an integer 1 ≤ K ≤ 20 which indicates the 
//number of different models there are for that garment g, followed by K integers indicating the price of each model ∈ [1..K] of that garment g.

//ABRIDGED SOLUTION:

#include <iostream>
using namespace std;

int M, C, price[25][25];
int memo[210][25];
int shop(int money, int g) {
	if (money < 0) return -100000000;
	if (g == C) return M - money;
	if (memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for (int model = 1; model <= price[g][0]; model++) {
		ans = max(ans, shop(money-price[g][model], g+1));
	}
	return memo[money][g] = ans;
}
