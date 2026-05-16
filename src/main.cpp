#include<iostream>
#include "calculator.h"
int main(){
    std::cout << "3+4= " << Calculator::add(3,4) << std::endl;
    std::cout << "3*4= " << Calculator::multiply(3,4) << std::endl;
    return 0;
}

