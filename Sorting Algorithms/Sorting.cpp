/**
* Algorithm And Complexity(A) Project2
* @author :  152120171063 Pinar Kizilarslan --> e-mail: pinarkzlarslan@gmail.com
* @author :  152120171008 Ayse Kaya --> e-mail: ayssekyaa@gmail.com
* @file :  Sorting.cpp
* @date :  May 12, Tuesday 2020
* @brief :  This code is an implementation of writing and comparing sorting algorithms.
*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include "Sorting.h"
using namespace std;

/****************************************************
 * Uses bubble sort to sort A[0..N-1]
 ****************************************************/
void BubbleSort(int A[], int N) {
	if (N == 1) // Base case
		return;
	// The largest element is moved to end. 
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			swap(A[i], A[i + 1]);
		}
	}
	// The largest element is fixed.
	BubbleSort(A, N - 1);
} //end-BubbleSort

/****************************************************
 * Uses selection sort to sort A[0..N-1]
 ****************************************************/
void SelectionSort(int A[], int N) {
	int i, j, index;
	for (i = 0; i < N - 1; i++)
	{
		// Find the minimum in unsorted array  
		index = i;
		for (j = i + 1; j < N; j++)
		{
			if (A[j] < A[index])
				index = j;
		}
		// Swap the found minimum with the first
		if (i != index)
		{
			swap(A[i], A[index]);
		}
	}
} //end-SelectionSort

/****************************************************
 * Uses insertion sort to sort A[0..N-1]
 ****************************************************/
void InsertionSort(int A[], int N) {
	if (N <= 1) // Base case 
		return;

	// Sort first N-1 elements 
	InsertionSort(A, N - 1);

	// Insert last element at its correct position
	int temp = A[N - 1];
	int i = N - 2;

	while (i >= 0 && A[i] > temp)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = temp;
} //end-InsertionSort

/****************************************************
 * Uses mergesort to sort A[0..N-1]
 ****************************************************/
void MergeSort(int A[], int N) {	
	if (N <= 1) // Base case
		return;

	int mid = N / 2;
	MergeSort(A, mid);
	MergeSort(A + mid, N - mid);
	int *S = new int[N];
	int i = 0, j = mid, k = 0;
	while (i < mid && j < N)
	{
		if (A[i] <= A[j])
		{
			S[k++] = A[i++];
		}	
		else
		{
			S[k++] = A[j++];
		}	
	}
	while (i < mid) // Left
	{
		S[k++] = A[i++];
	}
	while (j < N) //Right
	{
		S[k++] = A[j++];
	}
	for (i = 0; i < N; i++)
	{
		A[i] = S[i];
	}
	delete []S;
} //end-MergeSort

int Partition(int A[],int N) 
{
	if (N <= 1) return 0;
	int pivot = A[0];  // Pivot is the first element
	int i = 1, j = N - 1;

	while (1) {
		while (A[j] > pivot) j--;
		while (A[i] < pivot && i < j) i++;
		if (i >= j) break;
		swap(A[i],A[j]);
		i++; j--;
	} //end-while

	swap(A[j], A[0]); // Restore the pivot

	return j;
} //end-Partition

/****************************************************
 * Uses quicksort sort to sort A[0..N-1]
 ****************************************************/
void QuickSort(int A[], int N) {	
	if (N <= 1) // Base case
		return;

	int index = Partition(A, N);
	QuickSort(A, index);
	QuickSort(A + index+1, N - index-1);
} //end-QuickSort

void Heap(int A[], int N, int i)
{
	int large = i; // Largest is root 
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// Left child is larger than root 
	if (left < N && A[left] > A[large])
	{
		large = left;
	}
	// Right child is larger than largest so far 
	if (right < N && A[right] > A[large])
	{
		large = right;
	}
	// Largest is not root 
	if (large != i)
	{
		swap(A[i], A[large]);

		// Recursively heapify the affected sub-tree 
		Heap(A, N, large);
	}
} //end-Heap

/****************************************************
 * Uses heapsort to sort A[0..N]
 * NOTICE: The first element is in A[0] not in A[1]
 ****************************************************/
void HeapSort(int A[], int N) {
	// Build heap
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		Heap(A, N, i);
	}
	// Removing individual items from heap
	for (int i = N - 1; i > 0; i--)
	{
		swap(A[0], A[i]); // Move root to end
		Heap(A, i, 0);
	}
} //end-HeapSort

int Max(int A[], int N)
{
	int max = A[0];
	for (int i = 1; i < N; i++)
		if (A[i] > max)
			max = A[i];
	return max;
} //end-Max

void Count(int A[], int N, int exp)
{
	int *output=new int[N], i, count[10] = { 0 };

	for (i = 0; i < N; i++)
	{
		count[(A[i] / exp) % 10]++;
	}
	// Change count[i] to contains actual position
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = N - 1; i >= 0; i--)
	{
		output[count[(A[i] / exp) % 10] - 1] = A[i];
		count[(A[i] / exp) % 10]--;
	}
	for (i = 0; i < N; i++)
	{
		A[i] = output[i];
	}		
} //end-Count

/****************************************************
 * Uses radixsort to sort A[0..N]
 ****************************************************/
void RadixSort(int A[], int N) {
	// Find the max
	int max = Max(A, N);

	// Count sort for every digit.
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		Count(A, N, exp);
	}		
} //end-RadixSort

/****************************************************
 * Uses countingsort to sort A[0..N]
 ****************************************************/
void CountingSort(int A[], int N) {

	int i, j, k, index = 0, min, max;

	min = max = A[0];
	for (i = 1; i < N; i++) {
		min = (A[i] < min) ? A[i] : min;
		max = (A[i] > max) ? A[i] : max;
	}

	k = max - min + 1;
	int *S = new int[k];
	for (i = 0; i < k; i++)
	{
		S[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		S[A[i] - min]++;
	}
	for (i = min; i <= max; i++)
	{
		for (j = 0; j < S[i - min]; j++)
		{
			A[index++] = i;
		}
	}
	delete[] S;
} //end-CountingSort