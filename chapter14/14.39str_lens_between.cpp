

#include<iostream>
#include<string>    
#include<vector>    
#include <sstream>  // istringstream
#include <fstream>  // ifstream
#include <algorithm> // cout_if


class StrLensBetween{
    private:
        int min_len;
        int max_len;
    public:
        StrLensBetween(int min, int max):min_len(min), max_len(max){}
        bool operator()(const std::string &s){
            return s.size() >= min_len && s.size() <= max_len;
        }
};

class NotShorterThanLens{
    private:
        int len;
    public:
        NotShorterThanLens(int l):len(l){}
        bool operator()(const std::string &s){
            return s.size() >= len;
        }
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
    StrLensBetween slb(1, 9);
    std::cout << "len between 1 and 9, cnt : " << std::count_if(svec.begin(), svec.end(), slb) << std::endl;
    NotShorterThanLens sl(10);
    std::cout << "len not shorter than 10, cnt : " << std::count_if(svec.begin(), svec.end(), sl) << std::endl;
    return 0;
}