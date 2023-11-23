#include<iostream>
#include<string>

using namespace std;

int main(){
    //3.6
    string str="hello,world";
    for(auto &c:str)
    {
        c='X';
    }
    cout<<str<<endl;

    //3.7
    string str1="hello,world";
    for(char c:str1)
    {
        c='X';
    }
    cout<<str<<endl;
    
    //3.9
    string str2;
    //合法
    cout<<str2[5]<<endl;

    //3.10
    string str3="123+456=789";
    for(auto &c:str3){
        if(ispunct(c)){
            //'\0'代表空值
            c='\0';
        }
    }
    cout<<str3<<endl;

    //3.11
    const string str4="keep out!";
    for(auto &c:str4){
        cout<<c<<endl;
    }

}