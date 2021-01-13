#include <iostream> // Include for I/O streams
using namespace std; // Streams are in the std namespace (standard library)
#include <vector>
# include<string>

int main()
{
    //5.9
    // vector<string> text;
    // string s;
    // int v_count = 0;
    // while (getline(cin,s)) { //如果是cin >> s 首个输入单词就会忽略掉
    //     for (auto &c : s) {
    //         // if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {++v_count;}
    //         // }

    //         //5.10
    //         // if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {++v_count;}
    //         // }

    //     }
    
    // cout << v_count << endl;

    //5.11
    // unsigned int a_count=0,e_count=0,i_count=0,o_count=0,u_count=0;
    // unsigned int new_line_count=0,space_count=0,tab_count=0;
    // char c;
    // while (cin.get(c)) { //如果是cin >> c 就不会统计到 \t \n 空格
    //     switch (c)
    //     {
    //     case 'a':
    //     case 'A':
    //         ++a_count;
    //         break;
    //     case 'e':
    //     case 'E':
    //         ++e_count;
    //         break;
    //     case 'i':
    //     case 'I':
    //         ++i_count;
    //         break;
    //     case 'o':
    //     case 'O':
    //         ++o_count;
    //         break;
    //     case 'u':
    //     case 'U':
    //         ++u_count;
    //         break;
    //     case '\t':
    //         ++tab_count;
    //         break;
    //     case '\n':
    //         ++new_line_count;
    //         break;
    //     case ' ':
    //         ++space_count;
    //         break;
    //     }
    // }

    // cout << (a_count + e_count + i_count + o_count + u_count) << endl;
    // cout << (new_line_count + tab_count + space_count) << endl;

    //5.12
    // unsigned int ff_cnt=0, fl_cnt=0, fi_cnt=0;
    // char pre_c = '\0';
    // char c;
    // while (cin.get(c)) {
    //     if (pre_c == 'f') {
    //         switch (c)
    //         {
    //         case 'f':
    //             ++ff_cnt;
    //             break;
    //         case 'l':
    //             ++fl_cnt;
    //             break;
    //         case 'i':
    //             ++fi_cnt;
    //             break;
    //         }
    //     }

    //     if ( c != '\0' ) {
    //         pre_c = c;
    //     }
    // }
    // cout << ff_cnt << endl;
    // cout << fl_cnt << endl;
    // cout << fi_cnt << endl;

    //5.14
    // string s,f;
    // unsigned int f_cnt = 0,cur_cnt=0;
    // // vector<string> text;
    // while (cin >> s) {
    //     // text.push_back(s);
    //     if ( f != s) {
    //         f = s;
    //         cur_cnt = 1;
    //     }
    //     ++cur_cnt;

        
    // }
    // cout << f << " " << f_cnt << endl;

    //5.17
    // vector<int> ivec1 = {0,1,1,2};
    // vector<int> ivec2 = {0,1,1,2,3,5,8};
    // vector<int> ivec1;
    // vector<int> ivec2;
    // string tmp1,tmp2;
    // bool f = true;
    // decltype(ivec1.size()) times=0;

    // if (getline(cin,tmp1)) {
    //     // int tmp1 = static_cast<int>(tmp1);
    //     int tmp1 = stoi(tmp1);
    //     ivec1.push_back(tmp1);

    //     if (getline(cin,tmp2)) {
    //         int tmp2 = static_cast<int>(tmp2);
    //         ivec2.push_back(tmp2);

    //         if (ivec1.size() > ivec2.size()) {
    //             times = ivec2.size();
    //         }
    //         else
    //         {
    //             times = ivec1.size();
    //         }
    //     }
    // }
    // for (auto i : ivec1) {
    //     cout << "ivec1: " << i << " ";
    // }
    // cout << endl;

    // for (auto i : ivec2) {
    //     cout << "ivec2: " << i << " ";
    // }
    // cout << endl;
    
    // if (times) {
    //     cout << times << endl;

    //     for (decltype(times) i=0; i!=times;++i) {
    //         cout << ivec1[i] << ivec2[i] << endl;
    //         if (ivec1[i] != ivec2[i]) {
    //             f = false;
    //             break;
    //         }
    //     }
    //     cout << f << endl;
    // }

    // string s;
    // while (getline(cin,s,' ')) {
    //     int i = stoi(s);
    //     cout << i << endl;
    // }
    
   return 0;
}