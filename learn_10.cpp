#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
using namespace std::placeholders;
#include <numeric>
#include <iterator>
#include "csales_data"

//10.9
void elim_dumps(vector<string>& words) {
    sort(words.begin(),words.end());
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << endl;
    auto unique_end = unique(words.begin(),words.end()); //非unique元素访问不到但还是存在的
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << "size: " << words.size() << endl;
    words.erase(unique_end,words.end());
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << "size: " << words.size() << endl;
}

//10.11
bool is_shorter(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

//10.12
bool my_compare_isbn(const Sales_data& item1, const Sales_data& item2) {
    return item1.isbn() < item2.isbn();
}

//10.13
bool size_gte_5(const string& s) {
    return s.size() >=5;
}

//10.15
// int my_sum(const int& a) {
//     [a](const int& b) -> int {return a + b;}; //non-void function does not return a value
// }

//10.16
void show_gte(vector<string>& words, vector<string>::size_type sz) {
    //字典序排序并删除重复单词
    elim_dumps(words);
    //按长度排序 长度相同维持字典序
    stable_sort(words.begin(),words.end(),[](const string& a, const string& b) -> bool {return a.size() < b.size();});
    //获取一个迭代器 指向第一个满足size()>=sz的元素
    auto first_quailified = find_if(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    //计算满足size()>=sz的元素数量
    auto count = words.end() - first_quailified;
    cout << "qualified elems count: " << count << endl;
    //打印所有满足元素 以空格分隔
    for_each(first_quailified,words.end(),[](const string& s) -> void {cout << s << " ";});
    cout << endl;
}

//10.18
void show_gte_2(vector<string>& words, vector<string>::size_type sz) {
    //字典序排序并删除重复单词
    elim_dumps(words);
    //按长度排序 长度相同维持字典序
    stable_sort(words.begin(),words.end(),[](const string& a, const string& b) -> bool {return a.size() < b.size();});
    //获取一个迭代器 指向第一个满足size()>=sz的元素
    // auto first_quailified = find_if(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    auto end_true = partition(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    //计算满足size()>=sz的元素数量
    auto count = end_true - words.cbegin();
    cout << "qualified elems count: " << count << endl;
    //打印所有满足元素 以空格分隔
    for_each(words.begin(),end_true,[](const string& s) -> void {cout << s << " ";});
    cout << endl;
}

//10.18
void show_gte_3(vector<string>& words, vector<string>::size_type sz) {
    //字典序排序并删除重复单词
    elim_dumps(words);
    //按长度排序 长度相同维持字典序
    // stable_sort(words.begin(),words.end(),[](const string& a, const string& b) -> bool {return a.size() < b.size();});
    //获取一个迭代器 指向第一个满足size()>=sz的元素
    // auto first_quailified = find_if(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    auto end_true = stable_partition(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    //计算满足size()>=sz的元素数量
    auto count = end_true - words.cbegin();
    cout << "qualified elems count: " << count << endl;
    //打印所有满足元素 以空格分隔
    for_each(words.begin(),end_true,[](const string& s) -> void {cout << s << " ";});
    cout << endl;
}

//10.22
bool _lte(const string& s1, vector<string>::size_type sz) {
    return s1.size() <= sz;
}

int lte(const vector<string>& words,vector<string>::size_type sz) {
    auto count = count_if(words.cbegin(),words.cend(),bind(_lte,_1,sz));
    return count;
}

//10.24
bool check_size(const string& s, const string& s2) {
    return s.size() >= s2.size();
}

//10.25
bool check_size_2(const string& s, vector<string>::size_type sz) {
    return s.size() >= sz;
}

void show_gte_4(vector<string>& words, vector<string>::size_type sz) {
    //字典序排序并删除重复单词
    elim_dumps(words);
    //按长度排序 长度相同维持字典序
    // stable_sort(words.begin(),words.end(),[](const string& a, const string& b) -> bool {return a.size() < b.size();});
    //获取一个迭代器 指向第一个满足size()>=sz的元素
    // auto first_quailified = find_if(words.begin(),words.end(),[sz](const string& a) -> auto {return a.size() >= sz;});
    auto end_true = stable_partition(words.begin(),words.end(),bind(check_size_2,_1,sz));
    //计算满足size()>=sz的元素数量
    auto count = end_true - words.cbegin();
    cout << "qualified elems count: " << count << endl;
    //打印所有满足元素 以空格分隔
    for_each(words.begin(),end_true,[](const string& s) -> void {cout << s << " ";});
    cout << endl;
}

//10.42
void elim_dumps_2(list<string>& words) {
    words.sort();
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << endl;
    auto unique_end = unique(words.begin(),words.end()); //非unique元素访问不到但还是存在的
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << "size: " << words.size() << endl;
    words.erase(unique_end,words.end());
    for (auto elem : words) {
        cout << elem << " ";
    }
    cout << "size: " << words.size() << endl;
}

int main()
{
    //10.1
    // vector<int> ivec = {1,2,3,4,5,6,7,8,9,2,3};
    // auto c = count(ivec.cbegin(),ivec.cend(),2);
    // cout << c << endl;

    //10.2
    // list<string> l = {"hello","world","hello"};
    // auto c = count(l.cbegin(),l.cend(),"hello");
    // cout << c << endl;

    //10.3
    // vector<int> ivec = {1,2,3,4,5,6,7,8,9};
    // int sum = accumulate(ivec.cbegin(),ivec.cend(),0);
    // int sum_base_10 = accumulate(ivec.cbegin(),ivec.cend(),10);
    // cout << sum << endl;
    // cout << sum_base_10 << endl;

    //10.4
    // vector<double> ivec = {1,2,3,4,5,6,7,8,9};
    // double sum = accumulate(ivec.cbegin(),ivec.cend(),0); //不管返回值是int double都可以通过编译并返回正确的结果
    // double sum_base_10 = accumulate(ivec.cbegin(),ivec.cend(),10);
    // cout << sum << endl;
    // cout << sum_base_10 << endl;

    //10.6
    // vector<int> ivec(10,42);
    // cout << ivec[0] << endl;
    // fill_n(ivec.begin(),ivec.size(),0);
    // cout << ivec[0] << endl;

    //10.9
    // vector<string> words = {"roses","are","are","red","violets","are","blue"};
    // elim_dumps(words);

    // //10.11
    // stable_sort(words.begin(),words.end(),is_shorter);
    // for (auto elem:words) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //10.12
    // ifstream fstrm("sales_data.txt");
    // Sales_data item;
    // vector<Sales_data> books;
    // while (fstrm >> item) {
    //     books.push_back(item);
    // }
    // cout << books.size() << endl;
    // for (auto item:books) {
    //     cout << item << endl;
    // }
    // cout << endl;
    // sort(books.begin(),books.end(),my_compare_isbn);
    // cout << "after sort: " << endl;
    // for (auto item:books) {
    //     cout << item << endl;
    // }
    // cout << endl;

    //10.13
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // auto end_true = partition(svec.begin(),svec.end(),size_gte_5); //false元素也可以访问
    // for (auto elem : svec) {
    //     cout << elem << " ";
    // }
    // cout << svec.size() << endl;
    // svec.erase(end_true,svec.end());
    // for (auto elem : svec) {
    //     cout << elem << " ";
    // }
    // cout << svec.size() << endl;

    //10.14
    // [](const int a, const int b) -> int {return a + b;};

    //10.15
    // int i=5;
    // int result = my_sum(i);
    // cout << result << endl;

    //10.16
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // // show_gte(svec,5);
    // show_gte(svec,3);

    //10.17
    // ifstream fstrm("sales_data.txt");
    // Sales_data item;
    // vector<Sales_data> books;
    // while (fstrm >> item) {
    //     books.push_back(item);
    // }
    // cout << books.size() << endl;
    // for (auto item:books) {
    //     cout << item << endl;
    // }
    // cout << endl;
    // sort(books.begin(),books.end(),
    //     [](const Sales_data& item1, const Sales_data& item2) -> bool {return item1.isbn() < item2.isbn();}
    //     );
    // cout << "after sort: " << endl;
    // for (auto item:books) {
    //     cout << item << endl;
    // }
    // cout << endl;

    //10.18
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // show_gte_2(svec,5);
    // // show_gte(svec,3);

    //10.19
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // show_gte_3(svec,5);
    // // show_gte_3(svec,3);

    //10.22
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // cout << lte(svec,6) << endl;
    // cout << lte(svec,3) << endl;

    //10.24
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // auto first_qualified = find_if(svec.begin(),svec.end(),bind(check_size,_1,"hello"));
    // cout << *first_qualified << endl;

    //10.25
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // show_gte_4(svec,5);
    // // show_gte(svec,3);

    //10.27
    // vector<string> svec = {"roses","are","red","violets","are","blue"};
    // vector<string> sucopy,scopy;
    // sort(svec.begin(),svec.end());
    // for (auto elem: svec) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // copy(svec.cbegin(),svec.cend(),back_inserter(scopy));
    // unique_copy(svec.cbegin(),svec.cend(),back_inserter(sucopy));
    // for (auto elem: scopy) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // for (auto elem: sucopy) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    // vector<int> ivec = {1,2,3,1,2,3};
    // list<int> iucp,icp;
    // sort(ivec.begin(),ivec.end());
    // unique_copy(ivec.begin(),ivec.end(),back_inserter(iucp));
    // copy(ivec.begin(),ivec.end(),back_inserter(icp));
    
    // for (auto elem: icp) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // for (auto elem: iucp) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //10.28
    // vector<int> ivec{1,2,3,4,5,6,7,8,9};
    // list<int> i2,i3,i4;
    // list<int> i5{9,9,9};
    // copy(ivec.cbegin(),ivec.cend(),back_inserter(i2));
    // copy(ivec.cbegin(),ivec.cend(),front_inserter(i3));
    // copy(ivec.cbegin(),ivec.cend(),inserter(i4,i4.end()));
    // copy(ivec.cbegin(),ivec.cend(),inserter(i5,i5.end()));
    // for (auto elem: i2) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // for (auto elem: i3) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // for (auto elem: i4) {
    //     cout << elem << " ";
    // }
    // cout << endl;
    // for (auto elem: i5) {
    //     cout << elem << " ";
    // }
    // cout << endl;

    //10.29
    // ifstream fstrm("data.txt");
    // vector<string> words;
    // istream_iterator<string> in_iter(fstrm),eof;
    // // while (in_iter != eof) {
    // //     words.push_back(*in_iter++);
    // // }
    // // for (auto elem: words) {
    // //     cout << elem << " ";
    // // }
    // // cout << endl;
    // vector<string> words2(in_iter,eof);
    // ostream_iterator<string> out_iter(cout," ");
    // // for (auto elem: words2) {
    // //     *out_iter++ = elem;
    // // }
    // copy(words2.begin(),words2.end(),out_iter);
    // cout << endl;

    //10.30
    // istream_iterator<int> in_iter(cin),eof; //12345 2 3 4 5
    // ostream_iterator<int> out_iter(cout," ");
    // vector<int> ivec(in_iter,eof);
    // sort(ivec.begin(),ivec.end());
    // // copy(ivec.cbegin(),ivec.cend(),out_iter); //2 3 4 5 12345
    // unique_copy(ivec.cbegin(),ivec.cend(),out_iter); 
    // cout << endl;
    
    //10.32
    // ifstream fstrm("sales_data.txt");
    // istream_iterator<Sales_data> in_iter(fstrm),eof;
    // ostream_iterator<Sales_data> out_iter(cout);
    // vector<Sales_data> books(in_iter,eof);
    // copy(books.begin(),books.end(),out_iter);
    // if (books.empty()) {
    //     cout << "no data?" << endl;
    //     return -1;
    // }
    // sort(books.begin(),books.end(),my_compare_isbn);
    // cout << "sorted: " << endl;
    // copy(books.begin(),books.end(),out_iter);
    // auto l = books.begin();
    // while (l != books.end()) {
    //     auto item = *l;
    //     auto r = find_if(l+1,books.end(),
    //             [item](const Sales_data& item2) -> bool {return item.isbn() != item2.isbn();}
    //             );
    //     cout << accumulate(l+1,r,item) << endl;
    //     l = r;
        
    // }
    

    //10.34
    // vector<int> ivec{1,2,3,4,5,6,7,8,9};
    // ostream_iterator<int> out_iter(cout," ");
    // copy(ivec.crbegin(),ivec.crend(),out_iter);
    // cout << endl;

    //10.35
    // vector<int> ivec{1,2,3,4,5,6,7,8,9};
    // // for (vector<int>::const_iterator it=ivec.cend()-1;it!=ivec.cbegin();--it) {
    // //     cout << *it << " ";
    // // }
    // // cout << ivec.front() << endl;
    // for (auto it = ivec.cend(); it != ivec.cbegin();) {
    //     cout << *(--it) << " ";
    // }
    // cout << endl;

    //10.36
    // list<int> ivec{0,1,2,3,4,0,1,2,3,4};
    // auto first_qualified = find(ivec.crbegin(),ivec.crend(),0);
    // cout << *(first_qualified) << endl;
    // cout << *(first_qualified.base()) << endl;

    //10.37
    // vector<int> ivec{0,1,2,3,4,5,6,7,8,9};
    // list<int> il(ivec.crbegin()+3,ivec.crend()-2);
    // ostream_iterator<int> out_iter(cout," ");
    // copy(il.cbegin(),il.cend(),out_iter);
    // cout << endl;
    
    //10.42
    // list<string> words = {"roses","are","are","red","violets","are","blue"};
    // elim_dumps_2(words);

    



    return 0;
    
}


