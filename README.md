# Algorithms And Complexity


## Coin Exchange
You are given a set of coins {1, 3, 20, 25}, and an amount. Design a dynamic programming algorithm that returns the minimum number of coins necessary to make up for this amount. <br>
For example, assume you have the coins given above, and the amount is 68. <br>
Then the minimum number of coins necessary to make up for this amount is: <br>
 •	1x25 + 2x20 + 1x3 = 25+40+3 = 68 -> 4 coins <br>
Notice that the greedy algorithm would return: <br>
 •	2x25 + 6x3 = 50 + 18 = 68 -> 8 coins <br>
<br>


## Edit Distance
A dynamic programming algorithm that determines the minimum edit distance between X and Y. The edit distance between X and Y to be the minimum number of single character insertions, deletions, and replacements applied to X to make it equal to Y. For example, if X = backache and Y = sackrace, then the edit distance is 3. <br>
The sequence of changes is :

 •	Replace x_1 with  y_1('s')  <br>
 •	Insert  y_5('r') after x_4  <br>
 •	Delete x_7('h') <br>
<br> 


## Find Smallest Interval
Finds the smallest [x..y] interval with at least k in a list of “n” numbers consisting of the given integers A = [a0, a1, …, an-1] and k >=2. <br> 
The numbers of the list fall within this range (The size of the [x..y] range is y-x.) <br> 
The algorithm prints the range at the end.
<br> <br> 


## Huffman Coder 
In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. 
<br> <br> 
You are given an array of N unsigned chars (symbols) where each symbol is represented by 8-bits. Design a Huffman Coder that returns the length of the codeword for each of the possible 256 symbols and the total number of bits required to encode this data. 
Requirement: After computing the frequency of occurrence of each symbol, you must implement a min-heap (priority queue) to implement the Huffman coder. <br> 
For example, given Data = [‘a’, ‘b’, ‘b’, ‘a’, ‘c’, ‘d’, ‘a’, ‘a’, ‘c’, ‘a’, ‘c’] <br> 
Codeword lengths: [1, 3, 2, 3] <br> 
a=0 <br> 
b=110 <br> 
c=10 <br> 
d=111 <br> 
Total number of bits required to encode the data: 17 <br> 
<br> 


## Long Integer Multiplication
In this project the divide-and-conquer long integer multiplication algorithm, whose running time is O(n1.58), was applied.

Program will first prompt for N, the number of digits that each integer has. Then the program will prompt for the name of the file where the first integer is stored, then prompt for the name of the file where the second integer is stored. It will then multiply the integers using the divide-and-conquer long integer multiplication algorithm and write the result to a file named “result.txt”. 

Here is a typical interaction between the user and program:  <br>
Enter N: 1000  <br>
Enter first filename: A.txt  <br>
Enter second filename: B.txt  <br>
The resulting integer is written to 'result.txt'
<br> <br>


## Minimum Coin Exchange
Given a set of coins that includes 1 returns the minimum number of coins necessary to represent the amount. <br>
Coins are not given in sorted order. This is a Greedy Algorithm and works with O(nlogn). <br>
<br>
For example, assume you are given a set of coins {1, 5, 10, 25}, and the amount is 68. Then the minimum number of coins necessary to make up for this amount is: <br>
Two 25 coins <br>
One 10 coin <br>
One 5 coin <br>
Three 1 coins <br>
Total: 7 coins (2x25+1x10+1x5+3x1 = 68). <br>
<br>


## Recursive Insertion Sort
Insertion sort can be expressed as a recursive procedure as follows: <br>
In order to sort A[0..n-1], we recursively sort A[0..n-2] and then insert A[n-1] into the sorted array A[0..n-2].
<br> <br>


## Sorting Algorithms

Bubble Sort: <br>
Time complexity: Average is O(n²). Bubble goes through list comparing adjacent element pairs and swaps pairs based on value.

Selection Sort: <br>
Time complexity: Average is O(n²) and best case is O(n²). Selection goes through the list taking out the minimum element and, starting at the beginning, placing them in order.

Insertion Sort: <br>
Time complexity: Average is O(n²) and best is O(n). Iterate over list and place each element in its correct place as you get to it from first to last.

Merge Sort: <br>
Time complexity: All three cases are O(nlogn). Split arrays in half to create already sorted single element arrays and merge sorted arrays back together putting everything in the proper order.

Quick Sort: <br>
Time complexity: Average case is O(nlogn). Using a pivot point element, the array is split into two parts where everything below the pivot point is smaller and everything above the pivot is larger. The pivot point then moves between the values on the left, putting them sequentially and then the values on the right. This is a "divide and conquer" algorithm because it involves making the larger list into smaller lists that are easier to sort.

Heap Sort: <br>
Time complexity: All cases are O(nlogn). Using a tree based data structure for storing elements in a sorted fashion.

Radix Sort: <br>
Time complexity: Average and best is O(nk). Radix uses bits to sort by digits, starting with first or last digit.

Counting Sort: <br>
Time complexity: Average and best is O(n+k). Counting sorts by keeping track of the amount of times each value appears in the input list.
<br>
