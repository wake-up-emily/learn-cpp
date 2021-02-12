#include "or_query.h"

inline Or_query::Or_query(const Query& lhs, const Query& rhs)
: Binary_query(lhs,rhs,"|") {
    cout << "or_query构造+1" << endl;
}

inline Query operator | (const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new Or_query(lhs,rhs));
}

inline Text_query_result_str_vec Or_query::eval(const Text_query_str_vec& t) const {
    Text_query_result_str_vec l  = lhs.eval(t);
    Text_query_result_str_vec r = rhs.eval(t);
    auto new_set = make_shared<vector<size_t>>(l.begin(),l.end());
    new_set->insert(new_set->end(),r.begin(),r.end());
    return Text_query_result_str_vec(l.get_file(),new_set,rep());
}

