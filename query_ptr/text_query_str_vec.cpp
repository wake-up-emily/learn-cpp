#include "text_query_str_vec.h"

inline Text_query_str_vec::Text_query_str_vec(ifstream& fin) : file(new Str_vec()) {
    string line,word;
    size_t i = 0;
    while (getline(fin,line)) {
        file->push_back(line);
        istringstream sin(line);
        while (sin >> word) {
            auto& p = words[word]; //必须传引用 因为需要对原值修改
            if (!p) {   //第一次添加单词到vector p此时为nullptr 内存地址0 引用计数0 未指向一个动态对象
                // auto p(make_shared<vector<size_t>>()); //这样是不行的 p是一个已经存在的智能指针 只能通过.reset()交换指针 并不能通过make_shared去构造
                p.reset(new vector<size_t>()); //new 分配内存和引用计数是分开的 先分配内存 返回内置指针 引用次数1 p通过reset 交换指针 指向动态对象 引用次数1
            }
            p->push_back(i);
        }
        ++i;
    }
}