#include <iostream> // Include for I/O streams
#include <typeinfo>
#include <vector>
#include <cstdlib>
#include "csales_data"
using namespace std;

int main()
{
    //3.14
    // vector<int> ivec;
    // int tmp;
    // while (cin >> tmp) {
    //     ivec.push_back(tmp);
    // }
    // cout << ivec.size() << endl;
    // for (int c : ivec) {
    //     cout << c << " ";
    // }
    // cout << endl;

    //3.15
    // vector<string> svec;
    // string s;
    // while (cin >> s) {
    //     svec.push_back(s);
    // }
    // cout << svec.size() << endl;
    // cout << svec.front() << endl;

    //p93
    // vector<unsigned> scores(10,0);
    // unsigned tmp;
    // while (cin >> tmp) {
    //     if (tmp <= 100)
    //         ++scores[tmp/10];
    // }

    // for (auto c : scores) {
    //     cout << c << " ";
    // }

    // cout << endl; //0 1 0 0 1 0 1 0 0 1 

    //3.17
    // vector<string> svec;
    // string word;
    // while (cin >> word) {
    //     for (char& c : word) {
    //         c = toupper(c);
    //     }
    //     cout << word << endl;
    //     svec.push_back(word);
    // }

    //3.21
    // vector<string> svec;
    // string word;
    // while (cin >> word) {
    //     for (auto it=word.begin(); it!=word.end();++it) {
    //         *it = toupper(*it);
    //     }
    //     cout << word << endl;
    //     svec.push_back(word);
    // }

    //p96
    // string s = "learn iterator";
    // for (auto it = s.begin(); it != s.end(); ++it) {
    //     *it = toupper(*it);
    // }
    // cout << s << endl;

    // //p98
    // 3.22
    vector<string> text;
    string s;
    while (getline(cin,s)) {
        text.push_back(s);
    }
    for (auto it=text.begin();
            it !=text.end() && !it->empty(); 
            ++it) {
        string tmp = *it;
        for (auto cit=tmp.begin();cit!=tmp.end();++cit) {
            *cit = toupper(*cit);
        }
        cout << tmp << endl;
    }

    //3.23
    // srand((unsigned) time (NULL));
    // vector<int> ivec;
    // for (int i=0;i!=10;++i) {
    //     ivec.push_back( rand() % 1000);
    // }
    // for (auto it=ivec.cbegin();it!=ivec.cend();++it) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // for (auto it=ivec.begin();it!=ivec.end();++it) {
    //     *it = *it * 2;
    //     cout << *it << " ";
    // }
    // cout << endl;
    

    //3.18
    // vector<int> ivec;
    // ivec.push_back(42);

    //3.19
    // vector<int> ivec(10,42);
    // vector<int> ivec2 = ivec;
    // vector<int> ivec3;
    // for (int i=0;i!=10;++i) {
    //     ivec3.push_back(42);
    // }
    // vector<int> ivec4(10);
    // for (auto i : ivec4) {
    //     i = 42;
    // }

    //3.20
    // vector<int> ivec;
    // int cur;
    // while (cin >> cur) {
    //     ivec.push_back(cur);
    // }

    // for (int i=0; i<ivec.size()-1;i+=2) {
    //     cout << ivec[i] + ivec[i+1] << endl;
    //     }
    // if (ivec.size() % 2 != 0) {
    //     cout << ivec[ivec.size() - 1];
    // }

    // int length = ivec.size();

    // for (int i =0; i != length/2; ++i) { 
    //         int tmp = ivec[i] + ivec[length - i - 1];
    //         cout << tmp << endl;
    //     }
    // //奇数
    // if (length % 2 != 0) { 
    //     cout << ivec[length/2] << endl;
    //     }

    //3.24
    // vector<int> ivec;
    // int cur;
    // while (cin >> cur) {
    //     ivec.push_back(cur);
    // }
    // int mid = ivec.cend() - ivec.cbegin();
    // for (auto it=ivec.cbegin(); it != mid;++it) {
    //     cout << ivec[i] + ivec[i+1] << endl;
    //     }
    // if (ivec.size() % 2 != 0) {
    //     cout << ivec[ivec.size() - 1];
    // }

    // int length = ivec.size();

    // for (int i =0; i != length/2; ++i) { 
    //         int tmp = ivec[i] + ivec[length - i - 1];
    //         cout << tmp << endl;
    //     }
    // //奇数
    // if (length % 2 != 0) { 
    //     cout << ivec[length/2] << endl;
    //     }

    //p113
    // const int row_count = 3, col_count = 4;
    // int ia[row_count][col_count] = {};
    // int cell = 0;
    // for (int i=0;i!=row_count;++i) { //知道元素个数时用for遍历
    //     for (int j=0;j!=col_count;++j) {
    //         ia[i][j] = cell;
    //         ++cell;
    //     }
    // }
    // int (*p)[col_count] = ia; //指针默认指向数组的首元素地址 [col_count]必须写 表示指向一个包含4元素的数组 否则不能通过编译
    // int (&r)[col_count] = ia[1]; //同理
    // p = &ia[3];
    // for (auto p = begin(ia);p!=end(ia);++p) {
    //     for (auto q = begin(*p); q!= end(*p);++q) {
    //         cout << *q << " ";
    //     }
    // }
    // cout << endl;

    // for (auto p = begin(r);p!=end(r);++p) {
    //     cout << *p << " ";
    // }
    // cout << endl;

    //3.45
    // for (auto &row : ia) { //除了最内层循环 其他所有循环的控制变量都要求是引用型 否则外层循环中row被解释为int * 即数组首元素的指针 内层循环并不合法
    //     for (auto col : row) {
    //         cout << col << " ";
    //     }
    // }
    // cout << endl;

    //3.44
    // using int_array = int[4];
    // for (int_array &row : ia) {
    //     for (auto col : row) {
    //         cout << col << " ";
    //     }
    // }
    // cout << endl;

    return 0;
}
