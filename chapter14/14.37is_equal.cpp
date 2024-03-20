

#include<iostream>
#include<vector>

class IsEqual{
    private:
        int val;
    public:
        IsEqual(int v):val(v){std::cout<<"调用了构造函数"<<std::endl;}
        bool operator()(int v){
            return v == val;
        }
};


#include <algorithm>

int main(){
    // // 重载了函数调用运算符的类的对象，称为函数对象,此时val的值为4
    // IsEqual isEqual(4);
    // // isEqual(5)等价于isEqual.operator()(5)
    // std::cout << isEqual(5) << std::endl;
    // std::cout << isEqual(6) << std::endl;
    // return 0;
    std::vector<int> ivec = {3, 2, 1, 4, 3, 7, 8, 6};
    // std::replace_if 当谓词为真时，将元素替换为新值
    std::replace_if(ivec.begin(), ivec.end(), IsEqual(3), 5);
    for (int i : ivec)
        std::cout << i << " ";
    std::cout << std::endl;
}