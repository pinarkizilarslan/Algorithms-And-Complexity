/**
*  Algorithm And Complexity(A) Project1
*  @author  :152120171063 Pinar Kizilarslan --> e-mail:pinarkzlarslan@gmail.com
*  @author  :152120171008 Ayse Kaya --> e-mail:ayssekyaa@gmail.com
*  @date  :Wednesday, April 8, 2020
*  @brief  :In this project we are implement the divide-and-conquer long integer multiplication algorithm, 
            whose running time is O(n1.58). 
*/
#include"Multiplication.h"
int main()
{
	string FileName1, FileName2;
	string A, B, result;
	int N;
	cout << "Enter N: ";
	cin >> N;

	while (!cin || N < 0)
	{
		cout << "Error, please enter a positive integer !" << endl;
		cout << "Enter N: ";
		cin.clear();
		cin.ignore();
		cin >> N;
	}

	cout << "Enter first filename: ";
	cin >> FileName1;
	cout << "Enter second filename: ";
	cin >> FileName2;

	A = ReadFile(FileName1, N);
	B = ReadFile(FileName2, N);
	multiplication(A, B, result, N);
	WriteFile(result);
	cout << "The result integer is written to 'result.txt'" << endl;

	system("pause");
}