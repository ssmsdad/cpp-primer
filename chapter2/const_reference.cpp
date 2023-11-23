#include<iostream>

int main(){
    int i=42;
    const int &r1=i;
    const int &r2=42;
    std::cout<<r2<<std::endl;       //42
    const int &r3=r1*2;
    std::cout<<i<<"  "<<r3<<std::endl;      //42    84
    const int &r4=i;
    i=55;
    std::cout<<r4<<std::endl;
    // int &r5=r1;      r5是非常量引用，无法等于常量引用，如果可以，则可以根据r5来修改r1的值
}