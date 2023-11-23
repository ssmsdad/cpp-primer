#include<iostream>
#include<vector>

using namespace std;

int main(){
    //3.15
    // vector<int> v;
    // int num;
    // while(cin>>num){
    //     v.push_back(num);
    // }
    // for(auto c:v){
    //     cout<<c<<" ";
    // }

    // 3.16
    vector<string> v1;
    string s;
    while(cin>>s){
        for(auto &c:s)
        {
            c=toupper(c);
        }
        v1.push_back(s);
    }
    for(auto &c:v1){
        cout<<c<<endl;
    }
}