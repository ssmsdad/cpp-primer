

#include<iostream>
#include "quote.cpp"

class Bulk_Quote : public Quote {
    public:
        Bulk_Quote() = default;
        Bulk_Quote(const std::string &book, double sales_price, std::size_t qty, double disc):
            Quote(book, sales_price), min_qty(qty), discount(disc){}
        double net_price(std::size_t n) const override ;
    private:
        std::size_t min_qty = 0;
        double discount = 0.0;
};

double Bulk_Quote::net_price(std::size_t n) const {
    if (n >= min_qty)
        return n * (1 - discount) * price;
    else
        return n * price;
}

double print_total(std::ostream &os, const Quote &item, std::size_t n){
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}


int main(){
    Quote q("0-201-78345-X", 23.8);
    Bulk_Quote bq("0-201-78345-X", 23.8, 5, 0.2);
    print_total(std::cout, q, 6);
    print_total(std::cout, bq, 6);
    return 0;
}