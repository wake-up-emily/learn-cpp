#include "text_query_result_str_vec.h"

Text_query_result_str_vec Text_query_str_vec::query(const string& word) {
    auto res = words.find(word);
    if (res != words.cend()) { //found
        return Text_query_result_str_vec(file,res->second,word);
    }
    else
    {
        static word_line_set w_set = make_shared<vector<size_t>>();
        return Text_query_result_str_vec(file,w_set,word);
    }
}

inline ostream& print(ostream& out,const Text_query_result_str_vec& tr) {
    size_t sz = tr.tr_words->size();
    string if_single = sz > 1 ? "s" : "";
    out << tr.word << " occurs " << sz << " time" << if_single << endl;
    for (auto line:(*tr.tr_words)) {
        string text = tr.tr_file->at(line-1);
        out << "\tline (" << line << ") " << text << endl;
    }
    return out;
}