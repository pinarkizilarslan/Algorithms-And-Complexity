# Algorithms And Complexity

#### Bubble Sort
Time complexity: Average is O(n²).
Bubble goes through list comparing adjacent element pairs and swaps pairs based on value.

#### Selection Sort
Time complexity: Average is O(n²) and best case is O(n²).
Selection goes through the list taking out the minimum element and, starting at the beginning, placing them in order.

### Insertion Sort
Time complexity: Average is O(n²) and best is O(n).
Iterate over list and place each element in its correct place as you get to it from first to last.

#### Merge Sort
Time complexity: All three cases are O(nlogn).
Split arrays in half to create already sorted single element arrays and merge sorted arrays back together putting everything in the proper order.

#### Quick Sort
Time complexity: Average case is O(nlogn).
Using a pivot point element, the array is split into two parts where everything below the pivot point is smaller and everything above the pivot is larger. The pivot point then moves between the values on the left, putting them sequentially and then the values on the right. This is a "divide and conquer" algorithm because it involves making the larger list into smaller lists that are easier to sort.

#### Heap Sort
Time complexity: All cases are O(nlogn).
Using a tree based data structure for storing elements in a sorted fashion.

#### Radix Sort
Time complexity: Average and best is O(nk).
Radix uses bits to sort by digits, starting with first or last digit.

#### Counting Sort.
Time complexity: Average and best is O(n+k).
Counting sorts by keeping track of the amount of times each value appears in the input list.
