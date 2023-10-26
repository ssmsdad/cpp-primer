#include<iostream>

int main(){
    int ival=2023;
    int &refVal=ival;
    // int &refVal1;    错误：引用必须初始化，refVal1未初始化
    //将2赋给refVal指向的对象，即ival
    refVal=2;
    std::cout<<ival<<std::endl;
    //与i1 = ival结果一样
    int i1=refVal;
    std::cout<<i1<<std::endl;
    // int &refVal2=10;    错误：引用类型的初始值必须是一个对象

    //2.16
    int i=0,&r1=i;
    double d=0,&r2=d;
    r2=3.1515926;
    r1=r2;
    std::cout<<i<<std::endl;

    //2.17
    int j,&ri=j;
    j=5,ri=10;
    std::cout<<j<<"   "<<ri<<std::endl;
}