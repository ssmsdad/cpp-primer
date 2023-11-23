#include<iostream>

int main(){
    //二级指针
    int ival=42;
    int *pi=&ival;
    int **ppi=&pi;
    std::cout<<"direct value:"<<ival<<"\n"      //42
            <<"indirect value:"<<*pi<<"\n"      //42
            <<"double indirect value:"<<*ppi<<std::endl;        //ival对象的内存地址,同pi的值

    //指针的引用
    int i=50;
    int *p;
    int *&r=p;
    r=&i;   //对r进行操作相当于对p进行操作
    std::cout<<*p<<std::endl;   //50
    *r=0;
    std::cout<<*p<<std::endl;   //0
    int *l=0;
}