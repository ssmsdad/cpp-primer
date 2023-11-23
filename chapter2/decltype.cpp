#include<iostream>
#include <typeinfo>

int main(){
    const int ci=0,&cj=ci;
    decltype(ci) x=0;   //const int
    decltype(cj) y=x;   //const int&
    // decltype(cj) z;  //const int&,需要初始化

    std::cout<<&ci<<std::endl;
    std::cout<<(ci)<<std::endl;


    unsigned f = 42;
    std::cout << "Variable type: " << typeid(f).name() << std::endl;    //j是什么类型
    return 0;

}