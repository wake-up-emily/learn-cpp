#ifndef QUERY
#define QUERY
#include "query_base.h"

//接口类
class Query : public Query_base {
    friend Query operator ~ (const Query&);
    friend Query operator & (const Query&, const Query&);
    friend Query operator | (const Query&, const Query&);
    friend ostream& operator << (ostream&, const Query&);
    public:
        Query(const string&); //构建一个新的word_query

        //接口类的虚函数实际是需要调用各个派生类自己的虚函数实现
        Text_query_result_str_vec eval(const Text_query_str_vec&) const override;
        string rep() const override;

        //由于使用智能指针 可以安全使用编译器提供的合成拷贝 赋值 移动 析构等 由智能指针管理其生命周期
    private:
        Query(shared_ptr<Query_base>); //支持运算符的构造函数
        shared_ptr<Query_base> q; //空智能指针
};

#endif