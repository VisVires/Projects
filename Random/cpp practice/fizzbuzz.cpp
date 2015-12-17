#include <iostream>

using std::cout;
using std::cin;

using std::endl;

int main()
{
    int num = 1;
    for (auto i = 0; i != 100; ++i)
    {
        if (num%3 == 0 && num%5 == 0)
            cout << "FizzBuzz" << endl;
        else if (num%3 == 0)
            cout << "Fizz" << endl;
        else if (num%5 == 0)
            cout << "Buzz" << endl;
        else
            cout << num << endl;
        ++num;
    }


    return 0;
}
