#include<iostream>
#include "Chapter6.h"

int main(){
    int val;
    std::cout<<"Please input a number:"<<std::endl;
    std::cin>>val;
    std::cout<<val<<"! = "<<fact(val)<<std::endl;
    return 0;
}