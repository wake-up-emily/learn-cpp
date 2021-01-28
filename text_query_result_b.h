#ifndef TEXT_QUERY_RESULT
#define TEXT_QUERY_RESULT

#include "text_query_b.cpp"

class Text_query_result_b {
    friend ostream& print(ostream&,const Text_query_result_b&);
    public:
        Text_query_result_b(Text_query_b::str_blob& blob, Text_query_b::word_line_set& w_set, const string& w )
        : tr_file(blob), tr_words(w_set), word(w) {}
    private:
        Text_query_b::str_blob tr_file;
        Text_query_b::word_line_set tr_words;
        string word;
};


#endif