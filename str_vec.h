#ifndef STR_VEC
#define STR_VEC

#include <string>
#include <memory>
using std::allocator;
using std::string;
using std::initializer_list;

class Str_vec {

    public:
        Str_vec()
        : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        Str_vec(const initializer_list<string>&);
        Str_vec(const Str_vec&);
        Str_vec& operator= (const Str_vec&);
        Str_vec(Str_vec&&) noexcept;
        Str_vec& operator=(Str_vec&&) noexcept;
        ~Str_vec();
    public:
        size_t size() {return first_free - elements;}
        size_t capacity() {return cap - elements; }
        string* begin() {return elements;}
        string* end() {return first_free;}
        string at(const size_t&);
        void push_back(const string&); //调用check_n_alloc确保至少有一个可用空间 如果没有reallocate后添加新元素
        void push_back(string&&);
        void reserve(const size_t&);
        void resize(const size_t&,const string&);
    private:
        static allocator<string> alloc; //static成员变量需要类外定义 类内没有初始化 会报错头文件引入问题
        // allocator<string> alloc;
        std::pair<string*,string*> alloc_n_copy(const string*,const string*); //用于拷贝构造和拷贝构造
        void free(); //销毁元素 归还分配的内存
        void chk_n_alloc() {
            if (size() == capacity()) {
                reallocate();
            }
        } //当没有空间容纳新元素 即first_free == cap时 调用reallocate重新分配内存
        void reallocate(); //分配两倍大小的空间 （每个元素的地址）拷贝到新空间 重置三个定位指针的位置 和拷贝很像
        void reallocate(const size_t&); //reserve的辅助函数

        string* elements; //first element
        string* first_free;
        string* cap; //one after last element
};

#endif