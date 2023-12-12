#include<iostream>

using namespace std;

int main(){
    int ival1, ival2;
    cout<<"Please input two integers:"<<endl;
    while(cin>>ival1>>ival2){
        try{
            if(ival2==0){
                throw runtime_error("The divisor cannot be zero.");
            }
            else{
                cout<<ival1<<" / "<<ival2<<" = "<<ival1/ival2<<endl;
                break;
            }
        }catch(runtime_error err){
            cout<<err.what()<<endl;
            cout<<"continue(y or n)"<<endl;
            char ch;
            cin>>ch;
            if(!cin || ch == 'n'){
                break;
            }
        }
    };
    return 0;
}