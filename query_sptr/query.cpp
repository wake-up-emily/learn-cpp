#include "query.h"
#include "word_query.h"

inline Query::Query(const string& s)
: q(new Word_query(s)) {}

inline Query::Query(shared_ptr<Query_base> query) 
: q(query) {cout << "Query构造+1" << endl;}

inline ostream& operator << (ostream& out, const Query& q) {
        out << q.rep() << endl;
        return out;
}

inline Text_query_result_str_vec Query::eval(const Text_query_str_vec& query) const {
    query.h.push_back(q.get());
    return q->eval(query);
}

inline Text_query_result_str_vec Text_query_str_vec::query(const size_t& n) const {
    return h.query(n)->eval(*this);
}

inline void History::show_history() {
    cout << "查询编号\t查询名称" << endl;
    for (size_t n=1;n<=size();++n) {
        cout << n << "\t" << history->at(n-1)->rep() << endl;        
    }
}

inline string Query::rep() const {
    cout << "query rep" << endl;
    return q->rep();
}