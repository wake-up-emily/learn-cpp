#ifndef TEXT_QUERY_BLOB
#define TEXT_QUERY_BLOB

#include "str_blob_ptr.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Text_query_result_blob;

class Text_query_blob {
    friend class Text_query_result_blob;
    public:
        using str_blob = Str_blob;
        using word_line_set = shared_ptr<vector<size_t>>; //size_t是标准库定义的类型 在不同的机器上自动调节大小 unsigned long || unsigned long long etc.
        Text_query_blob(ifstream&);
    public:
        Text_query_result_blob query(const string&) const; //因为print接收的参数要求是const 所以这边函数返回的必须是const
    private:
        str_blob file;
        map<string,word_line_set>  words;

};

#endif