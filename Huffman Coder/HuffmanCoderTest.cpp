#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

extern int HuffmanCoder(vector<unsigned char>& data, vector<unsigned char>& codewordLengths);

///-----------------------------------------------------
/// Test1
///
int Q2Test1() {
	vector<unsigned char> data = { 'a', 'b', 'a', 'c', 'd', 'a', 'a', 'c', 'a', 'c' };
	vector<unsigned char> codewords(256);
		
	int noBits = HuffmanCoder(data, codewords);
	if (noBits != 17) return 0;

	if (codewords['a'] != 1) return 0;
	if (codewords['b'] != 3) return 0;
	if (codewords['c'] != 2) return 0;
	if (codewords['d'] != 3) return 0;

	for (int i = 0; i < 97; i++) if (codewords[i] != 0) return 0;
	for (int i = 'e'; i < 256; i++) if (codewords[i] != 0) return 0;

	return 10;
} //end-Q1Test1

///-----------------------------------------------------
/// Test2
///
int Q2Test2() {
	vector<unsigned char> data = { 97, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 99, 
		                          100, 100, 100, 101, 101, 102, 102, 102};
	vector<unsigned char> codewords(256);

	int noBits = HuffmanCoder(data, codewords);
	if (noBits != 42) return 0;

	if (codewords[97] != 4) return 0;
	if (codewords[98] != 1) return 0;
	if (codewords[99] != 4) return 0;
	if (codewords[100] != 3) return 0;
	if (codewords[101] != 3) return 0;
	if (codewords[102] != 3) return 0;
	for (int i = 0; i < 97; i++) if (codewords[i] != 0) return 0;
	for (int i = 103; i < 256; i++) if (codewords[i] != 0) return 0;

	return 15;
} //end-Q2Test2

///------------------------------------------------------
/// Test for HuffmanCoder
///
int Q2Test() {
	int grade = 0;

	grade += Q2Test1();
	grade += Q2Test2();

	return grade;
} //end-Q2Test