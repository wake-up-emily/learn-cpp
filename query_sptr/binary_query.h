#ifndef BINARY_QUERY
#define BINARY_QUERY

#include "query_base.h"
#include "query.cpp"

class Binary_query : public Query_base {
    protected:
        Binary_query(const Query& l, const Query& r, const string& op)
        : lhs(l), rhs(r), operator_name(op) {cout << "binary_query构造+1" << endl;}
        string rep() const override { 
            cout << "binary_query rep" << endl;
            return "(" + lhs.rep() + " " + operator_name + " " + rhs.rep() + ")" ;
        }
        Query lhs,rhs;
        string operator_name;
};

#endif