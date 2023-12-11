#include<iostream>
#include<string>

using namespace std;

int main(){
    string curStr, preStr=" ",maxStr;
    unsigned int curCnt = 1, maxCnt = 0;
    cout<<"Please input a string:"<<endl;
    while(cin>>curStr && curStr != "Q"){
        if(curStr == preStr){
            ++curCnt;
            if(curCnt > maxCnt){
                maxCnt = curCnt;
                maxStr = curStr;
            }
        }
        else{
            curCnt = 1;
        }
        preStr = curStr;
    }
    if(maxCnt > 1){
        cout<<"The max string is "<<maxStr<<", it appears "<<maxCnt<<" times."<<endl;
    }
    else{
        cout<<"There is no repeated string."<<endl;
    }
    return 0;
}