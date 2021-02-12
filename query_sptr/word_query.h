#ifndef WORD_QUERY
#define WORD_QUERY
#include "query.h"

class Word_query : public Query_base {
    friend class Query;
    Word_query(const string& s) : word(s) {cout << "word_query构造+1" << endl;}
    
    Text_query_result_str_vec eval(const Text_query_str_vec& t) const override {
        return t.query(word);
    }
    string rep() const override {
        cout << "words_query rep" << endl;
        return word;
    }
    
    string word;
};

#endif