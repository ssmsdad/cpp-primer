

#include<iostream>
#include<string>
#include<vector>
#include <memory>

class StrBlobPtr {
public:
    StrBlobPtr() : curr(0) {}
    const std::string &operator*() const;
    const std::string *operator->() const;
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

const std::string &StrBlobPtr::operator*() const {
    auto p = check(curr, "dereference past end");
    std::cout<<"hello,operator*"<<std::endl;
    return (*p)[curr];
}

const std::string *StrBlobPtr::operator->() const {
    return &this->operator*();
}


class MyClass {
public:
    MyClass() = default;
    MyClass(StrBlobPtr *p) : pointer(p) {}
    StrBlobPtr &operator*() { return *this->pointer; };
    StrBlobPtr *operator->() { return &this->operator*(); };

private:
    StrBlobPtr *pointer = nullptr;
};
            

int main(){
    StrBlobPtr p;
    MyClass myClass(&p);    
    // myClass->就会调用MyClass的operator->()，返回一个StrBlobPtr对象，然后其后的operator->()会调用StrBlobPtr的operator->()，返回一个 StrBlob 对象的指针，最后调用StrBlob的front()和back()。    
    std::cout << myClass->operator->()->front();
    std::cout << myClass->operator->()->back();
}