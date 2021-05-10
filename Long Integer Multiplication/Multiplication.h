#include<iostream>
#include<stdio.h> 
#include<math.h>
#include<sstream>
#include<fstream>
using namespace std;
/*
Controls the length of strings.
If the string length is not equal, it equalizes and returns the length of the long one.
Returns the length of the first string, if equal.
*/
int EqualLength(string &str1, string &str2)
{
	int lenght1 = str1.size();
	int lenght2 = str2.size();
	if (lenght1 < lenght2)
	{
		for (int i = 0; i < lenght2 - lenght1; i++)
			str1 = '0' + str1;
		return lenght2;
	}
	else if (lenght1 > lenght2)
	{
		for (int i = 0; i < lenght1 - lenght2; i++)
			str2 = '0' + str2;
		return lenght1;
	}
	else
		return lenght1;
}
/*
Adds two strings to the function and returns the sum.
*/
string add(string first, string second)
{
	string result;
	int sum;
	int carry = 0;  //Initialize carry 
	int length = EqualLength(first, second);
	for (int i = length - 1; i >= 0; i--) {
		sum = (first[i]) % 48 + (second[i]) % 48 + carry; //Use the function of from_character_to_number
		carry = 0; //Reset the plus

		if (sum > 9 && i != 0)
		{
			carry = 1;
			sum %= 10;
		}
		result.insert(0, to_string(sum));
	}
	return result;
}
/*
It is the function where subtract two strings and returns the result.
*/
string subtract(string first, string second)
{
	string result;
	int sub;
	int carry = 0;
	int length = EqualLength(first, second);
	for (int i = length - 1; i >= 0; i--) {
		sub = (first[i]) % 48 - (second[i]) % 48 + carry;
		carry = 0;
		if (sub < 0)
		{
			sub += 10;
			carry = -1;
		}
		result.insert(0, to_string(sub));
	}
	return result;
}
/*
It is the function where the product of two strings is made.
*/
void multiplication(string A, string B, string& result, int n)
{
	n = EqualLength(A, B);

	if (n == 0) //Base cases
	{
		result = to_string(0);
		return;
	}
	if (n == 1)	//Base cases
	{
		result = to_string((A[0] - '0')*(B[0] - '0'));
		return;
	}

	int m = n / 2;
	int k = (n - m);

	string W = A.substr(0, m);
	string X = A.substr(m, k);
	string Y = B.substr(0, m);
	string Z = B.substr(m, k);
	string C, D, E;
	multiplication(W, Y, C, m);
	multiplication(X, Z, D, m);
	string R = add(W, X);
	string T = add(Y, Z);
	multiplication(R, T, E, m);
	E = subtract(E, add(C, D));
	for (int i = 0; i < 2 * (n - m); i++)
	{
		C = C + "0";
	}
	for (int j = 0; j < (n - m); j++)
	{
		E = E + "0";
	}
	result = add(C, add(E, D));
	return;
}
/*
Returns the data in the file as a string.
*/
string ReadFile(string fileName, int len)
{
	ifstream read_file;
	read_file.open(fileName, ios::in);
	ifstream in(fileName);

	in.seekg(0, in.end); //Get the length of the file
	char c;
	string s;
	while (len--)
	{
		in.seekg(len, in.beg);
		in >> c;
		s.push_back(c); //The file data we hold as char is added to the S string.So it turns the char into string.
	}
	return s;
}
/*
Prints the result in a file in the form of a string.
*/
void WriteFile(string data)
{
	ofstream outdata;
	outdata.open("result.txt");
	if (!outdata) //File couldn't be opened
	{
		cerr << "Error: file could not be opened" << endl;
		exit(1);
	}
	reverse(data.begin(), data.end());
	outdata << data;
	outdata.close();
}