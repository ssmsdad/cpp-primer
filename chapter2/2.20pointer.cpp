#include<iostream>

int main(){
    int ival=42;
    int *p=&ival;   //p中存放着变量ival的地址，使用符号*得到指针p所指向的对象
    int *k=p;
    std::cout<<p<<"     "<<k<<std::endl;    //结果为地址
    std::cout<<*p<<"     "<<*k<<std::endl;  //结果为42
    *k=15;
    std::cout<<ival<<std::endl;     //结果均为0
    int &r2=*k;
    std::cout<<r2<<std::endl;       //结果为15
    int *j;
    j=&ival;
    std::cout<<j<<std::endl;        //同int *p=&ival

    //2.20
    int i=42;
    int *pl=&i;
    *pl=*pl**pl;
    std::cout<<*pl<<std::endl;

    //2.24
    int a=50;
    int *p1=&a;
    //double *p2=&a;    int类型的指针不能赋值给double类型的指针


}