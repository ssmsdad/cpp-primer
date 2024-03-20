

#include <functional>
#include<iostream>
#include<vector>
#include<algorithm>


int main(){
    int n;
    std::cin>>n;
    std::modulus<int> mod;
    std::vector<int> ivec{1,2,4,5,10};
    auto prediator = [mod,n](int i){return 0==mod(n,i);};
    auto is_divisible= std::all_of(ivec.begin(), ivec.end(), prediator);
    std::cout<<n<<(is_divisible?" is ":" is not ")<<"divisible by 1,2,4,5,10"<<std::endl;
}