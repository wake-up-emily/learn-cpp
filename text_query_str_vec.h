#ifndef TEXT_QUERY_STR_VEC
#define TEXT_QUERY_STR_VEC

#include "str_vec.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Text_query_result_str_vec;

class Text_query_str_vec {
    friend class Text_query_result_str_vec;
    public:
        using str_blob = shared_ptr<Str_vec>;
        using word_line_set = shared_ptr<vector<size_t>>; //size_t是标准库定义的类型 在不同的机器上自动调节大小 unsigned long || unsigned long long etc.
        Text_query_str_vec(ifstream&);
    public:
        size_t show_file_size() {return (*file).size(); }
        shared_ptr<Str_vec> get_file() {return file;}
        Text_query_result_str_vec query(const string&); //因为print接收的参数要求是const 所以这边函数返回的必须是const
    private:
        str_blob file;
        map<string,word_line_set> words;

};

#endif