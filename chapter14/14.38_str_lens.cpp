

#include<iostream>
#include<string>    
#include<vector>    
#include <sstream>  // istringstream
#include <fstream>  // ifstream
#include <algorithm> // cout_if

class StrLens{
public:
    StrLens(int l):len(l){}
    bool operator()(const std::string &s){
        return s.size() == len;
    }
private:
    int len;
};



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "请给出文件名" << std::endl;
        return -1;
    }
    std::ifstream in(argv[1]);
    if (!in) {
        std::cerr << "无法打开输入文件" << std::endl;
        return -1;
    }
    

    std::vector<std::string> svec;
    std::string line;
    std::string word;
    // 将文件中所有单词读入svec，首先读取一行，然后处理该行中的每个单词
    while (getline(in, line)) {
        // 构造字符串流，读取单词
        std::istringstream l_in(line);          
        while (l_in >> word)
            svec.push_back(word);
    }
    const int MinLen = 1;
    const int MaxLen = 10;
    for (int i = MinLen; i <= MaxLen; ++i) {
        StrLens sl(i);
        //cout_if计算使一元谓词为true的元素个数
        std::cout << "len = " << i << " ,cnt : " << std::count_if(svec.begin(), svec.end(), sl) << std::endl;
    }
}