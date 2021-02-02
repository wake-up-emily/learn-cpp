#include "str_vec.h"
using std::uninitialized_copy;
using std::runtime_error;

allocator<string> Str_vec::alloc;

inline Str_vec::Str_vec(const initializer_list<string>& il) {
    std::pair<string*,string*> data = alloc_n_copy(il.begin(),il.end());
    elements = data.first;
    cap = first_free = data.second;
}

inline void Str_vec::push_back(const string& s) {
    chk_n_alloc();
    alloc.construct(first_free++,s); //后++ 使用当前值构造 构造后+1
    cout << "push_back(const string&)" << endl;
}

inline void Str_vec::push_back(string&& s) {
    chk_n_alloc();
    alloc.construct(first_free++,std::move(s)); //后++ 使用当前值构造 构造后+1
    cout << "push_back(string&&)" << endl;
}

inline std::pair<string*,string*> 
Str_vec::alloc_n_copy(const string* b,const string* e) {
    string* data = alloc.allocate(e - b);
    return {data,uninitialized_copy(b,e,data)}; //返回copy后的首元素和尾元素之后的元素
}

// inline void Str_vec::free() {
//     if (elements) { //不能传给deallocate空指针 传空指针则什么也不做
//         for (auto p=first_free;p!=elements;) {
//             alloc.destroy(--p); //对对象中元素逆序析构
//         }
//         alloc.deallocate(elements,cap-elements); //归还分配的内存 第一个参数必须是之前某词调用allocate返回的指针 必须检查是否为空
//     }
// }

inline void Str_vec::free() {
    if (elements) { //不能传给deallocate空指针 传空指针则什么也不做
        // for (auto p=first_free;p!=elements;) {
        //     alloc.destroy(--p); //对对象中元素逆序析构
        // }
        //13.43 for_each版本 无需控制指针的移动
        for_each(elements,first_free,[](string& s)->void{alloc.destroy(&s);});
        alloc.deallocate(elements,cap-elements); //归还分配的内存 第一个参数必须是之前某词调用allocate返回的指针 必须检查是否为空
    }
}

inline Str_vec::Str_vec(const Str_vec& rhs) {
    std::pair<string*,string*> new_data = alloc_n_copy(rhs.elements,rhs.first_free);
    elements = new_data.first;
    first_free = cap = new_data.second;
}

inline Str_vec::Str_vec(Str_vec&& rhs) noexcept
: elements(rhs.elements),first_free(rhs.first_free),cap(rhs.cap) {
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
}

inline Str_vec::~Str_vec() {
    free();
}

inline Str_vec& Str_vec::operator=(const Str_vec& rhs) {
    std::pair<string*,string*> new_data = alloc_n_copy(rhs.elements,rhs.first_free);
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    return *this;
}

inline Str_vec& Str_vec::operator=(Str_vec&& rhs) noexcept {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
    return *this;
}

inline void Str_vec::reallocate() {
    size_t new_capacity = size() ? 2*size() : 1; //得到两倍空间大小
    string* new_data = alloc.allocate(new_capacity); //分配两倍空间大小
    auto dest = new_data; //指向下一个空间位置
    auto elem = elements; //指向下一个元素
    for (size_t i=0; i < size(); ++i) { //把每个元素搬到新地址
        alloc.construct(dest++,std::move(*elem++)); //和push_back类似 这里用了右值引用类型的参数 会调用移动构造 更快
    }
    free(); //搬完清场
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

inline void Str_vec::reallocate(const size_t& new_capacity) {
    string* new_data = alloc.allocate(new_capacity); //分配两倍空间大小
    auto dest = new_data; //指向下一个空间位置
    auto elem = elements; //指向下一个元素
    for (size_t i=0; i < size(); ++i) { //把每个元素搬到新地址
        alloc.construct(dest++,std::move(*elem++)); //和push_back类似
    }
    free(); //搬完清场
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;

}

inline void Str_vec::reserve(const size_t& sz) {
    if (sz > capacity()) {
        reallocate(sz);
    }
}

inline void Str_vec::resize(const size_t& sz,const string&s = std::string()) {
    //n > c.size()时 添加(n-c.size())个初始值到c末尾
    if (sz > size()) {
        // for (size_t i=sz;i!=size();--i) {
        // 不知道循环次数时用while合适
        while (size() < sz) {
            push_back(s);
        }
    }
    //否则丢弃末尾元素使 c.size() = n
    // for (auto p=first_free;p!=elements+sz;) {
    while (size() > sz) {
        alloc.destroy(--first_free); //对对象中元素逆序析构
    }
}

inline const string& Str_vec::at(const size_t& sz) const {
    size_t max_diff = cap - elements;
    if (sz < max_diff) {
        return *(elements + sz);
    }
    throw runtime_error("index out of range");
}
