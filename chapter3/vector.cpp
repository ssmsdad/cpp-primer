#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<string>  v{10,"hi"};
    vector<string>  v1(10,"null");
    //仲哥
    // cout<<v<<endl;
    for(auto c:v){
        cout<<c<<endl;
    }
    vector<int> v2{10,42};
    for(int i=0;i<10;i++){
        cout<<v2[i]<<endl;
    }

    string s1;
    vector<string> text;
    //仲哥，这个循环怎么停下来
    while(cin>>s1){
        text.push_back(s1);
    }
}