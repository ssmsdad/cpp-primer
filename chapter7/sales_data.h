
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<iostream>
#include <string>

class sales_data
{
    private:
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    public: 
        sales_data()=default;
        //简单写法
        // sales_data(const std::string &s):bookNo(s){};
        // sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){};
        // sales_data(std::istream &is){read(is,*this);};
        sales_data(const std::string &s);
        sales_data(const std::string &s,unsigned n,double p);
        sales_data(std::istream &is);
        std::string isbn() const { return this->bookNo; }
        sales_data &combine(const sales_data&);
        sales_data add(const sales_data&,const sales_data&);
        std::istream &read(std::istream&,sales_data&);
        std::ostream &print(std::ostream&,const sales_data&);
};

//与上边的简洁写法等价
sales_data::sales_data(const std::string &s){
    bookNo = s;
}

sales_data::sales_data(const std::string &s,unsigned n,double p){
    bookNo = s;
    units_sold = n;
    revenue = p*n;
}

sales_data::sales_data(std::istream &is){
    read(is,*this);
}

sales_data sales_data::add(const sales_data& lhs,const sales_data& rhs){
    sales_data sum(lhs);
    sum.combine(rhs);
    return sum;
}

std::istream &sales_data::read(std::istream &is,sales_data &item){
    is>>item.bookNo>>item.units_sold>>item.revenue;
    return is;
}

std::ostream &sales_data::print(std::ostream &os,const sales_data &item){
    os<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue;
    return os;
}

sales_data& sales_data::combine(const sales_data& rhs)
{
    units_sold +=rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
#endif