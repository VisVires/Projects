#include <iostream>

using std::cout;    using std::endl;
using std::cin;

int fibo(int x)
{
    if(x == 0)
    {
        return 0;
    }
    else if(x == 1)
    {
        return 1;
    }
    else
        return fibo(x-1) + fibo(x-2);
}

int main()
{
    int sum = 0;
    int num = 0;
    while(fibo(num) < 4000000)
    {
        int fib = fibo(num);
        if(fib%2 == 0)
        {
            sum += fib;
        }
        ++num;
    }

    cout << sum << endl;

    return 0;
}
