#pragma once

class HeapSort
{
public:
	void heapify(int arr[], int n, int i);
	void buildMaxHeap(int arr[], int n);
	void heapSort(int arr[], int n);
};
