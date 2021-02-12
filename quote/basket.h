#ifndef BASKET
#define BASKET

#include "quote.h"
#include <set>

class Basket {
    public:
        //出于用户使用习惯 add_item需要参数是Quote对象 因此要写重载函数 并处理动态内存
        void add_item(const std::shared_ptr<Quote>& item) {
            items.insert(item);
        }
        void add_item(const Quote&);
        void add_item(Quote&&);
        double total_receipt(std::ostream&) const;
    private:
        static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
            return lhs->isbn() < rhs->isbn();
        }
        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items{compare};
};

void Basket::add_item(const Quote& quote) {
    //但是new一个什么类对象呢 不如把new放在类的虚函数里吧 每个对象自己new
    std::shared_ptr<Quote> p(quote.clone());
    items.insert(p);
}

void Basket::add_item(Quote&& quote) {
    //形参右值引用 还是要用到std::move
    std::shared_ptr<Quote> p(std::move(quote).clone());
    items.insert(p);
}

double Basket::total_receipt(std::ostream& out) const {
    double total = 0;
    //每次处理同标题的书
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        total += print_total(out,**iter,items.count(*iter));
    }
    out << "total sale: " << total << std::endl;
    return total;
}

#endif