#ifndef LIMITED_NUM_QUOTE
#define LIMITED_NUM_QUOTE
#include "quote.h"

class Limited_num_quote : public Quote {
    public:
        Limited_num_quote(const std::string& s,const double& dd=0.0,const std::size_t& n=0,const double& dis=0.0)
        : Quote(s,dd), max_amount(n), discount(dis) {}
        double net_price(const std::size_t&) const override;
        std::string get_name() const override {return "limited num quote";};
    private:
        size_t max_amount;
        double discount;
};

double Limited_num_quote::net_price(const std::size_t& n) const {
    if (n >= max_amount) {
        return max_amount * (1-discount) * price + (n-max_amount) * price;
    }
    else
    {
        return n * (1-discount) * price;
    }
}

#endif