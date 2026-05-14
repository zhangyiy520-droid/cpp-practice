#include<iostream>

int main(){
    int x = 42;//指定x等于的值
    std::cout << "x =" << x << std::endl;
    std::cout << "&x =" << &x << std::endl;//输出x的地址

    int* p = &x;
    std::cout << "p =" << p << std::endl;//输出p关联的x地址
    std::cout << "*p =" << *p << std::endl;//输出*p的索引值

    *p = 100;//通过指针修改x
    std::cout << "x now =" << x <<std::endl;//输出通过指针p修改后x的值

    int& r = x;//关联x等于r
    r = 200;//通过引用直接修改x
    std::cout << "x now =" << x << std::endl;

    const int y = 10;//用const禁止y被修改
    const int* cp = &x;//禁止通过cp修改x的地址
    cp = &y;//通过cp引用y

    int* np = nullptr;//命令np为空指针
    if (np == nullptr){
        std::cout << "np is null" << std::endl;
    }//如果np为空指针输出np为空

    return 0;
}
