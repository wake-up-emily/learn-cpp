#include "query.h"
#include "word_query.h"

inline Query::Query(const string& s)
: q(new Word_query(s)), ref_count(new size_t(1)) {}

inline Query::Query(Query_base* query) 
: q(query),ref_count(new size_t(1)) {cout << "Query构造+1" << endl;}

inline Query::Query(const Query& p)
: q(p.q), ref_count(p.ref_count) {++*ref_count;}

inline Query& Query::operator= (const Query& p) {
    ++*p.ref_count;
    free();
    q = p.q;
    ref_count = p.ref_count;
    return *this;
}

inline void Query::free() {
    if (--*ref_count == 0) {
        delete q;
        delete ref_count;
    }
}

inline Query::~Query() {
    free();
}

inline ostream& operator << (ostream& out, const Query& q) {
        out << q.rep() << endl;
        return out;
}

inline Text_query_result_str_vec Query::eval(const Text_query_str_vec& query) const {
    return q->eval(query);
}

inline string Query::rep() const {
    cout << "query rep" << endl;
    return q->rep();
}