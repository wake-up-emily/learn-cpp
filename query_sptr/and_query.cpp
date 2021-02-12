#include "and_query.h"
#include <algorithm>

inline And_query::And_query(const Query& lhs, const Query& rhs)
: Binary_query(lhs,rhs,"&") {
    cout << "and_query构造+1" << endl;
}

inline Query operator & (const Query& lhs, const Query& rhs) {
    return shared_ptr<Query_base>(new And_query(lhs,rhs));
}

inline Text_query_result_str_vec And_query::eval(const Text_query_str_vec& t) const {
    Text_query_result_str_vec l = lhs.eval(t);
    Text_query_result_str_vec r = rhs.eval(t);
    shared_ptr<vector<size_t>> new_set = make_shared<vector<size_t>>();
    // set_intersection(l.begin(),l.end(),r.begin(),r.end(),new_set->begin());
    //如果不用inserter会报错内存溢出 因为目前容器是空的 
    set_intersection(l.begin(),l.end(),r.begin(),r.end(),inserter(*new_set,new_set->begin()));
    return Text_query_result_str_vec(l.get_file(),new_set,rep());
}