#include "text_query_result_b.cpp"
#include "text_query_result_blob.cpp"
#include "text_query_simple.cpp"
#include <fstream>
#include <iostream>

//检查str_blob类和str_blob_ptr类是否能用
void show_blob(const string& file) {
    ifstream fin(file);
    string line;
    Str_blob blob;
    while (getline(fin,line)) {
        blob.push_back(line);
        // cout << line << endl;
    }
    Str_blob_ptr b = blob.begin();
    Str_blob_ptr e = blob.end();

    //检查操作符重载是否生效
    for (Str_blob_ptr it=b; it != e; ++it) {
        cout << (*it) << endl;
    }

    //检查操作符重载的替代函数是否生效
    // for (auto it=b; neq(it,e); it.incr()) {
    //     cout << (*it) << endl;
    //     cout << it.index() << endl;
    // }
}

//检查改变接口 不进行数据共享的类是否能用
void run_query_simple(ifstream& fin) {
    Text_query_simple tq(fin);
    string file("query_words.txt");
    tq.query_file(file);
}

//检查使用using假封装的类是否能用
void run_query_b(const string& file) {
    ifstream fin(file);
    // string s("are");
    vector<string> svec{"are","blue"};
    Text_query_b tq(fin);
    for (auto s:svec) {
        print(cout,tq.query(s)) << endl;
    }
}

//检查使用自定义类的类是否能用
void run_query_blob(const string& file) {
    ifstream fin(file);
    // string s("are");
    vector<string> svec{"are","blue"};
    Text_query_blob tq(fin);
    for (auto s:svec) {
        print(cout,tq.query(s)) << endl;
    }
}

//检查reset离开作用域对象是否会销毁 make_shared离开作用域对象是否被销毁 
//结论是 reset离开作用域对象不销毁 make_shared离开作用域对象销毁
void show_ptr() {

    shared_ptr<vector<size_t>> p;
    cout << "show p use_count when created " << endl;
    cout << p.use_count() << endl;
    if (!p) {
        cout << "p not bound to a dynamic obj" << endl; 

        // cout << "bind and return address by reset" << endl;
        // p.reset(new vector<size_t>());
        // cout << "show p use_count inside if " << endl;
        // cout << p.use_count() << endl;
        
        cout << "bind and return address by make_shared" << endl;
        auto q = make_shared<vector<size_t>>();
        auto p (q);
        cout << "show p use_count inside if " << endl;
        cout << p.use_count() << endl;
    }
    cout << "show p use_count outside if " << endl;
    cout << p.use_count() << endl;
    p->push_back(1);
    cout << "show p use_count outside if after push back " << endl;
    cout << p.use_count() << endl;

}

//进一步提问 make_shared可以赋值给已经存在的shared_ptr吗？
//不能
//已存在的智能指针不能通过make_shared重新绑定到新的动态对象上 只能通过reset重新绑定
//空智能指针也不可
//make_shared通过拷贝赋值和拷贝构造 构造一个shared_ptr
shared_ptr<int> foo() {

    auto p = make_shared<int>(42);  // 此时p的引用计数为1
    cout << "show p use_count inside if " << endl;
    cout << p.use_count() << endl;

    return p;   // 此时p的引用计数为2 

}

void show_foo(){
    // shared_ptr<int> p;
    auto p = foo(); //取消上行的注释 会出现 error: redefinition of 'p'
    cout << "show p use_count outside if " << endl;
    cout << p.use_count() << endl;
}


int main()
{
    // show_blob("data.txt");

    // show_ptr();
    // show_foo();

    // ifstream fin("data.txt");
    // run_query_simple(fin);

    // string file("data.txt");
    // run_query_b(file);

    //ld: symbol(s) not found for architecture x86_64 一般是头文件引入错误 
    //实测分离式编译.cpp文件都引.cpp不容易出错 否则根据提示检查

    // string file("data.txt");
    // run_query_blob(file); 


    return 0;
    
}


