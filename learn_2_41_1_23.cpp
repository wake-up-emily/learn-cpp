#include <iostream> // Include for I/O streams
// #include "GCC_4_7_0/1/Sales_item.h"
#include <typeinfo>
using namespace std; // Streams are in the std namespace (standard library)

struct Sales_data
{
    string isbn;
    unsigned units_sold = 0;
    double revenue = 0;
    string book_name = "";
};

int main()
{
    Sales_data data1,data_sum;
    double price = 0;
    cout << "enter books info: " << endl;
    
    if (cin >> data1.isbn >> data1.units_sold >> price) {
        
        int num = data1.units_sold;

        Sales_data data2;
        while (cin >> data2.isbn >> data2.units_sold >> price) {
            if (data2.isbn == data1.isbn) {
                num += data2.units_sold; 
            }
            else {
                cout << "\n" << data1.isbn << " " << num << endl;
                data1 = data2;
                num = data1.units_sold;
            }
        }
        cout << "\n" << data1.isbn << " " << num << endl;
    }
    else
    {
        cout << "no data input!" << endl;
        return -1;
    }

    return 0;
    
}