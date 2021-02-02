#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
// using namespace std::placeholders;
#include <numeric>
#include <iterator>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
// #include "folder.cpp"
// #include "text_query_result_str_vec.cpp"
#include "my_string.cpp"
#include "str_vec.cpp"
#include "str_blob_ptr.cpp"

//13.13
struct X {
    X(){cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X& operator = (const X&) {
        cout << "X& = (const X&)" << endl; 
        return *this;
    }
    ~X() {cout << "delete" << endl;}
};

void run_X() {
    X x;
    X x2(x);
    X x3 = x;
    X* p = new X;
    vector<X> xvec(1,x);
    delete p;
}

//13.14
struct Numbered {
    size_t num;
    Numbered()
    :num(1) {}
    Numbered(const Numbered& n)
    :num(n.num+1) {}
};

void f(const Numbered& n) { //传值时会调用拷贝构造 不加const结果算进去传值拷贝构造的次数了 值不一样
    cout << n.num << endl;
}

void run_numbered() {
    Numbered a, b=a, c=b; //编译器将拷贝赋值改写成拷贝构造
    f(a);
    f(b);
    f(c);
}

//13.18
struct Employee
{   
    static size_t static_num;
    Employee()
    : num(static_num) {static_num++;}
    Employee(const string& s)
    : name(s),num(static_num) {static_num++;}
    // Employee(const Employee& e)
    // :name(e.name),num(e.num) {}
    // Employee& operator= (const Employee& e) {
    //     name = e.name;
    //     num = e.num;
    //     return *this;
    // }

    string name;
    size_t num;
};

size_t Employee::static_num = 1;

//13.22
struct Has_ptr
{
    friend void swap(Has_ptr&,Has_ptr&);
    bool operator < (const Has_ptr&) const;
    Has_ptr() : i(0),ps(new string()) {}
    Has_ptr(const string& s) : i(0),ps(new string(s)) {}
    Has_ptr(const Has_ptr& hp)
    : i(hp.i),ps(new string(*hp.ps)) {}
    // Has_ptr& operator= (const Has_ptr& hp);
    Has_ptr& operator= (Has_ptr hp) { //传值
        swap(*this,hp);
        return *this;
    }
    ~Has_ptr() {
        delete ps;
    }

