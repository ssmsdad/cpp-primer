#include<iostream>

using namespace std;

int main(){
    unsigned int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech = '\0';
    cout<<"Please input a string:"<<endl;
    while(cin >> ch && ch != 'Q'){
        if(prech == 'f'){
            switch(ch){
                case 'f':
                    ++ffCnt;
                    //实现prech的二级跳跃，完成一个字符只会被统计一次的功能
                    //如fffff，只会统计两次ff，删去这段代码，会统计四次ff
                    cin>>ch;
                    break;
                case 'l':
                    ++flCnt;
                    cin>>ch;
                    break;
                case 'i':
                    ++fiCnt;
                    cin>>ch;
                    break;
            }
        }
        prech = ch;
    }
    cout<<"ffCnt = "<<ffCnt<<endl;
    cout<<"flCnt = "<<flCnt<<endl;
    cout<<"fiCnt = "<<fiCnt<<endl;
    return 0;
}