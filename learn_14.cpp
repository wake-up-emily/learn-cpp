#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
// using namespace std::placeholders;
#include <numeric>
#include <iterator>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <functional>
using namespace std;
// using namespace std::placeholders;

//14.34
struct If_then_else {
    int operator()(bool a,const int& b,const int& c) const {
        return a ? b : c;
    }
};

//14.35
struct Print_line{
    Print_line(ostream& output=cout) :os(output) {}
    ostream& operator() (istream& in=cin) {
        string line;
        if (getline(in,line)) {
            os << line;
        }
        else {os << string();}
        return os;
    }
    private:
        ostream& os;
};

//14.36
struct Save_line{
    void operator() (istream& in=cin) {
        string line;
        while (getline(in,line)) {
            svec.push_back(line);
        }
    }
    void show_lines() {
        for (auto elem:svec) {
            cout << elem << endl;
        }
    }
    private:
        vector<string> svec;
};

//p508
struct Size_comp 
{
    Size_comp(size_t size) : sz(size) {}
    bool operator()(const string& s) {
        return s.length() <= sz;
    }

    private:
        size_t sz;
};

void run_size_comp() {
    vector<string> svec{"one","two","three","a"};
    cout << count_if(svec.cbegin(),svec.cend(),Size_comp(3)) << endl;
}


//14.38
//14.39
struct Length_match { //头文件分开引入的话没问题 像这样都写在main文件里 谓词类需要写在调用类前面 否则报错undeclared identifier
    Length_match(size_t size) :sz(size) {}
    bool operator()(const string& s) {
        return s.length() == sz;
    }
    private:
        size_t sz;
};

struct Length_lt { //头文件分开引入的话没问题 像这样都写在main文件里 谓词类需要写在调用类前面 否则报错undeclared identifier
    Length_lt(size_t size) :sz(size) {}
    bool operator()(const string& s) {
        return s.length() < sz;
    }
    private:
        size_t sz;
};

struct Length_gt { //头文件分开引入的话没问题 像这样都写在main文件里 谓词类需要写在调用类前面 否则报错undeclared identifier
    Length_gt(size_t size) :sz(size) {}
    bool operator()(const string& s) {
        return s.length() > sz;
    }
    private:
        size_t sz;
};

struct Save_string{
    void operator() (istream& in=cin) {
        string word;
        while (in >> word) {
            svec.push_back(word);
        }
    }
    void show_words() {
        for (auto elem:svec) {
            cout << elem << endl;
        }
    }
    int count_word_length_equal(const size_t& sz) {
        return count_if(svec.cbegin(),svec.cend(),Length_match(sz));
    }

    int count_word_length_lt(const size_t& sz) {
        return count_if(svec.cbegin(),svec.cend(),Length_lt(sz));
    }

    int count_word_length_gt(const size_t& sz) {
        return count_if(svec.cbegin(),svec.cend(),Length_gt(sz));
    }

    private:
        vector<string> svec;
};

void run_count_string_length() {
    fstream fin("data.txt");
    Save_string save_words;
    save_words(fin);
    // save_words.show_words();
    cout << save_words.count_word_length_equal(1) << endl;
    cout << save_words.count_word_length_equal(2) << endl;
    cout << save_words.count_word_length_equal(10) << endl;
}

void run_count_string_length_2() {
    fstream fin("data.txt");
    Save_string save_words;
    save_words(fin);
    // save_words.show_words();
    cout << save_words.count_word_length_lt(10) << endl;
    cout << save_words.count_word_length_gt(10) << endl;
}

//14.40
struct Sort_pred{
    bool operator()(const string& a, const string& b) {
        return a.size() < b.size();
    }
};

struct Find_pred{
    Find_pred(const vector<string>::size_type& size) : sz(size) {}
    bool operator()(const string& a) {
        return a.size() >= sz;
    }
    private:
        vector<string>::size_type sz;
};

struct Show_elem{
    void operator()(const string& s) {
        cout << s << " ";
    }
};

void Biggies(vector<string>& svec, vector<string>::size_type sz) {
    stable_sort(svec.begin(),svec.end(),Sort_pred());
    auto wc = find_if(svec.begin(),svec.end(),Find_pred(sz));
    auto count = svec.end() - wc;
    cout << count << " words of length " << sz << " or longer" << endl; 
    for_each(wc,svec.end(),Show_elem()); 
    //报错candidate template ignored: deduced conflicting types for parameter '_InputIterator'说明wc是const_iterator
    // for_each(wc,svec.end(),[](const string& s)->void{cout << s << " ";});
    cout << endl;
}

//14.42
// void run_std_pred() {
//     vector<int> ivec{4096,2048,1,2,1024};
//     // sort(ivec.begin(),ivec.end(),greater<int>());
//     // size_t sz = 1024;
//     // int ret = count_if(ivec.begin(),ivec.end(),[sz](const int& i)->bool{return i > sz;});
//     int ret = count_if(ivec.begin(),ivec.end(), bind(greater<int>(),_1,1024));
//     cout <<  ret << " elems greater than 1024" << endl;
// }

// void run_std_pred_str() {
//     vector<string> svec{"hello","friday","baby","plus","pooh"};
//     string t = "pooh";
//     sort(svec.begin(),svec.end(),less<string>());
//     // auto it = find_if(svec.begin(),svec.end(),[t](const string& s)->bool{return s != t;});
//     auto it = find_if(svec.begin(),svec.end(),bind(not_equal_to<string>(),_1,t));
//     cout << *it << endl;
// }

