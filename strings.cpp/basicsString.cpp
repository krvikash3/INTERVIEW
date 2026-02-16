#include <iostream>
using namespace std;

int main()
{
    // Creating a string
    string str = "hey vikash!";

    // Traverse using index:
    cout << "Using index: ";
    for (int i = 0; i < str.size(); ++i)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    // Traversing using range-based for loop
    cout << "Using range-based for loop: ";
    for (auto ch : str)
    {
        cout << ch << " ";
    }
    cout << endl;

    // Traversing using iterator
    cout << "Using iterator: ";
    auto beginItr = str.begin();
    auto endItr = str.end();

    for (auto i = beginItr; i != endItr; i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}