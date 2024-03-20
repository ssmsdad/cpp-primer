

#include<iostream>


class Sales_data {
    // +运算符最好定义为非成员函数，所以需要将其声明为友元，确保可以访问类的私有成员
    friend bool operator==(const Sales_data &, const Sales_data &);
    friend bool operator!=(const Sales_data &, const Sales_data &);
    friend Sales_data operator+(const Sales_data &, const Sales_data &);
    friend std::ostream &operator<<(std::ostream &, const Sales_data &);
    friend std::istream &operator>>(std::istream &, Sales_data &);
public:
    // 构造函数
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(std::istream &is) : Sales_data() {is >> *this;}
    Sales_data &operator+=(const Sales_data &);
    std::string isbn() const { return bookNo; }


private:
    double avg_price() const;
    // 书号
    std::string bookNo;
    // 卖出的册数
    unsigned units_sold = 0;
    // 销售收入
    double revenue = 0.0;

};

bool operator==(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs){
    return !(lhs == rhs);
}

double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}   

Sales_data &Sales_data::operator+=(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &item){
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

std::istream &operator>>(std::istream &is, Sales_data &item){
    double price=0;
    is >> item.bookNo >> item.units_sold >> price;
    if(is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}


int main()
{
    Sales_data item1("0-201-78345-X", 3, 20.00);
    Sales_data item2("0-201-78345-X", 2, 25.00);
    std::cout << item1 << std::endl;
    std::cout << item2 << std::endl;
    std::cout << item1 + item2 << std::endl;
    std::cout << (item1 += item2) << std::endl; // Explicitly call the overloaded operator+= function
    return 0;
}