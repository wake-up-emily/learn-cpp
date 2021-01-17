#include <iostream>
#include <fstream>
using namespace std;
#include <list>
#include <forward_list>
#include <deque>
#include <vector>

//9.4
bool find_int(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i ) {
    while(begin != end) {
        if (*begin == i) {
            return true;
        }
        ++begin;
    }
    return false;
}

//9.5
vector<int>::const_iterator find_int_iter(vector<int>::const_iterator begin, const vector<int>::const_iterator end, int i ) {
    while(begin != end) {
        if (*begin == i) {
            return begin;
        }
        ++begin;
    }
    return end;
}

//9.18
deque<string>::const_iterator save_string(deque<string>& svec, const string& file) {
    string s;
    ifstream fstrm(file);
    while (fstrm >> s) {
        svec.push_back(s);
    }
    return svec.cend();
}

void print_svec(const deque<string>& svec, deque<string>::const_iterator end) {
    auto begin = svec.cbegin();
    while (begin != end) {
        cout << *begin << " ";
        ++begin;
    }
    cout << endl;
}

//9.20
void split_list_to_dec(const list<int>& l,deque<int>& d1, deque<int>& d2) {
    auto begin = l.cbegin();
    auto end = l.cend();
    while (begin != end) {
        if (*begin % 2 != 0) {
            d1.push_back(*begin);
        }
        else {
            d2.push_back(*begin);
        }
        ++begin;
    }
}

//9.28
void append_after(forward_list<string>& flst,const string& s1,const string& s2) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    // auto end = flst.end(); //不要缓存容器的end迭代器 在循环中删除或添加元素导致迭代器失效后 用end判定循环的代码行为是未定义的 会引发无限循环
    bool found = 0;
    while (curr != flst.end()) { //保证每次判断时都使用更新的end迭代器
        try {
            if ( (*curr) == s1 ) {
                curr = flst.insert_after(curr,s2); //在当前位后面插
                found = 1;
                // break;
            }
            else
            {
                prev = curr;
                ++curr;
            }
        }
        catch (exception err) {
            cerr << err.what() << endl;
            cerr << __LINE__ << endl;
        }
    }
    if (! found) {
        flst.insert_after(prev,s2);
    }

}

