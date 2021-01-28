#ifndef TEXT_QUERY_B
#define TEXT_QUERY_B

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Text_query_result_b;

class Text_query_b {
    friend class Text_query_result_b;
    public:
        using str_blob = shared_ptr<vector<string>>;
        using word_line_set = shared_ptr<vector<size_t>>; //size_t是标准库定义的类型 在不同的机器上自动调节大小 unsigned long || unsigned long long etc.
        Text_query_b(ifstream&);
    public:
        Text_query_result_b query(const string&);
    private:
        str_blob file;
        map<string,word_line_set>  words;

};

#endif