#ifndef NOT_QUERY
#define NOT_QUERY
#include "query_base.h"
#include "query.cpp"

class Not_query : public Query_base {
    friend Query operator ~ (const Query&);

    Not_query(const Query&);

    Text_query_result_str_vec eval(const Text_query_str_vec&) const override;
    string rep() const override;

    Query query; //其实还是智能指针
};

#endif