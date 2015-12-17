#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using std::cout;    using std::iterator;
using std::cin;     using std::vector;
using std::endl;    using std::string;
using std::stringstream;

bool isSpace(const char &c);

int main()
{
    string str;
    cout << "Give me a string: " << endl;

    vector<string> tokens; // Create vector to hold our words

    while(cin >> str)
    {
        tokens.push_back(str);
    }

    for(vector<string>::size_type i = 0; i < tokens.size(); ++i)
        cout << tokens[i] << endl;
    return 0;
}


