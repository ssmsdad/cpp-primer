#include<iostream>

using namespace std;

//使用指针形参或者引用形参可以直接改变实参的值，所以无需return任何值
void change(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main(){
    int a = 10, b = 20;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    change(&a, &b);
    cout<<"a = "<<a<<", b = "<<b<<endl;
    return 0;
}