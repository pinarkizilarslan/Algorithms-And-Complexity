#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

enum DIR { DOWN = 1, RIGHT = 2 };
struct Index { int i, j; Index(int _i, int _j) { i = _i; j = _j; } };
extern int MinimumCostPath(vector<vector<int>>& M, vector<Index>& Path);

///-----------------------------------------------------
/// Test1
///
int Q3Test1() {
	vector<vector<int>> M = { {0, 1, 5},
							  {2, 4, 2},
							  {1, 3, 0} };
	vector<Index> Path;
	vector<Index> sol = { Index(0, 0), Index(1, 0), Index(2, 0), Index(2, 1), Index(2, 2) };
	int cost = MinimumCostPath(M, Path);

	if (cost != 6) return 0;
	if (Path.size() != sol.size()) return 0;

	for (size_t i = 0; i < sol.size(); i++) {
		if (sol[i].i != Path[i].i) return 0;
		if (sol[i].j != Path[i].j) return 0;
	} //end-for

	return 10;
} //end-Q3Test1

///-----------------------------------------------------
/// Test2
///
int Q3Test2() {
	vector<vector<int>> M = { {0, 3, 1, 2, 3},
							  {2, 3, 1, 9, 4},
							  {2, 4, 1, 2, 3},
							  {1, 2, 3, 4, 2},
							  {5, 4, 5, 2, 0} };

	vector<Index> Path;
	vector<Index> sol = { Index(0, 0), Index(0, 1), Index(0, 2), 
		                  Index(1, 2), Index(2, 2), Index(2, 3),
	                      Index(2, 4), Index(3, 4), Index(4, 4)};
	int cost = MinimumCostPath(M, Path);

	if (cost != 13) return 0;
	if (Path.size() != sol.size()) return 0;

	for (size_t i = 0; i < sol.size(); i++) {
		if (sol[i].i != Path[i].i) return 0;
		if (sol[i].j != Path[i].j) return 0;
	} //end-for

	return 15;
} //end-Q3Test2

///------------------------------------------------------
/// Test for MinCostPath
///
int Q3Test() {
	int grade = 0;

	grade += Q3Test1();
	grade += Q3Test2();

	return grade;
} //end-Q3Test