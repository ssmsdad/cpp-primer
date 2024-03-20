

#include<iostream>
#include <string>
#include <vector>


class GetInput{
public:
    GetInput(std::istream &is = std::cin) : is(is) {}
    std::string operator()(){
        std::string s;
        std::getline(is, s);
        return is ? s : std::string();
    }
private:
    std::istream &is;
};


int main(){
    GetInput getInput;
    std::vector<std::string> vec;
    for (std::string s; !(s = getInput()).empty(); vec.push_back(s));
    for(const auto &s : vec)    
        std::cout << s << std::endl;
    return 0;
}