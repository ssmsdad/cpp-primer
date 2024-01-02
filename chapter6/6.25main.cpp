#include <iostream>
using namespace std;
#define NDEBUG

// 6.36
string (&fun(int argc, char **argv))[10];
// 6.37
typedef string arrT[10];
arrT &fun2(int argc, char **argv);

auto fun3(int argc, char **argv) ->string(&)[10];

string str[10];
decltype(str) &fun4(int argc, char **argv);

// 6.38
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) &arrPtr(int i) {
    return (i % 2) ? odd : even;
}

void iii(int i=1,int j=2) {
    //定义了NDEBUG，就不会输出，用于调试
    #ifndef NDEBUG
    cout << i << " " << j << endl;
    #endif
}

int main(int argc, char **argv) {
    //const_cast用来改变常量的const属性
    const char *str;
    char *p=const_cast<char*>(str);
    int i=0,j=1;
    iii(i,j);
    for (int i = 0; i != argc; ++i) {
        cout << "argc[" << i << "]: " << argv[i] << endl;
    }

    return 0;
}
