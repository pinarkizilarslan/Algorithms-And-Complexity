#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

enum DIR { DOWN = 1, RIGHT = 2, EMPTY = 3 };

struct Index {
	int i, j;
	Index(int _i, int _j) {
		i = _i; j = _j;
	}
};

///------------------------------------------------------
/// You are given a NxN matrix with each slot containing a number 
/// indicating the cost of going through that slot
/// Initially you are at(0, 0)
/// You are only allowed to go Down or Right
/// You want to go to(N - 1, N - 1)
/// Find the path that has the minimum total cost
///
int MinimumCostPath(vector<vector<int>>& M, vector<Index>& Path) {

	int N = M.size(); //size of the given M table

	vector<vector<DIR>> dirsTable; //the table of directions

	vector<vector<int>> solTable; //the table of solutions


	for (int i = 0; i < N; i++) {

		solTable.push_back(vector<int>()); //to set solTable as default
		dirsTable.push_back(vector<DIR>()); //to set dirsTable as default

		for (int j = 0; j < M[i].size(); j++) {
			solTable[i].push_back(-1);
			dirsTable[i].push_back(EMPTY);
		}
	} //end-for

	solTable[N-1][N-1] = M[N-1][N-1];

	for (int i = N - 2; i >= 0; i--) { //to calculate last column - row
		
		solTable[i][N - 1] = M[i ][N - 1] + solTable[i + 1][N - 1];
		dirsTable[i][N - 1] = DOWN;

		solTable[N - 1][i] = M[N - 1][i] + solTable[N - 1][i + 1];
		dirsTable[N - 1][i] = RIGHT;
	} //end-for


	for (int i = N-2; i >=0; i--) {	//to calculate other cells

		for (int j = N - 2; j >=0; j--)	{

			if (solTable[i][j + 1] <= solTable[i + 1][j]) {
				solTable[i][j] = M[i][j] + solTable[i][j + 1];
				dirsTable[i][j] = RIGHT;
			}

			else {
				solTable[i][j] = M[i][j] + solTable[i + 1][j];
				dirsTable[i][j] = DOWN;
			}
		}
	} //end-for

	int S = 0;
	int C = 0;

	Index *tmp = new Index(S, C);
	Path.push_back(*tmp);

	while (dirsTable[S][C]!=EMPTY) // to sets the path
	{
		if (dirsTable[S][C] == DOWN)
			tmp = new Index(++S, C);
		
		else if(dirsTable[S][C] == RIGHT)		
			tmp = new Index(S, ++C);
		
		Path.push_back(*tmp);
	}

	return solTable[0][0];

} //end-MinimumCostPath