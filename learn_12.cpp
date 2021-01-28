#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include "str_blob_ptr.cpp"
using namespace std;


//12.6
vector<int>* new_vector_int_1() {
    vector<int>* p = new (nothrow) vector<int>();
    return p;
}

vector<int>* save_to_new_ivec(vector<int>* ivec)
{
    int i = 0;
    while (cin >> i) {
        ivec->push_back(i);
    }
    return ivec;
}

void print_new_ivec(const vector<int>* ivec) {
    for (auto it = ivec->cbegin(); it != ivec->cend() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

//12.7
shared_ptr<vector<int>> new_vector_int() {
    auto sptr = make_shared<vector<int>>() ;
    return sptr;
}

shared_ptr<vector<int>> save_to_new_ivec(shared_ptr<vector<int>>& ivec)
{
    int i = 0;
    while (cin >> i) {
        ivec->push_back(i);
    }
    return ivec;
}

void print_new_ivec(const shared_ptr<vector<int>>& ivec) {
    for (auto it = ivec->cbegin(); it != ivec->cend() ; ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

//12.20
void read_and_print(const string& file) {
    ifstream fin(file);
    string line;
    Str_blob sb;
    while (fin >> line) {
        sb.push_back(line);
    }
    auto b = sb.begin();
    auto e = sb.end();
    for (auto it=b; neq(it,e); it.incr()) {
        cout << *it << " ";
    }
    cout << endl;

}

//12.23
void add_char(const char& c1, const char& c2) {
    unique_ptr<char[]> up(new char[2]{c1,c2});
    for (size_t i=0; i !=2; ++i) {
        cout << up[i];
    }
    cout << endl;
}

void add_string(const string& s1, const string& s2) {
    unique_ptr<string[]> up(new string[2]{s1,s2});
    for (size_t i=0; i != 2; ++i) {
        cout << up[i] << " ";
    }
    cout << endl;
}

//12.24
void save_char_in_20(const string& file) {
    ifstream fin(file);
    char c;
    char* cc = new char[20];
    int l = 0;
    while (fin.get(c)) {
        if (isspace(c)) {
            cout << "break at space" << endl;
            break;
        }
        cc[l++] = c;
        if (l == 20) {
            cout << "up to limits 20" << endl;
            break;
        }
    }
    cout << "first 20: " << endl;
    // for (size_t i=0; i != 20; ++i) {
    //     cout << cc[i];
    // }
    for (auto it=cc; it != (cc+20); ++it) {
        cout << (*it);
    }
    cout << endl;

    delete[] cc;
    
}

//12.26
void save_char_using_alloc(const string& file, const int& sz) {
    ifstream fin(file);
    char c;
    // char* cc = new char[20];
    allocator<char> a;
    auto const p = a.allocate(sz);
    auto q = p; //q指向最后构造的元素之后的位置 这里指首元素的位置
    int l = 0;
    while (fin.get(c) && q != p+sz) {
        // if (isspace(c)) {
        //     cout << "break at space" << endl;
        //     break;
        // }
        // cc[l++] = c;
        a.construct(q++,c);
        if (l == sz) {
            cout << "up to limits 20" << endl;
            break;
        }
    }
    cout << "first " << sz << ": " << endl;
    // for (size_t i=0; i != 20; ++i) {
    //     cout << cc[i];
    // }
    for (auto it=p; it != (p+sz); ++it) {
        cout << (*it);
    }
    cout << endl;

    while (q != p) {
        a.destroy(--q);
    }
    a.deallocate(p,sz);
    
}



int main()
{
    //12.6
    // auto p = new_vector_int_1();
    // p = save_to_new_ivec(p);
    // print_new_ivec(p);
    // delete p;
    // p = nullptr;

    //12.7
    // auto p = new_vector_int();
    // p = save_to_new_ivec(p);
    // print_new_ivec(p);

    //12.20
    // string file("data.txt");
    // read_and_print(file);

    //12.23
    // char c1('h'), c2('i');
    // add_char(c1,c2);

    // string s1("jazz");
    // string s2("hiphop");
    // add_string(s1,s2);

    //12.24
    // string file("data.txt");
    // save_char_in_20(file);

    //12.26
    // string file("data.txt");
    // save_char_using_alloc(file,50);

   
    return 0;
    
}


