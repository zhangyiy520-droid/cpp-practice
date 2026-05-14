#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

// 模拟一个简化版 MapPoint
class MapPoint {
public:
    // 构造函数
    MapPoint(double x, double y, double z, int id)//构造函数mappoint含有xyz和id
        : x_(x), y_(y), z_(z), id_(id) {//设置初始化
        std::cout << "MapPoint " << id_ << " created" << std::endl;
    }//输出mouge点被创造和id

    // 析构函数
    ~MapPoint() {
        std::cout << "MapPoint " << id_ << " destroyed" << std::endl;
    }//mappoint被删除时显示被删

    // 成员函数
    double distance() const {
        return std::sqrt(x_*x_ + y_*y_ + z_*z_);
    }//计算这个点的距离

    int id() const { return id_; }//设计函数输出这个的id，const只读取id不改变

private:
    double x_, y_, z_;
    int id_;
};//xyz和id无法被外界读取

int main() {
    // 1. 栈上创建
    MapPoint p1(1.0, 2.0, 3.0, 1);
    std::cout << "Distance: " << p1.distance() << std::endl;

    // 2. 堆上创建 + unique_ptr (独占所有权)
    auto p2 = std::make_unique<MapPoint>(4.0, 5.0, 6.0, 2);//p2作为指针指向存放这个点的坐标
    std::cout << "Distance: " << p2->distance() << std::endl;//因为p2是坐标，使用他指代的内容要->
    // unique_ptr 离开作用域自动释放 → 析构函数被调用

    // 3. shared_ptr (共享所有权) — SLAM 中最常用
    std::vector<std::shared_ptr<MapPoint>> map;//设计一个叫map的数组，map中有很多共享的mappoint
    auto sp = std::make_shared<MapPoint>(7.0, 8.0, 9.0, 3);//设计一个spmap point
    map.push_back(sp);     // sp 和 map[0] 共享所有权，把sp放入这个map的数组
    std::cout << "Use count: " << sp.use_count() << std::endl;  // 2，计数他的引用次数，map0一个sp一个

    map.clear();           // map 释放 → use_count = 1，map0被清理了
    std::cout << "Use count: " << sp.use_count() << std::endl;  // 1

    return 0;  // sp 离开作用域 → use_count = 0 → 析构
}
