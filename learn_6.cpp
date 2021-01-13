#include <iostream> // Include for I/O streams
using namespace std; // Streams are in the std namespace (standard library)
#include <vector>

//6.4
int fact(int val) {
    if (val < 0) {
        return -1;
    }

    int ret = 1;
    for (int i=2;i!=val+1;++i) {
        ret *= i;
    }
    return ret;
}

//6.5
double my_abs(double i) {
    if (i < 0) {
        return -i;
    }
    return i;
}

//6.7
unsigned int call_cnt() {
    static unsigned int cnt = 0;
    return cnt++;
}

//6.10
void change_val(int &val1, int &val2) {
    int tmp = val1;
    val1 = val2;
    val2 = tmp;
}

//6.17
bool contain_upper(const string s) {
    bool contain = false;
    for (auto c : s) {
        if (isupper(c)) {
            contain = true;
            break;
        }
    }
    return contain;
}

string& my_to_lower(string &s) {
    for (auto &c : s) { //不传引用的话c值不可改
        if (isupper(c)) {
            c = tolower(c);
        }
    }
    return s;
}

//6.21
int my_compare_int(const int i1,const int *i2) {
    // if (i1 < *i2) {
    //     return *i2;
    // }
    // return i1;

    return (i1 > *i2) ? i1 : *i2; //三元运算符 看上去更清晰
}

//6.22
//1. 以值传递的方式使用指针 所有改变仅限于函数内部 函数执行完毕后指针的值和所指的内容都不改变
//2. 以值传递的方式使用指针 在函数内部通过解引用的方式直接访问内存并修改了指针所指的内容
//3. string * & 引用一个string指针
void swap_ptr_1(const string *p1, const string *p2) {
    string tmp = *p1, *p = &tmp;
    p1 = p2;
    p2 = p;
    cout << "inside func s1" << " " << p1 << " " << *p1 << endl;
    cout << "inside func s2" << " " << p2 << " " << *p2 << endl;
}

void swap_ptr_2(string *p1, string *p2) {
    string tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    cout << "inside func s1" << " " << p1 << " " << *p1 << endl;
    cout << "inside func s2" << " " << p2 << " " << *p2 << endl;
}

void swap_ptr_3(string *&p1, string *&p2) {
    string *tmp = p1;
    p1 = p2;
    p2 = tmp;
    cout << "inside func s1" << " " << p1 << " " << *p1 << endl;
    cout << "inside func s2" << " " << p2 << " " << *p2 << endl;
}

//6.23
void print_arr10(const int (&arr)[10]) { //用指针的话就拿不到arr的类型 auto没法写
    for (auto elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

void print_be(const int *begin, const int *end) { //传引用的话auto型具体是什么并不知道 省力传指针
    for (auto q = begin ;q != end;++q) {
        cout << *q << " ";
    }
    cout << endl;
}

//6.27
int sum_argv(initializer_list<int> il) {
    int s;
    for (auto elem : il) {
        s += elem;
    }
    return s;
}

//6.32
int& get(int *arry, int index) { //实际上int *arry指向arry数组的首元素 可通过编译
    return arry[index];
}

//6.33
void print_ivec(const vector<int> &ivec,const unsigned &index) {
    unsigned sz = ivec.size();
    if (!ivec.empty() && index <= sz) {
        cout << ivec[index] << endl;
        print_ivec(ivec,index + 1);
    }
}

//6.36
string (*func(string s))[10];

auto func() -> string(&)[10];

typedef string sarry1[10];
sarry1 &func();

using sarry2 = string[10];
sarry2 &func2();

string s[10];
decltype(s) &func3() { //
    return s;
}

//6.39
void calc(int i1,int i2) {
    i1 = 10;
    i2 = 20;
}
// void calc(const int i1,const int i2) { //函数重载失败
//     i1 = 10;
//     i2 = 20;
// }

//6.54
using my_func_type = int(*)(int i1, int i2);
vector<my_func_type> my_vec;

//6.55
int my_add(int i1,int i2) {
    return i1 + i2;
}
int my_minus(int i1,int i2) {
    return i1 - i2;
}
int my_mul(int i1,int i2) {
    return i1 * i2;
}
int my_div(int i1,int i2) {
    return i1 / i2;
}

//6.56
void my_compute(int a, int b, my_func_type func) {
    cout << func(a,b) << endl;
}

int main(int argc, char const *argv[]) //argc 参数个数 *argv[] 参数
{
    //6.4
    // try {
    //     int fact_5 = fact(5);
    //     cout << fact_5 << endl;
    // }
    // catch (runtime_error err) {
    //     cout << "run time error" << endl;
    //     cout << err.what() << endl;
    //     return -1;
    // }

    //6.5
    // cout << my_abs(-3.14) << endl;

    //6.7
    // cout << call_cnt() << endl;
    // cout << call_cnt() << endl;

    //6.10
    // int i1=3,i2=5;
    // change_val(i1,i2);
    // cout << i1 << " " << i2 << endl;

    //6.17
    // cout << contain_upper("roses are RED") << endl;
    // cout << contain_upper("violets are blue") << endl;

    // string s1 = "roses are RED";
    // string s2 = "violets are blue";
    // cout << my_to_lower(s1) << endl;
    // cout << my_to_lower(s2) << endl;

    //6.21
    // int i1= 3;
    // int i2 = 5, *p2 = &i2;
    // cout << my_compare_int(i1,p2) << endl;

    //6.22
    // string s1 = "roses are red", *p1 = &s1;
    // string s2 = "violets are blue", *p2 = &s2;
    // cout << "main before s1" << " " << s1 << " " << p1 << " " << *p1 << endl;
    // cout << "main brefore s2" << " " << s2 << " " << p2 << " " << *p2 << endl;
    // swap_ptr_1(p1,p2);
    // // swap_ptr_2(p1,p2);
    // // swap_ptr_3(p1,p2);
    // cout << "main after s1" << " " << s1 << " " << p1 << " " << *p1 << endl;
    // cout << "main after s2" << " " << s2 << " " << p2 << " " << *p2 << endl;

    //6.23
    // int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    // print_arr10(arr);
    // // print_arr10({0,1});
    // int arr2[2] = {0,1};
    // print_arr10_p(arr);
    // print_arr10(arr2);
    // auto b = begin(arr);
    // auto e = end(arr);
    // print_be(b,e);

    //6.25
    /* 
    debug
    launch.json
    "args": [
                "hello",
                "world"
            ],
    */
    // string s1 = argv[1];  //从下标1开始使用用户输入的参数
    // string s2 = argv[2];

    //6.27
    // int result = sum_argv({0,1,2,3,4,5});
    // cout << result << endl;

    //6.32
    // int arry[] = {0,1,2,3};
    // for (auto i : arry) {
    //     int tmp = get(arry,i);
    //     cout << tmp << " ";
    // }
    // cout << endl;

    //6.33
    // vector<int> ivec = {0,1,2,3,4,5};
    // print_ivec(ivec,1);

    //6.39
    // int a=0,b=0;
    // calc(a,b);
    // cout << a << b << endl;

    //6.55

    // vector<my_func_type> my_func = {my_add,my_minus,my_mul,my_div};

    // //6.56
    // int i=5,j=3;
    // for (auto func : my_func) {
    //     my_compute(i,j,func);
    // }


   return 0;
}