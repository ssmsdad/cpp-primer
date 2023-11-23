#include<iostream>

int main(){
    typedef double base,*p;
    base l=3.15;
    p pi=&l;
    std::cout<<l<<" "<<*pi<<std::endl;

    
}