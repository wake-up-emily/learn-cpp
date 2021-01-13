#include <iostream> // Include for I/O streams
// #include "GCC_4_7_0/1/Sales_item.h"
#include <typeinfo>
using namespace std; // Streams are in the std namespace (standard library)


int main()
{
    const int i = 42;
    auto j = i;
    const auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    cout << "\ntype of j " << typeid(j).name() << endl;
    cout << "\ntype of k " << typeid(k).name() << endl;
    cout << "\ntype of p " << typeid(*p).name() << endl;
    cout << "\ntype of j2 " << typeid(j2).name() << endl;
    cout << "\ntype of k2 " << typeid(k2).name() << endl;
    
}