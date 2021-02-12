#ifndef QUOTE
#define QUOTE

#include <iostream>

class Quote {
    public:
        Quote() = default;
        Quote(const std::string& s,const double& dd=0.0)
        : book_number(s), price(dd) {}
        Quote(const Quote&) = default;
        Quote& operator = (const Quote&) = default;
        virtual double net_price(const size_t& n) const {return n * price;}; //无折扣
        virtual ~Quote() = default;
        virtual std::string get_name() const {return "class quote";};
        const std::string& isbn() const {return book_number;}
        //clone还得考虑左值右值引用的重载版本
        virtual Quote* clone() const & {return new Quote(*this);}
        virtual Quote* clone() && {return new Quote(std::move(*this));}
    protected:
        double price;
    private:    
        std::string book_number;
};

double print_total(std::ostream& os, const Quote& item, const size_t& n) {
    //由于是常值引用 net_price虚函数调用会动态绑定到调用的类
    double ret = item.net_price(n);
    os << item.get_name() << " " << item.isbn() << " # sold " << n << " total due: " << ret << std::endl;
    return ret;
}

#endif
