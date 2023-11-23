#include<iostream>
#include<string>

using namespace std;

int main(){
    //逐行
    string line;
    while(getline(cin,line)){
        cout<<line<<endl;
    }
    //逐单词
    // string word;
    // while(cin>>word){
    //     cout<<word<<endl;
    // }
    return 0;
}