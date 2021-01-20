#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
// using namespace std::placeholders;
#include <numeric>
#include <iterator>
#include "csales_data"
#include <map>
#include <unordered_map>
#include <string>
#include <set>
// #include <regex>

//11.3
void count_word(string file) {
    ifstream fstrm(file);
    map<string,size_t> word_count;
    // istream_iterator<string> in_iter(fstrm),eof;
    // while (in_iter != eof) {
    //     ++word_count[*in_iter];
    // }
    // ostream_iterator<map> out_iter(cout," ");
    // copy(word_count.cbegin(),word_count.cend(),out_iter);
    string s;
    while (fstrm >> s) {
        ++word_count[s];
    }
    for (const auto& w : word_count) {
        cout << w.first << " " << w.second << endl;
    }

}

//11.4
string& trans(string& s) {
    // for (size_t i=0; i != s.size(); ++i) { // condition i != s.size()会catch error 改成 < 可以 but why?
    //     try {
    //         if (isupper(s[i])) {
    //             // s[i] = s[i] - 'A' + 'a';
    //             s[i] += 32;
    //         }
    //         if (s[i] == '.' || s[i] == ',') {
    //             cout << "ready to erase pos " << i << " with value " << s[i] << endl;
    //             // s.erase(s.begin()+i,s.begin()+i+1); //s.erase(b,e)
    //             s.erase(i,1); //s.erase(pos,n)
    //             }
    //     }
    //     catch (exception err) {
    //         cout << err.what() << endl;
    //     }
    // }
    // for (string::iterator it = s.begin(); it != s.end(); ++it) { // 同样condition it != s.end()会catch error 改成 < 可以 but why?
    //     try {
    //         if (isupper(*it)) {
    //             // s[i] = s[i] - 'A' + 'a';
    //             *it += 32;
    //         }
    //         if ((*it) == '.' || (*it) == ',') {
    //             s.erase(it,++it);
    //         }
    //     }
    //     catch (exception err) {
    //         cout << err.what() << endl;
    //     }
    // }
    // string::iterator it = s.begin();
    // while (it != s.end()) { // 同样condition it != s.end()会catch error 改成 < 可以 but why?
    //     try {
    //         if (isupper(*it)) {
    //             // s[i] = s[i] - 'A' + 'a';
    //             *it += 32;
    //         }
    //         if ((*it) == '.' || (*it) == ',') {
    //             s.erase(it,++it);
    //         }
    //     }
    //     catch (exception err) {
    //         cout << err.what() << endl;
    //     }
    //     ++it;
    // }
    for (auto& c : s) {
        if (isupper(c)) {
            c = c + 32;
        }
    }
    // auto true_end = remove_if(s.begin(),s.end(),ispunct); //pred如果是ispunct有重载二义性 用lambda包装一下
    auto true_end = remove_if(s.begin(),s.end(),[](const char& c) -> bool {return ispunct(c);});
    // s.erase(true_end,s.end());

    s.erase(find_if(s.begin(),s.end(),[](const char& c) -> bool {return ispunct(c);})); //假设一个单词只会出现一次标点
    return s;
}

void count_word_2(string file) {
    ifstream fstrm(file);
    map<string,size_t> word_count;
    string s;
    while (fstrm >> s) {
        s = trans(s);
        ++word_count[s];
    }
    for (const auto& w : word_count) {
        cout << w.first << " " << w.second << endl;
    }

}

//11.7
void add_child(map<string,vector<string>>& family,const string& family_name, const string& child_name) {
    if ( family.cbegin() != family.cend()) {
        family[family_name];
    }
    family[family_name].push_back(child_name);
}

void add_child(map<string,vector<string>>& family,const string& family_name, const vector<string>& childs_name) {
    if ( family.cbegin() != family.cend()) {
        family[family_name];
    }
    for (auto child_name : childs_name) {
        family[family_name].push_back(child_name);
    }
}

void show_family(const map<string,vector<string>>& family) {
    for (const auto& f : family) {
        cout << "family " << f.first << " has child: ";
        for (const auto& child : f.second) {
            cout << child << " ";
        }
        cout << endl;
    }
}

