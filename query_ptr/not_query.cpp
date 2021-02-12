#include "not_query.h"

inline Not_query::Not_query(const Query& q)
: query(q) {cout << "not_query构造+1" << endl;}

inline string Not_query::rep() const {
    cout << "not_query rep" << endl;
    return "~(" + query.rep() + ")" ;
}

inline Query operator ~ (const Query& q) {
    return new Not_query(q);
}

inline Text_query_result_str_vec Not_query::eval(const Text_query_str_vec& t) const {
    Text_query_result_str_vec origin = query.eval(t);
    cout << "origin: " << endl;
    print(cout,origin) << endl;
    shared_ptr<vector<size_t>> not_set = make_shared<vector<size_t>>();
    auto b = origin.begin();
    auto e = origin.end();
    //循环相当于创建一个大的集合 元素是从0到wordl_line_set.size()
    //循环内判断 大集合的元素和迭代器指向的元素是否相等 只留下不相等的那些存入not_set
    size_t line = 0;
    for (size_t n = 0;n!=origin.get_file()->size();++n) {
        auto found = find(b,e,n);
        if (found == e) {
            not_set->push_back(n);
        }
    }
    return Text_query_result_str_vec(origin.get_file(),not_set,rep());
    
}