#ifndef BULK_QUOTE
#define BULK_QUOTE
// #include "quote.h"
#include "disc_quote.h"

class Bulk_quote : public Disc_quote {
    public:
        Bulk_quote() = default;
        // Bulk_quote(const std::string& s,const double& dd=0.0,const std::size_t& n=0,const double& dis=0.0) //默认值必须放最后 所以当中一个有默认值其后所有的参数都得有默认值
        // : Disc_quote(s,dd,n,dis) {}
        using Disc_quote::Disc_quote;
        double net_price(const size_t&) const override; //基类是const 子类也得是const
        std::string get_name() const override {return "class bulk quote";};
        Bulk_quote* clone() const & override {return new Bulk_quote(*this);}
        Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this));}
};

double Bulk_quote::net_price(const size_t& n) const {
    if (n >= quantity) {
        return n * (1-discount) * price; //超过一定数量 有折扣
    }
    else
    {
        return n * price;
    }
}


#endif