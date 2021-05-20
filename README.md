# Algorithms And Complexity


## Edit Distance
A dynamic programming algorithm that determines the minimum edit distance between X and Y. The edit distance between X and Y to be the minimum number of single character insertions, deletions, and replacements applied to X to make it equal to Y. For example, if X = backache and Y = sackrace, then the edit distance is 3. <br>
The sequence of changes is :

 •	Replace x_1 with  y_1('s')  <br>
 •	Insert  y_5('r') after x_4  <br>
 •	Delete x_7('h') <br>
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
Coins are not given in sorted order. <br>
This is a Greedy Algorithm and works with O(nlogn). <br>
<br>


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
