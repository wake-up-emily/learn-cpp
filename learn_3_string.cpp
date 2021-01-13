#include <iostream> // Include for I/O streams
// #include "GCC_4_7_0/1/Sales_item.h"
#include <typeinfo>
#include <iomanip>
#include "csales_data"
using namespace std; // Streams are in the std namespace (standard library)


int main()
{
    //3.2
    // string word;
    // while (cin >> word)
    // {
    //     cout << word << endl;
    // }

    //3.3
    // string line;
    // while (getline(cin,line)) {
    //     cout << line << endl;
    // }

    //3.4
    // string word1, word2;
    // cin >> word1 >> word2;
    // if (word1 == word2) {
    //     cout << "match!" << endl;
    // }
    // else
    // {
    //     if (word1.size() >= word2.size()) {
    //         cout << word1 << endl;
    //     }
    //     else
    //     {
    //         cout << word2 << endl;
    //     }
        
    // }
    
    //3.5
    // string word,total;
    // while (cin >> word) {
    //     total += word;
    //     total += " ";
    // }
    // cout << total << endl; 

    // string word;
    // while (cin >> word) {
    //     for (auto c : word) {
    //         cout << c;
    //     }
    //     cout << endl;
    // }

    //3.6
    // string s;
    // getline(cin,s);
    // for (char& c : s) { //havs to be &c to change c value
    //     c = 'X'; //c type char so use ''
    // }
    // cout << s << endl;

    //3.8
    // string s;
    // getline(cin,s);
    // // int i = 0;
    // // while (s[i] != 0) {
    // //     s[i] = 'X';
    // //     ++i;
    // // }
    // for (int i = 0;i!=s.size();++i) {
    //     s[i] = 'X';
    // }
    // cout << s << endl;

    //3.10
    // string s;
    // getline(cin,s);
    // for (char& c : s) {
    //     if (!ispunct(c)) {
    //         cout << c;
    //     }
    // }

    //3.11
    // const string s = "Keep out!";
    // for (auto& c : s) {
    //     c = 'X'; //不行 c不可改
    //     cout << c << "1 "; //可
    // }


    //csales_data
    // Sales_data data1, data2;
    // cin >> data1;                        // x86-12345 2 80 100
    // cin >> data2;                        // x86-12345 3 70 100
    // cout << data1 << endl;               // x86-12345 2 80 100 0.8 
    // cout << data2 << endl;               // x86-12345 3 70 100 0.7 
    // cout << (data1 == data2) << endl;    // 1
    // cout << (data1 != data2) << endl;    // 0
    // cout << (data1 + data2) << endl;     // x86-12345 5 74 100 0.74 
    // cout << data1 << endl;               // x86-12345 2 80 100 0.8 
    // cout << (data1 += data2) << endl;    // x86-12345 5 74 100 0.74 
    // cout  << data1 << endl;              // x86-12345 5 74 100 0.74

    return 0;
    
}