    int i;
    string *ps;
};

bool Has_ptr::operator< (const Has_ptr& rhs) const {
    return *ps < *rhs.ps;
}

void swap(Has_ptr& lhs, Has_ptr& rhs) {
    using std::swap;
    cout << "swapping..." << endl;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

void run_Has_ptr() {
    Has_ptr hp;
    Has_ptr hp2(hp);
    cout << *hp2.ps << endl;
    Has_ptr hp3("wind");
    Has_ptr hp4 = hp3; //编译器改写为拷贝构造 不会调用拷贝赋值的swap
    cout << *hp4.ps << endl;
    swap(hp2,hp3); //会调用swap
    cout << *hp2.ps << endl;
}

//13.31
void run_has_ptr_vec() {
    vector<Has_ptr> psvec;
    int elem_count = 10;  //元素数量<=10时sort不会调用swap
    for (int i=0; i < elem_count; ++i) {
        psvec.push_back(to_string(i));
    }  
    for (auto elem: psvec) {
        cout << *elem.ps << " ";
    }
    cout << endl;
    sort(psvec.begin(),psvec.end());
    for (auto elem: psvec) {
        cout << *elem.ps << " ";
    }
    cout << endl;
}

//13.27
struct Has_ptr_ref
{
    Has_ptr_ref(const string& s = string()) : ps(new string(s)), ref_count(new size_t(1)) {}
    Has_ptr_ref(const Has_ptr_ref& rhs)
    : ps(rhs.ps),ref_count(rhs.ref_count) {++*ref_count;}
    Has_ptr_ref& operator= (const Has_ptr_ref& rhs) {
        ++*rhs.ref_count;
        if (--*ref_count == 0) {
            delete ps;
            delete ref_count;
        }
        ps = rhs.ps;
        ref_count = rhs.ref_count;
        return *this;
    }
    ~Has_ptr_ref() {
        if (--*ref_count == 0) {
            delete ps;
            delete ref_count;
        }
    }

    string *ps;
    size_t *ref_count;
};

void run_Has_ptr_ref() {
    Has_ptr_ref hp;
    cout << *hp.ps << *hp.ref_count << endl;
    Has_ptr_ref hp2(hp);
    cout << *hp2.ps << *hp2.ref_count << endl;
    Has_ptr_ref hp3("wind");
    cout << *hp3.ps << *hp3.ref_count << endl;
    Has_ptr_ref hp4 = hp3;
    cout << *hp4.ps << *hp4.ref_count << endl;
    if (true) {
        Has_ptr_ref hp5 = hp3;
        cout << *hp5.ps << *hp5.ref_count << endl;
    }
    cout << *hp4.ps << *hp4.ref_count << endl;
    Has_ptr_ref hp6;
    cout << *hp6.ps << *hp6.ref_count << endl;
}

//13.28
//以下代码run不起来的 之后再来补二叉树的实现
// class Tree_node { 
//     public:
//         Tree_node(const string& s = string())
//         : value(s), count(1), left(nullptr), right(nullptr) {}
//         Tree_node(const Tree_node& rhs)
//         : value(rhs.value),count(rhs.count + 1),left(*rhs),right(nullptr) {rhs.right = &this;}
//         ~Tree_node() {
//             (*left).right = right;
//             (*right).left = left;
//             delete left;
//             delete right;
//         }
//         void print() const {
//             if (left) {
//                 cout << "node left " << left << endl;
//             }
//             if (right) {
//                 cout << "node right " << right << endl;
//             }
//             cout << "no left and right yet" << endl;
//         }
//         void copy_tree() { //来自参考答案的模拟
//             if (left) {
//                 left->copy_tree();
//             }
//             if (right) {
//                 right->copy_tree();
//             }
//             count++;
//         }

//     private:
//         string value;
//         int count;
//         Tree_node *left;
//         Tree_node *right;
// };

// class Bin_str_tree {
//     public:
//         Bin_str_tree()
//         : root(Tree_node *node = nullptr) {}
//         Bin_str_tree(const Bin_str_tree& rhs)
//         : root(rhs.root) {root->copy_tree();} //拷贝整棵树 而非节点
//     private:
//         Tree_node *root;
// };

// void run_tree_node() {
//     Tree_node node1;

//     node1.print();
//     Tree_node node2(node1);
//     node2.print();
//     Bin_str_tree node3;
//     node2.print();
//     // cout << "bin str tree new node left " << *node3.root.left << " right " << *node3.root.right << endl;
// }

//13.37
// void run_msg_folder() {
//     Message m1("formal msg"),m2("trash msg");
//     Folder formal,trash;
//     m1.save(formal);
//     m2.save(trash);
//     Message m3(m1);
//     cout << formal.size() << endl;
//     cout << trash.size() << endl;
//     Message m4 = m1;
//     cout << trash.size() << endl;
//     for (auto m : trash.show_msgs()) {
//         cout << m->show_content() << endl;
//     }
//     cout << formal.size() << endl;
//     for (auto m : formal.show_msgs()) {
//         cout << m->show_content() << endl;
//     }
// }

// //13.39

// void run_str_vec_pre() {
//     Str_vec svec{"letting","go"};
//     cout << svec.size() << endl;
//     cout << *svec.begin() << endl;
//     cout << *(svec.end()-1) << endl;
//     svec.push_back("unseen");
//     cout << *(svec.end()-1) << endl;
//     svec.resize(2);
//     cout << *(svec.end()-1) << endl;
// }

// void run_str_vec() {
//     ifstream fin("data.txt");
//     string s("are");
//     vector<string> svec{"are","blue"};
//     Text_query_str_vec tq(fin);
//     print(cout,tq.query(s)); //前置声明报错可能是某些成员的const有问题
//     // cout << tq.show_file_size() << endl;
//     // cout << *tq.get_file()->begin() << endl;
//     // cout << *(tq.get_file()->end()-1) << endl;
// }

// void run_my_string() {
//     My_string s("wind");
//     cout << s.size() << endl;
//     My_string s2(s);
//     cout << s2.size() << endl;
//     cout << s2 << endl;
//     My_string s3 = s2;
//     cout << s3.size() << endl;
//     cout << s3 << endl;
//     My_string s4 = s3 + s2;
//     cout << s4 << endl;
// }

//13.48
void run_13_48() {
    vector<My_string> svec;
    svec.reserve(4);
    My_string s("a new string"); //
    svec.push_back(s); //拷贝构造
    My_string s2 = s; //拷贝构造
    svec.push_back(s2); //拷贝构造
    svec.push_back(My_string("another new string")); //移动构造
    svec.push_back(std::move(s)); //移动构造

    //超过reserve空间 svec 重新分配了一个空间 并使用移动构造搬过去
    svec.push_back("plus"); //移动构造
    //增加移动操作后 最后一个push_back的参数是右值引用 构造时使用了移动构造
}

class Foo{
    public:
        Foo();
        Foo(const initializer_list<int>& il) {
            for (auto i : il) {
                v.push_back(i);
            }
        }
        Foo sorted() const &;
        Foo sorted() &&;

    private:
        vector<int> v;

};

inline Foo Foo::sorted() const & {
    Foo ret(*this);
    cout << "const &" << endl;
    sort(ret.v.begin(),ret.v.end());
    return ret;
}

inline Foo Foo::sorted() && {
    cout << "&&" << endl;
    sort(v.begin(),v.end());
    return *this;
}



int main()
{
    //13.13
    // run_X();

    //13.14
    // run_numbered();

    //13.18
    // Employee e("shieve");
    // cout << e.num << endl;
    // Employee e2;
    // cout << e2.num << endl;
    // Employee e3("cheer");
    // cout << e3.num << endl;
    // Employee e4(e3);
    // cout << e4.name << " " << e4.num << endl;
    // Employee e5 = e4;
    // cout << e5.name << " " << e5.num << endl;

    //13.22
    //13.30
    // run_Has_ptr();

    //13.27
    // run_Has_ptr_ref();

    //13.28
    // run_tree_node();

    //13.31
    // run_has_ptr_vec();

    //13.37
    // run_msg_folder();

    //13.39
    // run_str_vec_pre();

    //13.44
    // run_my_string();

    //13.48
    
    
    //p482
    // Str_vec svec{"one","two","three"};
    // svec.push_back("four"); //push_back(string&&)
    // string s5("five");
    // svec.push_back(s5); //push_back(const string&)

    //13.55
    // Str_blob svec{"one","two"};
    // svec.push_back("three"); //string&&
    // string s3("four");
    // svec.push_back(s3); //const string&

    //13.58
    // Foo f{7,5,3};
    // f.sorted(); //const &
    // Foo{1,2,3}.sorted(); //&&


    return 0;
    
}


