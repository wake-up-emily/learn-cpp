#ifndef TEXT_QUERY_RESULT_STR_VEC
#define TEXT_QUERY_RESULT_STR_VEC

#include "text_query_str_vec.cpp"

class Text_query_result_str_vec {
    friend ostream& print(ostream&,const Text_query_result_str_vec&);
    public:
        Text_query_result_str_vec(Text_query_str_vec::str_blob& blob, Text_query_str_vec::word_line_set& w_set, const string& w )
        : tr_file(blob), tr_words(w_set), word(w) {}
    private:
        Text_query_str_vec::str_blob tr_file;
        Text_query_str_vec::word_line_set tr_words;
        string word;
};


#endif