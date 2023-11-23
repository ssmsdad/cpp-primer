#include<iostream>
#include<string>

using namespace std;

int main(){
    //max
    string s1="zhangwenzhe";
    string s2="zhangzhong";
    cout<<s1.size()<<endl;
    cout<<s1.length()<<endl;
    if(s1==s2){
        cout<<s1<<"与"<<s2<<"相等"<<endl;
    }
    else{
        cout<<((s1>s2)?s1:s2)<<endl;
    }

    //max length
    if(s1==s2){
        cout<<s1<<"与"<<s2<<"相等"<<endl;
    }
    else{
        cout<<((s1.size()>s2.size())?s1:s2)<<endl;
    }

    string temp;
    string buff;
    while (getline(cin,temp))
    {
        if(!temp.empty()){
            buff+=temp+" ";
        }
    }
    cout<<buff;
    
}