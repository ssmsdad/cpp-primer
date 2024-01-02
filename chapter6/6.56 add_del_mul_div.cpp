#include<iostream>
#include<vector>

using namespace std;

int add(int a, int b){
    return a+b;
}

int sub(int a, int b){
    return a-b;
}

int mul(int a, int b){
    return a*b;
}

int divi(int a, int b){
    return a/b;
}

void compute(int a,int b,int (*p)(int,int)){
    cout<<p(a,b)<<endl;
}
int main(){
    int a=10,b=5;
    vector<decltype(add) *> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(divi);
    for(auto f:vec){
        compute(a,b,f);
    }
    return 0;
}