//11.8
void save_unique_word(vector<string>& words,const string& word) {
    auto first_qualified = find(words.cbegin(),words.cend(),word);
    if ( first_qualified != words.cend()) {
        words.push_back(word);
    }
}

void save_unique_word(const vector<string>& words,vector<string>& dest) {
    for (const auto& word : words) {
        auto first_qualified = find(dest.cbegin(),dest.cend(),word);
        if ( first_qualified == dest.cend()) {
            dest.push_back(word);
        }
    }
}

void show_word(const vector<string>& words) {
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;
}

void save_unique_word_set(const vector<string>& words,set<string>& dest) {
    for (const auto& word : words) {
        dest.insert(word);
    }
}

void show_word(const set<string>& words) {
    for (const auto& w : words) {
        cout << w << " ";
    }
    cout << endl;
}

//11.9
void save_word_with_line_num(const string& file,map<string,int>& words){
    ifstream fin(file);
    string line;
    if (!fin) {
        cout << "no data?" << endl;
    }
    while (getline(fin,line)) {
        string word;
        istringstream sin(line);
        int line_num;
        while (sin >> word) {
            words[word] = line_num; //重复单词会覆盖行号
        }
        ++line_num;
    }
}

void show_word(const map<string,int>& words) {
    for (const auto& w : words) {
        cout << w.first << " " << w.second << endl;
    }
}

//11.11
bool my_compare_isbn(const Sales_data& book1, const Sales_data& book2) {
    return book1.isbn() < book2.isbn();
}

//11.12
vector<pair<string,int>> my_bind(const vector<string>& svec, const vector<int>& ivec) {
    vector<pair<string,int>> pvec;
    for (size_t i = 0; i < svec.size(); ++i ) {
        pvec.push_back({svec[i],ivec[i]});
    }
    return pvec;
}

void show_elem(const vector<pair<string,int>>& pvec) {
    for (auto p : pvec) {
        cout << p.first << " " << p.second << endl;
    }
}

//11.13
vector<pair<string,int>> my_bind_2(const vector<string>& svec, const vector<int>& ivec) {
    vector<pair<string,int>> pvec;
    for (size_t i = 0; i < svec.size(); ++i ) {
        // pvec.push_back({svec[i],ivec[i]});
        pvec.push_back(make_pair(svec[i],ivec[i]));
        // pair<string,int> p(svec[i],ivec[i]);
        // pvec.push_back(p);
    }
    return pvec;
}

//11.14
void add_child_2(map<string,vector<pair<string,string>>>& family,const string& family_name, const vector<pair<string,string>>& childs_info) {
    if ( family.cbegin() != family.cend()) {
        family[family_name];
    }
    for (auto child : childs_info) {
        family[family_name].push_back({child.first,child.second});
    }
}

void show_family(const map<string,vector<pair<string,string>>>& family) {
    for (const auto& f : family) {
        cout << "family " << f.first << " has child: " << endl;
        for (const auto& child_info : f.second) {
            cout << child_info.first << " " << child_info.second << endl;
        }
        cout << endl;
    }
}

//11.20
void count_word_insert(string file) {
    ifstream fstrm(file);
    map<string,size_t> word_count;
    string s;
    while (fstrm >> s) {
        // ++word_count[s];
        s = trans(s);
        auto ret = word_count.insert({s,1});
        if (!ret.second) {
            ++ret.first->second;
        } 
    }
    for (const auto& w : word_count) {
        cout << w.first << " " << w.second << endl;
    }

}

//11.23
void add_child_3(multimap<string,vector<pair<string,string>>>& family,const string& family_name, const vector<pair<string,string>>& childs_info) {
    
    for (auto child : childs_info) {
        vector<pair<string,string>> myvec;
        pair<string,string> p{child.first,child.second};
        myvec.push_back(p);
        family.insert({family_name,myvec});
    }
}

