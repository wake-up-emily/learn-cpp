#ifndef AND_QUERY
#define AND_QUERY
#include "binary_query.h"

class And_query : public Binary_query {
    friend Query operator & (const Query&, const Query&);

    And_query(const Query&, const Query&);

    Text_query_result_str_vec eval(const Text_query_str_vec&) const override;
    
};

#endif