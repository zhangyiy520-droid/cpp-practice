#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <filesystem>

int main(){
    std::string file_path;
//读取文件路径

    std::getline(std::cin,file_path);
//存储键盘输入的文件路径并保存

    std::ifstream fin(file_path);
//打开文件

    std::filesystem::path p(file_path);
//解析文件，获取文件名

    std::cout << "文件名:" << p.filename() << std::endl;
//输出文件名

    struct stat file_info;
//声明有这个东西

    stat(file_path.c_str(), &file_info);
//读取文件，获得字符和修改时间

    std::cout << "文件大小: " << file_info.st_size << " bytes" << std::endl;
//输出文件大小

    std::cout << "最后修改时间:" << file_info.st_mtime << std::endl;
    return 0; 
}
