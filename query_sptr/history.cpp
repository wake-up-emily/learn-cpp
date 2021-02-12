#include "history.h"

inline History::History() 
:history(make_shared<vector<Query_base*>>()) {}

inline size_t History::size() {return history->size();}

inline Query_base* History::query(const size_t& if_in_history) {
    if (if_in_history <= size()) {
        return history->at(if_in_history-1);
    }
    return *history->end();
}

inline void History::push_back(Query_base* p) {
    history->push_back(p);
}