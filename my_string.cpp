#include "my_string.h"

allocator<char> My_string::a;

inline bool operator== (const My_string& lhs,const My_string& rhs) {
    if (lhs.sz == rhs.sz) {
        for(size_t curr=0;curr!=lhs.sz;++curr) {
            if (*(lhs.p+curr) == *(rhs.p+curr)) {
                return true;
            }
        }
    }
    return false;
}

inline ostream& operator<< (ostream& os,const My_string& rhs) {
    print(os,rhs);
    return os;
}

inline ostream& print(ostream& os,const My_string& rhs) {
    auto p = rhs.p;
    for_each(rhs.p,rhs.p+rhs.sz,[&os](const char& c)->ostream&{os << c; return os;});
    return os;
}

inline My_string operator+ (const My_string& lhs, const My_string& rhs) {
    My_string new_string;
    auto new_sz = lhs.sz+rhs.sz;
    auto p =new_string.a.allocate(new_sz);
    auto next_first = uninitialized_copy(lhs.p,lhs.p+lhs.sz,p);
    uninitialized_copy(rhs.p,rhs.p+rhs.sz,next_first);
    new_string.sz = new_sz;
    new_string.p = p;
    return new_string;
}