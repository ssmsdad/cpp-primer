#include<iostream>

//constexpr,定义在函数体外部的变量地址固定不变，可以用来初始化constexpr对象的值
int j=0;
constexpr int i=42;
constexpr int *pi3=&j;
constexpr const int *pi4=&i;

int main(){
    const double pi=42;
    const double *ptr=&pi;
    std::cout<<*ptr<<std::endl;
    std::cout<<ptr<<std::endl;  //0x7ffef3cffce0,对象pi的内存地址
    double dval=50;
    ptr=&dval;  //这里ptr指针指向dval对象，来改变*ptr的值
    std::cout<<ptr<<std::endl;  //0x7ffef3cffce8,对象dval的内存地址
    std::cout<<*ptr<<std::endl; //50
    std::cout<<pi<<std::endl;   //42
    //指向常量的指针仅仅要求不能通过指针来改变该对象的值，但是没有规定那个对象的值不能通过其他路径来改变
    // ptr=60;      不能通过指针来改变该对象的值
    dval=60;    //对象dval的值通过其他路径来改变
    ptr=&dval;
    std::cout<<*ptr<<std::endl; //60

    //常量指针
    const double pi2=3.14;
    const double *const pip=&pi2;   //第一个const代表指向常量的指针
                                    //第二个const代表常量指针，此时pip所指的对象只能是pi2，不能改变
                                    //两个const加起来则代表pip所指对象与所指对象的值均不能改变
    //仲哥，constexpr p84   如果你认定变量..........??
}