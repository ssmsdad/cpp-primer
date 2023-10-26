#include<iostream>

using namespace std;

int main(){
    int a,b;
    cout << "请输入两个数" <<endl;
    cin>>a;
    cin>>b;
    while(a<b){
        cout<<a;
        a++;
    }
    return 0;
}