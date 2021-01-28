#ifndef TEXT_QUERY_SIMPLE
#define TEXT_QUERY_SIMPLE

#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


class Text_query_simple {
    friend class Text_query_result_simple;
    public:
        Text_query_simple(ifstream&);

    public:
        void query(const string&) const;
        void query_file(const string&) const;

    private:
        vector<string> lines;
        map<string,set<int>> words;
        void initialize(ifstream&);
};

#endif