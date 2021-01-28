#ifndef STR_BLOB_PTR
#define STR_BLOB_PTR

#include <vector>
#include "str_blob.h"
using namespace std;

class Str_blob_ptr {
    friend bool operator == (const Str_blob_ptr&, const Str_blob_ptr&); //非成员函数
    friend bool operator != (const Str_blob_ptr& p1, const Str_blob_ptr& p2) {return !(p1 == p2); };
    friend bool eq(const Str_blob_ptr&, const Str_blob_ptr&); //重载运算符的替代形函数
    friend bool neq(const Str_blob_ptr&, const Str_blob_ptr&);
    public:
        Str_blob_ptr()
        :curr(0) {} //会通过wptr检查指针类是否确实指向数据还是空指针

        Str_blob_ptr(Str_blob& blob,const size_t& sz=0)
        : wptr(blob.data), curr(sz) {}

        Str_blob_ptr(const Str_blob& blob,const size_t& sz=0)
        : wptr(blob.data), curr(sz) {}

        Str_blob_ptr(const Str_blob_ptr& item)
        : curr(item.curr), wptr(item.wptr.lock()) {}

        Str_blob_ptr operator = (const Str_blob_ptr&);
        
    public:
        Str_blob_ptr& operator ++ (); //成员函数
        const string& operator* ();
        const size_t& index() {return curr;};
        Str_blob_ptr& incr();
        const string& deref(const size_t&);

    private:
        size_t curr;
        shared_ptr<vector<string>> check(const size_t&,const string&);
        weak_ptr<vector<string>> wptr;
};

#endif