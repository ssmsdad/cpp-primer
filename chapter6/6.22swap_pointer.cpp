#include<iostream>

using namespace std;

void swap_pointer(int *&p, int *&q){
    int *temp = p;
    p = q;
    q = temp;
}

int main(){
    int a = 10, b = 20;
    int *p = &a, *q = &b;
    cout<<"a = "<<*p<<", b = "<<*q<<endl;
    cout<<"p = "<<p<<", q = "<<q<<endl;
    swap_pointer(p, q);
    cout<<"a = "<<*p<<", b = "<<*q<<endl;
    cout<<"p = "<<p<<", q = "<<q<<endl;
}