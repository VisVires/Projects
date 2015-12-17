#include <iostream>
#include "sortAlgo.h"

using std::cout;        using std::cin;
using std::endl;        using std::vector;

void printVector(vector<int>&);

int main()
{
    cout << "Please enter 10 numbers" << endl;
    int number = 0;
    int input;
    vector<int> numbers;
    while(number != 10)
    {
        cin >> input;
        numbers.push_back(input);
        ++number;
    }

    printVector(numbers);
    //bubbleSort(numbers);
    //insertionSort(numbers);
    //selectionSort(numbers);
    //shellSort(numbers);
    //heapSort(numbers);
    quickSort(numbers, numbers[0], numbers[numbers.size()]);
    printVector(numbers);

    return 0;
}

void printVector(vector<int>& nums)
{
    for(unsigned int x = 0; x < nums.size(); ++x)
    {
        cout << nums[x] << ", ";
    }
    cout << endl;
}
