#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> ivec;
    for (auto i = 0; i < 10; i++)
    {
        ivec.push_back(rand()%100);
    }
    cout<<"原始序列为："<<endl;
    for(auto c:ivec){
        cout<<c<<" ";
    }
    for (auto &c:ivec)
    {
        c%2?c*=2:c;
    }
    cout<<endl<<"修改后序列为："<<endl;
    for(auto c:ivec){
        cout<<c<<" ";
    }
}