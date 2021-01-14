#include <iostream> // Include for I/O streams
using namespace std; // Streams are in the std namespace (standard library)
#include "csales_data"
#include "cperson"
#include "cscreen"
#include "cexample"

//7.31
// struct  X;
// class Y;

// class X
// {
//     private:
//         Y *y; 
// };

// class Y
// {
//     private:
//         X x; 
// };

//7.58

double Example::rate = 6.5;
// const int Example::vec_size; //static字面常量值在类声明中初始化默认值后 在类外无需定义也可通过编译
// vector<double> Example::dvec(Example::vec_size); //编译报错 dvec: incomplete type is not allowed
int Example::arr[vec_size] = {0,1,2};


int main()
{
    //7.11
    // Sales_data item;
    // print(cout,item);

    // Sales_data item1("x86-12345");
    // print(cout,item1);

    // Sales_data item2;
    // read(cin,item2);
    // print(cout,item2);

    //7.15
    // Person p1("finn","the human","land of ooo");
    // cout << p1.name() << endl;
    // cout << p1.address() << endl;

    //7.27
    // Screen my_screen(5,5,'X');
    // my_screen.display(cout);
    // cout << endl;
    // my_screen.move(4,0).set('#').display(cout);
    // cout << endl;
    // my_screen.display(cout);

    //7.58
    // class Example e;
    // cout << e.rate << endl;
    // cout << e.vec_size << endl;
    // for (auto elem : Example::arr) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    

    return 0;
}