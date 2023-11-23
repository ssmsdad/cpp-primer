#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool compare(const int *ab,const int *ae,const int *bb,const int *be){
    while(ab != ae && bb != be){
        if(*ab > *bb)
            return true;
        else if(*ab < *bb)
            return false;
        ab++;
        bb++;
    }
    return false;   
}
int main(){
    //3.31
    int a[10];
    for(size_t i=0;i<10;i++){
        a[i]=i;
    }

    for (auto c:a)
    {
       cout<<c<<" ";
    }
    
    //3.32
    vector<int> ivec;
    for (size_t i = 0; i < 10; i++)
    {
        ivec.push_back(i);
    }

    for (auto d:ivec)
    {
       cout<<d<<" ";;
    }

    constexpr int sz = 5;
    int arr[sz] = {1,2,3,4,5};
    //p指向了尾元素的下一位置
    int *p=arr+sz;
    cout<<*p<<endl;
    
    //3.36
    int m[]={1,2,3,4,5};
    int n[]={0,1,2,3,4};
    cout<<compare(begin(m),end(m),begin(n),end(n))<<endl;

    vector<int> v1{1,2,3,4,5};
    vector<int> v2{0,1,2,3,4};
    if(v1>v2){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }

    char ch[]="abcdefg";
    cout<<strlen(ch)<<endl;

    int k[3][4]={{0},{4},{8}}; //0 0 0 0 4 0 0 0 8 0 0 0
    int t[3][4]={0,3,6,9};  //0 3 6 9 0 0 0 0 0 0 0 0
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout<<t[i][j]<<" ";
        }
        
    }
    //将row这个数组绑定到数组k的第二行
    int (&row)[4]=k[1];

    size_t cnt=0;
    for(auto &row : k){
        for (auto &col : row){
            col=cnt;
            cnt++;
            cout<<col<<" ";
            cout<<endl;
        }       
    }

    for(auto p=k;p!=k+3;p++){
        for(auto q=*p;q!=*p+4;q++){
            cout<<*q<<" ";
        }
        cout<<endl;
    }
}