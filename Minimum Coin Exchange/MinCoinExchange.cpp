#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int MinCoinExchange(vector<int> &coins, int amount) {

	if (amount == 0) //base case
		return 0;

	int coinsNo = 0; //number of coins
	int sum = 0; //sum of coins values

	sort(coins.begin(), coins.end()); //sorting coins

	int iter = coins.size() - 1; //iter traveling in coins

	while (amount != 0) {

		if (amount >= coins[iter]) { //enter if amount is greater than this coin value
			amount -= coins[iter]; //decrease amount by coin's value
			sum += coins[iter]; //increase sum by coin's value
			coinsNo++; //increase the number of coins used
		}
		else
			iter--;
	}

	if (sum = amount + 1) //enter if sum is equals amount+1
		return coinsNo;

	return 0;

} //end-MinCoinExchange


int main() {
	   
	// Test1
	vector<int> coinsSet1 = { 5, 1, 25, 10 };
	int amount = 68;
	int noCoins = MinCoinExchange(coinsSet1, amount);
	if (noCoins == 7) return 10;

	// Test2
	vector<int> coinsSet2 = { 5, 1, 50, 25, 10 };
	int amount = 77;
	int noCoins = MinCoinExchange(coinsSet2, amount);
	if (noCoins == 4) return 10;
	   
	return 0;

} //end-main