#include <iostream> // Include for I/O streams
// #include "GCC_4_7_0/1/Sales_item.h"
using namespace std; // Streams are in the std namespace (standard library)


int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    a = 42;
    b = 42;
    c = 42;
    // d = 42; // d is a pointer. it should be *d = 42
    // *e = 42; // e is a pointer, point to ci, which is not changeable
    // g = 42; // g repr ci, which is not changeable
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    // cout << *d << endl;

    
}