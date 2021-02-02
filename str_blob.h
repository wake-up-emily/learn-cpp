#ifndef STR_BLOB
#define STR_BLOB
#include <vector>
using namespace std;

class Str_blob_ptr;

class Str_blob {
    friend class Str_blob_ptr;
    public:
        Str_blob()
        : data(make_shared<vector<string>>()) {}
        
        Str_blob(initializer_list<string> il)
        :data(make_shared<vector<string>>(il)) {}
    public:
        using sz = vector<string>::size_type;
        sz size() {return data->size();};
        void push_back(const string& s) { cout << "const string&" << endl; return data->push_back(s);}
        void push_back(string&& s){ cout << "string&&" << endl; return data->push_back(s);}
        Str_blob_ptr begin();
        Str_blob_ptr end();
        const string& at(const size_t&) const;
        
    private:
        shared_ptr<vector<string>> data; //带指针的类
        void check(const int&,const string&) const; //检查函数不改变data的数据
};

#endif
