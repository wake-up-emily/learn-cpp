#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
// using namespace std::placeholders;
#include <numeric>
#include <iterator>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include "quote/quote.h"
#include "quote/bulk_quote.h"
#include "quote/limited_num_quote.h"
#include "quote/basket.h"
// #include "query_sptr/text_query_result_str_vec.cpp"
// #include "query_sptr/query.cpp"
// #include "query_sptr/and_query.cpp"
// #include "query_sptr/or_query.cpp"
#include "query_sptr/not_query.cpp"
// #include "query_diy_ptr/and_query.cpp"
// #include "query_diy_ptr/not_query.cpp"

// #include "query_ptr/and_query.cpp"
// #include "query_ptr/or_query.cpp"
// #include "query_ptr/not_query.cpp"
using namespace std;

//15.36
void run_query(const string& file) {
    ifstream fin(file);
    // vector<string> svec{"are","blue"};
    // for (auto s:svec) {
    //     cout << Query(s) << endl;
    // }
    
    // Query q = Query("are") & Query("blue");
    // cout << q << endl;
    /*
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    and_query构造+1
    Query构造+1
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    (are & blue)
    */

//    Query q = Query("are") & Query("blue") | Query("sky");
//    Query q = (Query("are") | Query("blue")) & Query("sky");
//    cout << q << endl;
   /*
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    or_query构造+1
    Query构造+1
    word_query构造+1
    binary_query构造+1
    and_query构造+1
    Query构造+1
    query rep
    binary_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    ((are | blue) & sky)
   */

//    Query q = Query("are") | Query("blue") & Query("sky");
//    cout << q << endl;
   /*
    word_query构造+1
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    and_query构造+1
    Query构造+1
    binary_query构造+1
    or_query构造+1
    Query构造+1
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    (are | (blue & sky)) //why...位运算符不是应该满足左结合律吗...
    */

    // Query q = Query("are") | Query("blue") & Query("sky") | Query("ops");
    // cout << q << endl;
    /*
    word_query构造+1
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    and_query构造+1
    Query构造+1
    binary_query构造+1
    or_query构造+1
    Query构造+1
    word_query构造+1 //甚至word_query构造也不是4个一起先构造的...
    binary_query构造+1
    or_query构造+1
    Query构造+1
    query rep
    binary_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    ((are | (blue & sky)) | ops) //omg...
    */

    // Query q = Query("are") | Query("blue") | Query("sky") & Query("ops");
    // cout << q << endl;
    /*
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    or_query构造+1
    Query构造+1
    word_query构造+1
    word_query构造+1
    binary_query构造+1
    and_query构造+1
    Query构造+1
    binary_query构造+1
    or_query构造+1
    Query构造+1
    query rep
    binary_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    query rep
    binary_query rep
    query rep
    words_query rep
    query rep
    words_query rep
    ((are | blue) | (sky & ops)) //明白了 编辑器有自己的想法
    */
    // Query q = Query("are") | Query("blue") | Query("sky") & Query("ops");
    // Query q = Query("are") & Query("blue");
    // Query q = Query("are") | Query("blue");
    // Query q = Query("are");
    Query q = ~ Query("are");
    Text_query_str_vec t(fin);
    print(cout,q.eval(t)) << endl; //因为之前的需求里vector比set更优解 所以当时更新成了vector 导致出的结果会有重复 先不修正了
}

//15.41
void run_15_41() {
    // Query q = Query("are") | Query("blue") | Query("sky") & Query("ops");
    // Query q = Query("are") & Query("blue");
    // Query q = Query("are") | Query("blue");
    // Query q = Query("are");
    string file("data.txt");
    ifstream fin(file);
    Query q = ~ Query("are");
    Text_query_str_vec t(fin);
    print(cout,q.eval(t)) << endl; //因为之前的需求里vector比set更优解 所以当时更新成了vector 导致出的结果会有重复 先不修正了
}

void run_15_42_2() {
    string file("data.txt");
    ifstream fin(file);
    Query q = ~ Query("are");
    Text_query_str_vec t(fin);
    print(cout,q.eval(t)) << endl;
    // t.history();
    Query q2 = Query("blue");
    print(cout,q2.eval(t)) << endl;
    t.history();
    print(cout,t.query(3)) << endl;
}

void run_some_test() {
    auto p =make_shared<vector<size_t>>();
    p->insert(p->begin(),2);
    cout << p->front() << endl;
}

int main()
{
    //15.3 - 15.7
    // // Quote item("million",20);
    // Bulk_quote dis_item("million",20,20,0.1);
    // Limited_num_quote lim_item("million",20,15,0.1);
    // // // print_total(cout,item,20);
    // print_total(cout,dis_item,20);
    // print_total(cout,lim_item,20);

    //15.29
    // vector<Quote> qvec;
    // qvec.push_back(Bulk_quote("million",20,20,0.1));
    // qvec.push_back(Bulk_quote("million",20,20,0.1));
    // qvec.push_back(Bulk_quote("million",20,20,0.1));
    // double total = 0;
    // for (auto quote:qvec) {
    //     double nprice = quote.net_price(20);
    //     total += nprice;
    // }
    // cout << total << endl;

    // vector<shared_ptr<Quote>> qvec;
    // double total = 0;
    // qvec.push_back(make_shared<Bulk_quote>("million",20,20,0.1));
    // qvec.push_back(make_shared<Bulk_quote>("million",20,20,0.1));
    // qvec.push_back(make_shared<Limited_num_quote>("million",20,20,0.1));
    // for (auto quote:qvec) {
    //     double nprice = quote->net_price(20);
    //     total += nprice;
    // }
    // cout << total << endl;

    //15.30
    // Basket items;
    // items.add_item(Bulk_quote("million",20,3,0.1));
    // items.add_item(Bulk_quote("million",20,3,0.1));
    // items.add_item(Bulk_quote("million",20,3,0.1));
    // items.add_item(Bulk_quote("million2",20,3,0.1));
    // items.total_receipt(cout);

    //15.36-15.39
    // run_query("data.txt");
    // run_some_test();

    //15.41
    // run_15_41();

    //15.42.2
    // run_15_42_2();


    return 0;
    
}


