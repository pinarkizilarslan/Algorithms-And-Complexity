#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int EditDistance(string &X, string &Y) {
		   
	int m = X.length();
	int n = Y.length();

	int **DP = new int *[m + 1]; //to create a dynamic DP array

	for (int i = 0; i <= m; i++)
		DP[i] = new int[n + 1];
	
	for (int i = 0; i <= m; i++) //to fill the DP array with 0
	{
		for (int j = 0; j <= n; j++)
			DP[i][j] = 0;
	}

	for (int i = 0; i <= m; i++) 
		DP[0][i] = i;

	//to fill the DP
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j <= m; j++) { //to compare from Y string with X string characters

			if (j == 0) //enter if X string is empty
				DP[i % 2][j] = i; //add character to get Y string

			else if (X[j - 1] == Y[i - 1]) //enter if character from both string is same
				DP[i % 2][j] = DP[(i - 1) % 2][j - 1]; //i%2 is for bound the row number

			else 
				DP[i % 2][j] = 1 + min(DP[(i - 1) % 2][j], min(DP[i % 2][j - 1], DP[(i - 1) % 2][j - 1])); //to take the minimum			
		}
	}

	return DP[n % 2][m];

} //end-EditDistance


int main() {

	// Test
	string X = "backache";
	string Y = "sackrace";
	if (EditDistance(X, Y) != 3) return 0;


	return 0;

} //end-main