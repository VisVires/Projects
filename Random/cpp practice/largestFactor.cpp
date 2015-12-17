#include <iostream>

using std::cout;    using std::cin;
using std::endl;

long long int largestPrime(long long int x)
{
    int largePrime = 2;
    while(x > largePrime)
    {
        if(x%largePrime == 0)
        {
            x = x / largePrime;
            largePrime = 2;
        }
        else
        {
            largePrime++;
        }
    }
    return largePrime;
}

int main()
{
    long long int num = 600851475143;
    long long int prime = largestPrime(num);

    cout << "\nThe factor is " << prime;

    return 0;
}
