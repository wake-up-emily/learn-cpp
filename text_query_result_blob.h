#ifndef TEXT_QUERY_RESULT_BLOB
#define TEXT_QUERY_RESULT_BLOB

#include "text_query_blob.cpp"

class Text_query_result_blob {
    friend ostream& print(ostream&,const Text_query_result_blob&);
    public:
        Text_query_result_blob(Text_query_blob::str_blob blob, Text_query_blob::word_line_set w_set, const string& w )
        : tr_file(blob), tr_words(w_set), word(w) {}
    private:
        Text_query_blob::str_blob tr_file;
        Text_query_blob::word_line_set tr_words;
        string word;
};


#endif