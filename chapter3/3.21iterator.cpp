#include<iostream>
#include<vector>

using namespace std;

//binary search
    void binary(const vector<int> &text,int target)
    {
        auto begin=text.cbegin(),end=text.cend();
        auto mid=text.begin()+(end-begin)/2;
        while(*mid!=target&&mid!=end){
            if(target<*mid){
                end=mid;
            }else{
                begin=mid+1;
            }
            mid=begin+(end-begin)/2;
        }
        //仲哥，mid打印不了
            if(mid != end) {
            cout<<*mid;
        } else {
            cout<<"Target not found";
        }
    }

int main(){
    vector<char> s{10,'a'};
    string c="word";
    for(auto it=c.begin(); it!=c.end() && !isspace(*it); it++){
        *it=toupper(*it);
        cout<<*it;
    }

    //3.23
    vector<int> i(10,12);
    for(auto it=i.begin(); it!=i.end(); it++){
        *it=*it*2;
        cout<<*it<<" ";
    }

    vector<int> a{1,2,3,4,5,6,7,8,9};
    int target=5;
    binary(a,target);
    for(auto m:a){
        cout<<m<<" ";
    }

}