void show_family(const multimap<string,vector<pair<string,string>>>& family) {
    for (const auto& f : family) {
        cout << "family " << f.first << " has child: " << endl;
        for (const auto& child_info : f.second) {
            cout << child_info.first << " " << child_info.second << endl;
        }
        cout << endl;
    }
}

//11.33
map<string,string> build_map(const string& map_file) {
    ifstream fin(map_file);
    string key,value;
    map<string,string> m;
    while (fin >> key && getline(fin,value)) {
        if (value.size() > 1) {
            m[key] = value.substr(1); //注意下标操作和insert操作的不同 key相同的情况下value值是不同的
        }
        else
        {
            throw runtime_error("no trans rule, check");
        }
    }
    return m;
}

const string& transform(const string& s, const map<string,string>& m) {
    auto first_qualified = m.find(s);
    if (first_qualified != m.end()) {
        return first_qualified->second;
    }
    else {
        return s;
    }
}

void word_transform(const string& map_file, const string& read_file) {
    auto word_map = build_map(map_file);
    string text;
    ifstream fin(read_file);
    while (getline(fin,text)) {
        istringstream sin(text);
        string word;
        while (sin >> word) {
            cout << transform(word,word_map) << " ";
        }
        cout << endl;
    }
}

//11.38
void count_word_3(string file) {
    ifstream fstrm(file);
    unordered_map<string,size_t> word_count;
    // istream_iterator<string> in_iter(fstrm),eof;
    // while (in_iter != eof) {
    //     ++word_count[*in_iter];
    // }
    // ostream_iterator<map> out_iter(cout," ");
    // copy(word_count.cbegin(),word_count.cend(),out_iter);
    string s;
    while (fstrm >> s) {
        s = trans(s);
        ++word_count[s];
    }
    for (const auto& w : word_count) {
        cout << w.first << " " << w.second << endl;
    }

}

unordered_map<string,string> build_uomap(const string& map_file) {
    ifstream fin(map_file);
    string key,value;
    unordered_map<string,string> m;
    while (fin >> key && getline(fin,value)) {
        if (value.size() > 1) {
            m[key] = value.substr(1); //注意下标操作和insert操作的不同 key相同的情况下value值是不同的
        }
        else
        {
            throw runtime_error("no trans rule, check");
        }
    }
    return m;
}

const string& transform(const string& s, const unordered_map<string,string>& m) {
    auto first_qualified = m.find(s);
    if (first_qualified != m.end()) {
        return first_qualified->second;
    }
    else {
        return s;
    }
}

void word_transform_2(const string& map_file, const string& read_file) {
    auto word_map = build_map(map_file);
    string text;
    ifstream fin(read_file);
    while (getline(fin,text)) {
        istringstream sin(text);
        string word;
        while (sin >> word) {
            cout << transform(word,word_map) << " ";
        }
        cout << endl;
    }
}

