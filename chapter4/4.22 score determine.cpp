#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> grade;
    vector<string> level;
    for (size_t i = 0; i < 10; i++)
    {
        grade.push_back(rand()%100);
    }
    cout<<"成绩序列为："<<endl;
    for (auto c:grade)
    {
        cout<<c<<" ";
    }
    cout<<"等级分别为："<<endl;
    for (auto &c:grade)
    {   
        string s;
        s=c>90?"hign pass":c>75?"pass":c>60?"low pass":"fail";
        level.push_back(s);
    }
    for(auto c:level){
        cout<<c<<" ";
    }
}