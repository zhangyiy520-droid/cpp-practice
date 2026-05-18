#include<opencv2/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

int main(int argc , char** argv){
    if(argc < 2){
	std::cout << "Usage: ./show_image <image_path>" << std::endl;
    return 1;
    }

    cv::Mat image = cv::imread(argv[1],cv::IMREAD_COLOR);
    if(image.empty()){
	std::cerr << "Failed to load: " << argv[1] << std::endl;
    return 1;
    }

    std::cout << "image.size=" << image.cols << "x" << image.rows << std::endl;
    std::cout << "image_channels= " << image.channels() << std::endl;

    cv::imwrite("output.png" , image);
    std::cout << "output.png_saved" << std::endl;
    return 0;
}
