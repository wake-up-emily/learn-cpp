#ifndef MY_STRING
#define MY_STRING

#include <memory>
#include <iostream>
using std::allocator;
using std::initializer_list;
using std::uninitialized_copy;
using std::uninitialized_fill_n;
using std::ostream;

class My_string {
    friend bool operator== (const My_string&, const My_string&);
    friend ostream& operator<< (ostream&,const My_string&);
    friend ostream& print(ostream&,const My_string&); //辅助函数

    friend My_string operator+ (const My_string&, const My_string&);
    public:
        size_t size() {return sz;}
    public:
        My_string()=default;
        My_string(const char* cp)
        :sz(strlen(cp)),p(a.allocate(strlen(cp))) {uninitialized_copy(cp,cp+sz,p);}
        My_string(const char* cp,const size_t& n)
        :sz(n),p(a.allocate(n)) {uninitialized_copy(cp,cp+n,p);}
        My_string(const My_string& rhs)
        :sz(rhs.sz),p(a.allocate(rhs.sz)) {
            uninitialized_copy(rhs.p,rhs.p+sz,p);
            cout << "拷贝构造+1" << endl;
            }
        My_string(My_string&& rhs) noexcept
        :sz(rhs.sz),p(rhs.p) {
            rhs.sz = 0;
            rhs.p = nullptr;
            cout << "移动构造+1" << endl;
            }
        My_string(const size_t& n,const char& c)
        :sz(n),p(a.allocate(n)) {uninitialized_fill_n(p,n,c);}
        My_string& operator=(const My_string& rhs) {
            if (this == &rhs) {
                return *this;
            }
            if (p) {
                a.deallocate(p,sz);
            }
            sz = rhs.sz;
            p = a.allocate(rhs.sz);
            uninitialized_copy(rhs.p,rhs.p+sz,p);
            cout << "拷贝赋值+1" << endl;
            return *this;
        }
        My_string& operator=(My_string&& rhs) noexcept {
            if (this != &rhs) {
                if (p) {
                a.deallocate(p,sz);
                }
                sz = rhs.sz;
                p = rhs.p;
                rhs.p = nullptr;
                rhs.sz = 0;
                cout << "移动赋值+1" << endl;
            }
            return *this;
        }
        ~My_string(){
            if (p) {
                a.deallocate(p,sz);
            }
        }
    private:
        char* p = nullptr;
        static allocator<char> a;
        size_t sz;
};

#endif