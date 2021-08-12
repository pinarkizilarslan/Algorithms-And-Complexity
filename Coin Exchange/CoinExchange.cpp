#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int MinCoinExchangeDP(vector<int> &coins, int amount) {

	if (amount == 0) //base case
		return 0;
	if (amount < 0) //base case
		return 0;
	if (coins.size() == 0) //base case
		return 0;
	
	int n = coins.size(); //size of coins

	vector<int> vec(amount + 1); //vec[i] will be storing the minimum number of coins required for i value. So vec[V] will have result.
	
	vec[0] = 0; //base case
		
	for (int i = 1; i <= amount; i++) //initialize table values as INT_MAX 
		vec[i] = INT_MAX;


	for (int i = 1; i <= amount; i++) //Compute minimum coins required for all values from 1 to amount 
	{		
		for (int j = 0; j < n; j++) //go through all coins smaller than i
		{
			if (coins[j] <= i)
			{
				int sub_res = vec[i - coins[j]];

				if (sub_res != INT_MAX && sub_res + 1 < vec[i]) {
					vec[i] = sub_res + 1;
				}
			}
		}			
	}
	return vec[amount];

} //end-MinCoinExchangeDP

int main() {

	// Test1
	// Greedy would return: 2x25 + 6x3 = 8 coins
	// Optimal Solution:    1x25 + 2x20 + 1x3 = 4 coins
	vector<int> coins = { 1, 3, 20, 25 };
	int amount = 68;
	int noCoins = MinCoinExchangeDP(coins, amount);
	if (noCoins == 4) return 10;

	// Test2
	// Greedy would return: 2x30 + 1x10 + 1x5 + 2x1 = 6 coins
	// Optimal solution:    4x18 + 1x5 = 5 coins
	vector<int> coins = { 1, 5, 10, 18, 30 };
	int amount = 77;
	int noCoins = MinCoinExchangeDP(coins, amount);
	if (noCoins == 5) return 15;

	return 0;

} //end-main