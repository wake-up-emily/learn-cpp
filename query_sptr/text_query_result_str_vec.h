#ifndef TEXT_QUERY_RESULT_STR_VEC
#define TEXT_QUERY_RESULT_STR_VEC

#include "text_query_str_vec.cpp"

class Text_query_result_str_vec {
    friend ostream& print(ostream&,const Text_query_result_str_vec&);
    public:
        using word_it = vector<size_t>::const_iterator;
        Text_query_result_str_vec(Text_query_str_vec::str_blob& blob, Text_query_str_vec::word_line_set& w_set, const string& w )
        : tr_file(blob), tr_words(w_set), word(w) {}
        Text_query_result_str_vec(const Text_query_str_vec::str_blob& blob, const Text_query_str_vec::word_line_set& w_set, const string& w )
        : tr_file(blob), tr_words(w_set), word(w) {}
        shared_ptr<Str_vec> get_file() {return tr_file;}
        size_t size() { return tr_words->size();}
        word_it begin() {return tr_words->cbegin();}
        word_it end() {return tr_words->cend();}

    private:
        Text_query_str_vec::str_blob tr_file;
        Text_query_str_vec::word_line_set tr_words;
        string word;
};


#endif