// void run_std_pred_double() {
//     vector<int> ivec{1,2,4,8,16};
//     // for_each(ivec.begin(),ivec.end(),bind(multiplies<int>(),_1,2)); //并不生效
//     transform(ivec.begin(),ivec.end(),ivec.begin(),bind(multiplies<int>(),_1,2));
//     for_each(ivec.begin(),ivec.end(),[](const int& i)->void{cout << i << " ";});
//     cout << endl;
// }

// void run_std_pred_devide() {
//     int i = 2;
//     // vector<int> ivec{2,4,6,8,10};
//     vector<int> ivec{2,4,6,8,10,13};
//     int ret = count_if(ivec.begin(),ivec.end(),bind(modulus<int>(),_1,i));
//     if (ret) {
//         cout << "cannot modulus by all elems" << endl;
//     }
//     else
//     {
//         cout << "can modulus by all elems" << endl;
//     }
    
// }

//14.44
void run_std_function() {
    map<string,function<int(int,int)>> binops = {
        {"+",[](int a,int b)->int{return a+b;}},
    };
    cout << binops["+"](1,1) << endl;
}

struct Need_calc {
    Need_calc() : binops(new map<string,function<int(int,int)>>()) {
        binops->insert({"+",[](int a,int b)->int{return a+b;}});
        binops->insert({"-",[](int a,int b)->int{return a-b;}});
        binops->insert({"*",[](int a,int b)->int{return a*b;}});
        binops->insert({"/",[](int a,int b)->int{return a/b;}});
        binops->insert({"%",[](int a,int b)->int{return a%b;}});
    }
    function<int(int,int)> do_calc(const string& calc_type) {
        auto it = binops->find(calc_type);
        if (it == binops->end()) {throw runtime_error("not support for this calc type yet");}
        return binops->at(calc_type);
    }
    private:
        shared_ptr<map<string,function<int(int,int)>>> binops;
};

void run_need_calc() {
    int a,b;
    string calc_type;
    Need_calc simple_calc;
    while (cin >> a >> calc_type >> b) {
        cout << simple_calc.do_calc(calc_type)(a,b) << endl;
    }
}

//14.45
struct Sales_data {
    friend istream& operator >> (istream&, Sales_data&);
    Sales_data()=default; //不加default不行
    Sales_data(istream&);
    explicit operator string() const {return book_isbn;};
    explicit operator double() const {return sold_price;};
    explicit operator bool() const {
        if (book_isbn != "") {return true;}
        return false;
    }

    private:
        string book_isbn;
        double sold_price;
        size_t sold_units;
        double discount;
        double label_price;
};

istream& operator >> (istream& in, Sales_data& s) {
    in >> s.book_isbn >> s.sold_units >> s.sold_price >> s.label_price;
    if (in && s.sold_price != 0) {
        s.discount = s.sold_price / s.label_price;
    }
    else
    {
        s = Sales_data();
    }
    return in;
}

void run_14_45() {
    Sales_data book;
    cin >> book; //x86-12345 2 80 100
    cout << static_cast<string>(book) << endl;
    cout << static_cast<double>(book) << endl;
    if (book) {
        cout << "record has book isbn" << endl;
    }
    else {
        cout << "record doesn't have isbn" << endl;
    }
}

//p582
struct Small_int {
    friend Small_int operator+ (const Small_int&, const Small_int&);
    // Small_int(const int& i=0): val(i) {}
    explicit Small_int(const int& i=0): val(i) {}
    explicit operator int() const {return val;};
    size_t val;
};

Small_int operator+ (const Small_int& a, const Small_int& b) {
    // return a.val + b.val; //构造函数不加explicit 返回size_t值也可以构造
    return Small_int(a.val+b.val); //否则需要显示调用构造函数返回
}

void run_small_int() {
    Small_int i1(42),i2(10);
    Small_int i3 = i1 + i2;
    cout << i3.val << endl;
    // auto i4 = i3 + 10; //构造函数不加explicit可以在加法函数中隐式类型转换 加了就不行 这个条件不管有没有定义explicit类型转换函数都一样
    // cout << static_cast<int>(i3) << endl;
    // Small_int i4 = Small_int(static_cast<int>(i3) + 10);
    // cout << i4.val << endl;
    int i4 = static_cast<int>(i3) + 10;
    cout << i4 << endl;
}

int main()
{
    //14.34
    // If_then_else if_then_else;
    // int ret = if_then_else(2,2,3);
    // cout << ret << endl;
    // ret = if_then_else(0,1,3);
    // cout << ret << endl;

    //14.35
    // fstream fin("data.txt");
    // Print_line print_line;
    // print_line(fin);

    //14.36
    // fstream fin("data.txt");
    // Save_line save_line;
    // save_line(fin);
    // save_line.show_lines();

    //14.38
    // run_size_comp();
    // run_count_string_length();

    //14.39
    // run_count_string_length_2();

    //14.40
    // vector<string> svec{"one","two","three","a"};
    // Biggies(svec,svec.size());

    //14.42
    // run_std_pred();
    // run_std_pred_str();
    // run_std_pred_double();
    // run_std_pred_devide();

    //14.44
    // run_std_function();
    // run_need_calc();

    //14.45
    // run_14_45();

    run_small_int();





    return 0;
    
}


