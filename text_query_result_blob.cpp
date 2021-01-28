#include "text_query_result_blob.h"

Text_query_result_blob Text_query_blob::query(const string& word) const {
    auto res = words.find(word);
    if (res != words.cend()) { //found
        return Text_query_result_blob(file,res->second,word);
    }
    else
    {
        static word_line_set w_set = make_shared<vector<size_t>>(); //不是static也可以 但是static的话 在main程序结束之前的多个query_result对象可以共享数据 节约开销
        return Text_query_result_blob(file,w_set,word);
    }
}

inline ostream& print(ostream& out,const Text_query_result_blob& tr) {
    size_t sz = tr.tr_words->size();
    string if_single = sz > 1 ? "s" : "";
    out << tr.word << " occurs " << sz << " time" << if_single << endl;
    for (auto line:(*tr.tr_words)) {
        string text = tr.tr_file.at(line-1); //the object has type qualifiers that are not compatible with the member function "Str_blob::at" -- object type is: const Text_query_blob::str_blob 所以at得是const
        out << "\tline (" << line << ") " << text << endl;
    }
    return out;
}