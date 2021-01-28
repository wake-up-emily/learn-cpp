#include "text_query_simple.h"

inline Text_query_simple::Text_query_simple(ifstream& fin) {
    string line,word;
    int i = 1;
    while (getline(fin,line)) {
        lines.push_back(line);
        istringstream sin(line);
        while (sin >> word) {
            words[word].insert(i);
        }
        ++i;
    }
}

inline void Text_query_simple::query(const string& word) const {
    auto first_qualified = *this->words.find(word);
    if (first_qualified != *this->words.cend()) {
        auto wset = first_qualified.second;
        string if_single = wset.size() > 1 ? "s" : "";
        cout << word << " occurs " << wset.size() << " time" << if_single << endl;
        for (auto word_line:wset) {
            cout << "line (" << word_line << ") " << lines[word_line-1] << endl;
        }
    }
}

inline void Text_query_simple::query_file(const string& file) const {
    ifstream fin(file);
    string word;
    while (fin >> word) {
        auto first_qualified = *this->words.find(word);
        if (first_qualified != *this->words.cend()) {
            auto wset = first_qualified.second;
            string if_single = wset.size() > 1 ? "s" : "";
            cout << word << " occurs " << wset.size() << " time" << if_single << endl;
            for (auto word_line:wset) {
                cout << "line (" << word_line << ") " << lines[word_line-1] << endl;
            }
        }
    }
}