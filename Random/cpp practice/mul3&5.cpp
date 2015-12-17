#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using std::cout;        using std::endl;
using std::cin;         using std::iterator;
using std::vector;


int main()
{
    int i = 0;
    int nsum = 0;

    while(i < 1000)
    {
        if(i%3 == 0 || i%5 == 0)
        {
            nsum += i;
        }
        ++i;
    }
    cout << nsum << endl;

    return 0;
}


