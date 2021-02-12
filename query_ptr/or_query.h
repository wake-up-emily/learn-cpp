#ifndef OR_QUERY
#define OR_QUERY

#include "binary_query.h"

class Or_query : public Binary_query {
    friend Query operator | (const Query&, const Query&);

    Or_query(const Query&, const Query&);

    Text_query_result_str_vec eval(const Text_query_str_vec&) const override;
};

#endif