#ifndef QUERY_BASE
#define QUERY_BASE
#include "text_query_result_str_vec.cpp"

class Query_base {
    friend class Query;
    friend class History;
    friend class Text_query_str_vec;
    protected:
        virtual ~Query_base() = default;
    private:
        //定义为protected或者private主要是针对第三类用户派生类 本例我感觉其实没差

        //交代与或非各种派生类定义自己的query_result和查询的string
        virtual Text_query_result_str_vec eval(const Text_query_str_vec&) const = 0;
        virtual string rep() const = 0;
};

#endif