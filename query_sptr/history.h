#ifndef HISTORY
#define HISTORY

#include <vector>
#include <iostream>
using std::vector;
using std::shared_ptr;
using std::cout;
using std::endl;
using std::make_shared;

class Query_base;

class History {
    public:
        History();
        size_t size();
        void show_history();
        Query_base* query(const size_t&);
        void push_back(Query_base*);
    private:
        shared_ptr<vector<Query_base*>> history;
};

#endif