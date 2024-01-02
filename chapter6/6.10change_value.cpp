#include<iostream>

using namespace std;

//使用指针形参或者引用形参可以直接改变实参的值，所以无需return任何值
void change_point(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void change_reference(int &p, int &q){
    int temp = p;
    p = q;
    q = temp;
}

void you(const int a, const int b){
    cout<<'666'<<endl;
}

int main(){
    int a = 10, b = 20;
    //非常量实参可以绑定到const引用上
    you(a, b);
    cout<<"a = "<<a<<", b = "<<b<<endl;
    change_point(&a, &b);
    change_reference(a, b);
    cout<<"a = "<<a<<", b = "<<b<<endl;

}

