#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // 创建一个640x480的图像，初始化为白色（255）
    cv::Mat mask = cv::Mat::ones(480, 640, CV_8UC1) * 255;

    // 将底部80行设置为黑色（0）
    for (int i = 200; i < 480; ++i)
    {
        for (int j = 0; j < 640; ++j)
        {
            mask.at<uchar>(i, j) = 0;
        }
    }

    // 保存图像为"fishesys_mask.jpg"
    if (cv::imwrite("fishesys_mask.jpg", mask))
    {
        std::cout << "Image saved successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Error: Could not save image!" << std::endl;
    }

    return 0;
}
