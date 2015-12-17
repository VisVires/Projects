#ifndef SORTALGO_H_INCLUDED
#define SORTALGO_H_INCLUDED

#include <vector>


void swapVal(int &a, int &b);

//O(n^2)
void bubbleSort(std::vector<int>& a);
void insertionSort(std::vector<int>& a);
void selectionSort(std::vector<int>& a);

//O(n log(n^2))
void shellSort(std::vector<int> & a);

//O(nk)
//bucketSort();
//radixSort();

//O(n log(n))
void quickSort(std::vector<int> &a, int left,int right);
void heapSort(std::vector<int> & a);
void heapify(std::vector<int> &a);
void percolateDown(std::vector<int> & a, int, int);
//timSort();
//mergeSort();



#endif // SORTALGO_H_INCLUDED
