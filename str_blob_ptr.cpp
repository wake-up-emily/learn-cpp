#include "str_blob_ptr.h"
#include <string>
#include <iostream>

inline shared_ptr<vector<string>> Str_blob_ptr::check(const size_t& sz,const string& msg) {
    auto sptr = wptr.lock();
    if (!sptr) {
        throw runtime_error("unbound ptr");
    }
    if (sz > sptr->size()) {
        throw runtime_error(msg);
    }
    return sptr;
}

inline Str_blob_ptr Str_blob::begin() {
    return Str_blob_ptr(*this);
}

inline Str_blob_ptr Str_blob::end() {
    return Str_blob_ptr(*this,data->size());
}

inline const string& Str_blob::at(const size_t& sz) const {
    auto it = Str_blob_ptr(*this,sz);
    return *it;
}

inline bool operator == (const Str_blob_ptr& lhs, const Str_blob_ptr& rhs) {
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r) { //两个指针都为空 或指向同一个对象
        return (!r || lhs.curr == rhs.curr); // 不指向任何对象 可 ||同一个对象的同一个位置 可
    }
    return false;
}

inline Str_blob_ptr& Str_blob_ptr::operator++ () {
    auto sptr = check(curr,"increasement past end");
    ++curr;
    return *this; 
}

inline const string& Str_blob_ptr::operator* () {
    auto sptr = check(curr,"dereference past end");
    return (*sptr)[curr];
}

inline const string& Str_blob_ptr::deref (const size_t& sz) {
    auto sptr = check(curr,"dereference past end");
    return (*sptr)[sz];
}

inline Str_blob_ptr Str_blob_ptr::operator = (const Str_blob_ptr& item) {
    Str_blob_ptr cp(item);
    return cp;
}

inline Str_blob_ptr& Str_blob_ptr::incr() {
    auto sptr = check(curr,"increasement past end");
    ++curr;
    return *this;
}
inline bool eq(const Str_blob_ptr &lhs, const Str_blob_ptr &rhs) {
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if (l == r) {
        return ( !r || lhs.curr == rhs.curr);
    }
    else {
        return false;
    };
}
inline bool neq(const Str_blob_ptr &lhs, const Str_blob_ptr &rhs) {return !eq(lhs,rhs);};