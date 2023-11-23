#include<iostream>

int reused=42;
int main(){
    int i=100,sum=0;
    for(i=0;i!=10;++i){
        sum+=i;
    }
    std::cout<<i<<"  "<<sum<<std::endl;

    int unique=0;
    std::cout<<reused<<"  "<<unique<<std::endl;
    int reused=0;
    std::cout<<reused<<"  "<<unique<<std::endl;
    //::使用全局作用域
    std::cout<<::reused<<"  "<<unique<<std::endl;
}