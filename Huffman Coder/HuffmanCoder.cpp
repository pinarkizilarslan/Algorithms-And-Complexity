#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

///------------------------------------------------------
/// Given some data where each data element is represented by
/// an 8-bit fixed-length codeword, run the Huffman coder
/// and return the length of the variable-length codeword for each
/// of the 256 symbols. Also return the total number of bits required
/// to encode the data using the variable-length codewords
/// Requirement: You must make use of a min-heap in your implementation
///

struct Nodes {

	unsigned char value;
	int frequency;

	Nodes *right;
	Nodes *left;

	Nodes(unsigned char _value,int _frequency) {
		left = right = NULL;
		frequency = _frequency;
		value = _value;
	}

}; //end-Struct Nodes

struct comparison {

	bool operator()(Nodes* l, Nodes* r) {
		return (l->frequency > r->frequency);
	}

}; //end-Struct comparison

void countBits(Nodes *root, string str, int &counts, vector<unsigned char> &wordLength, vector<unsigned char> &frequency) {

	if (!root)
		return;

	if (root->right == NULL && root->left == NULL) {

		counts += (frequency[root->value] * str.length());
		wordLength[root->value] = str.length();
	}

	countBits(root->right, str + "1", counts, wordLength, frequency);
	countBits(root->left, str + "0", counts, wordLength, frequency);

} //end-countBits


int HuffmanCoder(vector<unsigned char> &data, vector<unsigned char> &codewordLengths) {

	vector <unsigned char> frequency(256);

	for (int i = 0; i < data.size(); i++)
		frequency[data[i]]++;
	
	priority_queue <Nodes*, vector<Nodes*>, comparison> Queue; //to create a priority queue

	for (int i = 0; i < frequency.size(); i++) {

		if (frequency[i] != 0)
			Queue.push(new Nodes(i, frequency[i]));
	} //end-for

	while (1 < Queue.size()) { //Queue has more than 1 elements

		Nodes *left = Queue.top();
		Queue.pop();
		Nodes *right = Queue.top();
		Queue.pop();

		Nodes *tmp = new Nodes(NULL, (left->frequency + right->frequency));
		tmp->right = right;
		tmp->left = left;

		Queue.push(tmp);

	} //end-while

	int count = 0; //number of bits required to encode data
	countBits(Queue.top(), "", count, codewordLengths, frequency);

	return count;

} //end-HuffmanCoder