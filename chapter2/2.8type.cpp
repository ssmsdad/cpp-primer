#include<iostream>

int p1(){
    int i;
    // 仲哥，定义在函数体内部的内置类型的变量不会被初始化，为什么i的值是0
    std::cout<<i<<std::endl;
    return 0;
}

int _;

int main(){
    std::cout<<"2"<<"\115\n";
    std::cout<<"2"<<"\t\115\n";
    int i=(3.14);
    // extern int i;
    // int i={3.14};    编译会报错,精度损失
    std::cout<<i<<std::endl;
    //std::cin>>int a;  错的
    // double a=b=9.99;    两个变量的初始化不允许在同一行
    p1();
    int _;
    double Doubel=3.14;
    std::cout<<Doubel<<std::endl;
    // int 1_or_2=1;    错误
    int a;
    int b=1;
    std::cout<<a+b<<std::endl;
    return 0;
}

