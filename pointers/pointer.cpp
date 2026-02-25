#include <iostream>
using namespace std;

int main()
{
    // address of var->>
    int a;
    cin >> a;
    cout << &a << endl;
    //  create pointer
    int *ptr; // integer type pointer
    ptr = &a; // assign address of a
    //*p that means value at p->
    cout << *ptr << endl;
    cout << sizeof(ptr) << endl;
    cout << a << endl;

    // Memory based questions->
    cout << a << endl;    // i think value of a
    cout << &a << endl;   // address of a
    cout << ptr << endl;  // address of a
    cout << *ptr << endl; // value at p
    cout << &ptr << endl; // address of p

    *ptr = *ptr + 2; // this is true
    cout << *ptr << endl;
    cout << a << endl;

    ptr = ptr + 1;
    cout << ptr;

    return 0;
}