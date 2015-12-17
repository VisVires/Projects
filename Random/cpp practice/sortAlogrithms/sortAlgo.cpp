#include <iostream>
#include "sortAlgo.h"

using std::vector;

//swap two values
void swapVal(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

//bubble sort algorithm
void bubbleSort(vector<int>& a)
{
    //get size
    vector<int>::size_type n = a.size();
    bool swapped = true;
    int j = 0;
    //move through vals until no more swaps occur
    while(swapped)
    {
        swapped = false;
        j++;
        for(unsigned int i = 0; i < n - j; ++i)
        {
            //if you find values not in order swap
            //and set swapped to true
            if(a[i] > a[i + 1])
            {
                swapVal(a[i], a[i + 1]);
                swapped = true;
            }

        }
    }
}

//insertion sort algorithm
void insertionSort(vector<int> &a)
{
    //move through entire set and swap each val with
    //its neighbor if smaller
    for(vector<int>::size_type i = 1; i < a.size(); ++i)
    {
        vector<int>::size_type j = i;
        while(j > 0 && a[j-1] > a[j])
        {
            swapVal(a[j], a[j-1]);
            j--;
        }
    }
}

//selection sort
void selectionSort(vector<int>& a)
{
    unsigned int i, j, minimum;
    //iterate through set
    for(j = 0; j < a.size()-1; ++j)
    {
        //set minimum at lowest unsorted val
        minimum = j;
        for(i = j + 1; i < a.size(); ++i)
        {
            //iterate through entire set to find
            //minimum of entire set
            if (a[i] < a[minimum])
            {
                minimum = i;
            }
        }
        //if not j then swap with j
        if(minimum != j){
            swapVal(a[j], a[minimum]);
        }
    }
}

//shell sort
void shellSort(std::vector<int> &a)
{
    unsigned int gap, i, j;
    vector<int>::size_type n = a.size();
    //set gap equation to n/2 then divide gap by two until gap == 0
    for(gap = n/2; gap > 0; gap /=2)
    {
        //set i to gap and move through vector
        for(i = gap; i < n; ++i)
        {
            //for each j compare and swap with j spaced gap away
            for(j = i; j >= gap && a[j] < a[j-gap]; j -= gap)
            {
                swapVal(a[j], a[j-gap]);
            }
        }
    }
}

//quickSort
void quickSort(std::vector<int> &a, int left,int right)
{
    int i = left, j = right;
    int pivot = a[(left + right) / 2];

      /* partition */
    while (left > j || i < right )
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swapVal(a[i], a[j]);
            i++;
            j--;
        }
        else
        {
        /* recursion */
            if (left < j)
                quickSort(a, left, j);
            if (i < right)
                quickSort(a, i, right);
            return;
        }
    }
}


//heap sort
void heapSort(std::vector<int> &a)
{
    //heapify
    heapify(a);
    //last = vector size - 1
    int last  = a.size() - 1;
    //while last > 0 swap root and largest value
    while(last > 0)
    {
        //decrement last
        last--;
        //percolate last value down

    }
}

void heapify(std::vector<int> &a)
{
    int start;

    //assign start to last parent node(find parent of last element)
   start = a.size()/2;
   //place all nodes below start index in heap order
   do
    {
        percolateDown(a, start, a.size()-1);
        start--;
    }
    while(start >= 0);
}

void percolateDown(std::vector<int> &a,int start,int last)
{
    //set start as root node
    int root = start;
    //while root has at least one child
    while(root * 2 + 1 <= last)
    {
        //go to  left child
        int child = root * 2 + 1;
        int sw = root;
        //if left child is greater set as swap
        if (a[sw] < a[child])
            child = sw;
        //if right child exists and is greater set swap
        if(child + 1 <= last && a[sw] < a[child + 1])
            sw = child + 1;
        //if root holds largest element we are done
        if(sw == root)
            return;
        //swap root and value and set new root to sw
        else
        {
             swapVal(a[root], a[sw]);
             root = sw;
        }

    }

}