int main()
{
    //9.2
    // list<deque<int>> l;

    //9.4
    // int check_num[] = {5,10};
    // bool result; 
    // vector<int> ivec = {1,2,3,4,5};
    // try {
    //     for (auto num : check_num) {
    //         cout << "start checking if vector include value " << num << endl;
    //         result = find_int(ivec.begin(),ivec.end(),num);
    //         cout << result << endl;
    //     }
    // }
    // catch (exception) {
    //     cerr << "error" << endl;
    // }

    //9.5
    // int check_num[] = {5,10};
    // vector<int>::const_iterator result; 
    // vector<int> ivec = {1,2,3,4,5};
    // try {
    //     for (auto num : check_num) {
    //         cout << "start checking if vector include value " << num << endl;
    //         result = find_int_iter(ivec.begin(),ivec.end(),num);
    //         cout << *result << endl;
    //     }
    // }
    // catch (exception) {
    //     cerr << "error" << endl;
    // }

    //9.14
    // list<const char *> l = {"this","is","a","list"};  //const 不加会warning ISO C++11 does not allow conversion from string literal to 'char *const'
    // vector<string> s(l.cbegin(),l.cend());
    // for (auto elem : s) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //p304
    // vector<int> i1 = {1,2,3,5};
    // vector<int> i2 = {2,2,3,4};
    // list<int> i3 = {1,2,3,4};
    // cout << (i1 < i2) << endl;
    // cout << (i1 == i3) << endl; //不同类型的容器无法比较元素 因为元素类型不同 操作符重载没有定义如何比

    //9.18
    // string file = "data.txt";
    // deque<string> desvec;
    // deque<string>::const_iterator end = save_string(desvec,file);
    // print_svec(desvec,end);

    //9.20
    // deque<int> d1,d2;
    // list<int> l = {1,2,3,4,5,6};
    // split_list_to_dec(l,d1,d2);
    // cout << "d1 num: " << endl;
    // for (auto elem : d1) {
    //     cout << elem << endl;
    // }
    // cout << "d2 num: " << endl;
    // for (auto elem : d2) {
    //     cout << elem << endl;
    // }

    //9.23
    // vector<int> ivec;
    // vector<int>::iterator it = ivec.begin();
    // int mid = ivec.size()/2;
    // int i = 0, t = 0;

    // while (i <= mid) {
    //     if (*it == t) {
    //         ivec.insert(it,t * 2);
    //         it++;
    //         it++;
    //     }
    //     it++;
    //     i++;
    // }

    //9.24
    // vector<int> ivec;
    // // cout << ivec.front() << endl; //segmentation fault 
    // // cout << ivec.back() << endl; //segmentation fault 
    // cout << (*ivec.begin()) << endl; //segmentation fault 
    // cout << ivec.at(0) << endl; //terminating with uncaught exception of type std::out_of_range: vector
    // // cout << ivec[0] << endl; //segmentation fault 

    //p312
    // list<int> il = {1,2,3,4,5,6,7,8,9};
    // auto it = il.begin();
    // while (it != il.cend()) {
    //     if (!((*it) % 2)) {
    //         it = il.erase(it);
    //     }
    //     else {
    //         ++it;
    //     }
    // }
    // for (auto elem : il) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //9.26
    // int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    // vector<int> ivec(begin(ia),end(ia));
    // list<int> il(begin(ia),end(ia));
    // for (vector<int>::iterator it=ivec.begin(); it != ivec.cend(); ++it) {
    //     if ((*it) % 2 == 0 ) {
    //         ivec.erase(it);
    //     }
    // }
    // for (list<int>::iterator it=il.begin(); it != il.cend(); ++it) {
    //     if ((*it) % 2 != 0 ) {
    //         il.erase(it);
    //     }
    // }
    // for (auto elem : ivec) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    // for (auto elem : il) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //9.27
    // forward_list<int> flst = {0,1,1,2,3,5,8,13,21,55,89};
    // forward_list<int>::iterator prev,curr;
    // prev = flst.before_begin(); //auto也可
    // curr = flst.begin();
    // while (curr != flst.cend()) {
    //     if ( (*curr) % 2 != 0 ) {
    //         curr = flst.erase_after(prev);
    //     }
    //     else
    //     {
    //         prev = curr;
    //         ++curr;
    //     }
        
    // }
    // cout << "flst: " << endl;
    // for (auto elem : flst) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //9.28
    // forward_list<string> flst = {"this","is","a","test"};
    // string s1 = "a";
    // string s2 = "regular";
    // for (auto elem : flst) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // // append_after(flst,s2,s1);
    // // for (auto elem : flst) {
    // //     cout << elem << " ";
    // // }
    // // cout << endl;
    // append_after(flst,s1,s2);
    // for (auto elem : flst) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //9.31
    // forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    // auto prev = flst.before_begin();
    // auto curr = flst.begin();
    // while (curr != flst.end()) {
    //     if ( (*curr) % 2 != 0) {
    //         curr = flst.insert_after(curr,*curr); //返回迭代器是指向最后一个插入元素的迭代器
    //         prev = curr; 
    //         ++curr;
    //     }
    //     else
    //     {
    //         curr = flst.erase_after(curr); //返回被删元素之后的迭代器
    //     }
        
    // }
    // for (auto elem : flst) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //9.38
    // vector<int> ivec;

    // cout << "default " 
    // << "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;
    
    // for (int i=0; i != 24; ++i) {
    //     ivec.push_back(i);
    // }

    // cout << "push back 24 " 
    // <<  "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;

    // ivec.reserve(50);

    // cout << "reserve 50 " 
    // << "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;
    
    // while (ivec.size() != ivec.capacity()) {
    //     ivec.push_back(42);
    // }

    // cout << "fill capacity " 
    // << "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;
    
    // ivec.push_back(1);

    // cout << "1 more out of capacity " 
    // << "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;
    
    // ivec.shrink_to_fit();

    // cout << "shrink to fit " 
    // << "capacity: " << ivec.capacity() 
    // << " size: " << ivec.size() << endl;
    
    return 0;
    
}