int main()
{
    // 11.4
    // string file("data.txt");
    // count_word_2(file);

    // string s = "Roses.";
    // auto b = s.begin()+5;
    // auto e = b+1; // e = ++b 不行
    // s.erase(b,e);
    // cout << "after exec s.erase(b,e) s.size() = " << s.size() << endl;
    // cout << s << endl;
    // s.erase(s.begin()+5,++(s.begin()+5));
    // cout << "after exec s.erase(s.begin()+5,++(s.begin()+5))  s.size() = " << s.size() << endl;
    // // s.erase(5,1);
    // cout << s << endl;

    // cout << (0 - 'A' + 'a') << endl;

    //11.7
    // map<string,vector<string>> family;
    // family["woof"] = {"big j","large j","little j"};
    // show_family(family);
    // add_child(family,"woof","extra large j");
    // add_child(family,"deer",vector<string>{"cute c","super cute c"});
    // show_family(family);

    //11.8
    // vector<string> words{"save","unique","words","unique"};
    // vector<string> unique_words;
    // save_unique_word(words,unique_words);
    // show_word(words);
    // show_word(unique_words);

    // set<string> unique_words_set;
    // save_unique_word_set(words,unique_words_set);
    // show_word(unique_words_set);

    //11.9
    // string file("data.txt");
    // map<string,int> words;
    // save_word_with_line_num(file,words);
    // show_word(words);

    //11.10
    // map<vector<int>::iterator,int> m1;
    // map<list<int>::iterator,int> m2;
    // vector<int> ivec{1,2,3};
    // list<int> il{1,2,3};

    // m1[ivec.cbegin()] = ivec.front();
    // m2[il.cbegin()] = il.front();

    //11.11
    // multiset<Sales_data,decltype(my_compare_isbn)*> bookstore1(my_compare_isbn);
    // using my_comp = bool (*)(const Sales_data&, const Sales_data&);
    // multiset<Sales_data,my_comp> bookstore(my_comp);

    //11.12
    // vector<string> svec{"no","love","fang"};
    // vector<int> ivec{1,2,3};
    // vector<pair<string,int>> pvec;

    // pvec = my_bind(svec,ivec);
    // show_elem(pvec);

    //11.13
    // vector<string> svec{"no","love","fang"};
    // vector<int> ivec{1,2,3};
    // vector<pair<string,int>> pvec;

    // pvec = my_bind_2(svec,ivec);
    // show_elem(pvec);

    //11.14
    // map<string,vector<pair<string,string>>> family;
    // family["woof"] = {{"big j","2020-01-01"},{"large j","2021-02-01"},{"little j","2022-03-01"}};
    // show_family(family);
    // add_child_2(family,"woof",{{"extra large j","2023-04-01"}});
    // add_child_2(family,"deer",{{"cute c","2020-01-01"},{"super cute c","2021-02-01"}});
    // show_family(family);

    //p382
    // map<string,int> m1;
    // m1["fang"] = 22;
    // // m1["no love"] = 2016;
    // auto begin = m1.begin();
    // cout << (begin->first) << endl;
    // cout << (++(begin->second)) << endl;
    // cout << (begin->second) << endl;

    //11.16
    // map<string,int> m1;
    // m1["empty"];
    // auto it = m1.begin();
    // // (*it).second = 42;
    // it->second = 42;
    // cout << it->first << " " << it->second << endl;

    //11.18
    // map<string,int> m1;
    // m1["first"] = 42;
    // map<string,int>::iterator it = m1.begin();
    // cout << it->first << " " << it->second << endl;

    //11.19
    // using my_comp = bool (*) (const Sales_data&, const Sales_data&);
    // using it = multiset<Sales_data, my_comp>::iterator;
    // multiset<Sales_data, my_comp> bookstore(my_compare_isbn);
    // auto b1 = bookstore.begin();
    // it b = bookstore.begin();

    //11.20
    // string file("data.txt");
    // count_word_insert(file);

    //11.23
    // multimap<string,vector<pair<string,string>>> family;
    // family.insert({"woof",{{"big j","2020-01-01"},{"large j","2021-02-01"},{"little j","2022-03-01"}}});
    // show_family(family);
    // add_child_3(family,"woof",{{"extra large j","2023-04-01"}});
    // add_child_3(family,"deer",{{"cute c","2020-01-01"},{"super cute c","2021-02-01"}});
    // show_family(family);

    //11.28
    // map<string,vector<int>> m1;
    // auto first_qialified = m1.find("fang");
    // if (first_qialified == m1.end()) {
    //     cout << "key not in map" << endl;
    // }

    //11.31
    // multimap<string,vector<string>> authors;
    // auto first_qualified = authors.find("fang");
    // if (first_qualified != authors.end()) {
    //     authors.erase(authors.equal_range("fang").first,authors.equal_range("fang").second);
    // }
    // else
    // {
    //     cout << "key not in multimap" << endl;
    // }
    
    //11.33
    // string rule_file("rules.txt");
    // string text_file("text.txt");
    // word_transform(rule_file,text_file);

    //11.38
    // string file("data.txt");
    // count_word_3(file);

    // string rule_file("rules.txt");
    // string text_file("text.txt");
    // word_transform_2(rule_file,text_file);


    return 0;
    
}


