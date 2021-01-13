#include <iostream> // Include for I/O streams
#include "GCC_4_7_0/1/Sales_item.h"
using namespace std; // Streams are in the std namespace (standard library)


int main()
{
   Sales_item total;
   if (cin >> total) {
      Sales_item nextbook;
      while (cin >> nextbook) {
         if (compareIsbn(total, nextbook)) {
            total += nextbook;
         }
         else
         {
            cout << "\n" << endl;
            cout << "static: " << total << endl;
            total = nextbook;
         }
      }
      cout << "\n" << endl;
      cout << "static: " << total << endl;
   }
   else
   {
      cout << "no input data!" << endl;
      return -1;
   }

   return 0;
}