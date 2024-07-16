#include <opencv2/opencv.hpp>
#include <iostream>

// int main()
// {
//     // 创建一个640x480的图像，初始化为白色（255）
//     cv::Mat mask = cv::Mat::ones(480, 640, CV_8UC1) * 255;

//     // 将底部80行设置为黑色（0）
//     for (int i = 200; i < 480; ++i)
//     {
//         for (int j = 0; j < 640; ++j)
//         {
//             mask.at<uchar>(i, j) = 0;
//         }
//     }

//     // 保存图像为"fishesys_mask.jpg"
//     if (cv::imwrite("fishesys_mask.jpg", mask))
//     {
//         std::cout << "Image saved successfully!" << std::endl;
//     }
//     else
//     {
//         std::cerr << "Error: Could not save image!" << std::endl;
//     }

//     return 0;
// }

int main()
{
    // 图像大小
    int width = 640;
    int height = 480;

    // 创建一个空白图像，初始值为0（黑色）
    cv::Mat mask = cv::Mat::zeros(height, width, CV_8UC1);

    // 定义鱼眼的参数
    cv::Point center(width / 2, height / 2); // 中心位置
    cv::Size axes(width / 2, height / 2);    // 长轴和短轴的长度
    int angle = 0;                           // 椭圆的旋转角度
    int startAngle = 0;                      // 椭圆的起始角度
    int endAngle = 360;                      // 椭圆的终止角度

    // 绘制椭圆（鱼眼形状）
    cv::ellipse(mask, center, axes, angle, startAngle, endAngle, cv::Scalar(255), -1);

    // 显示和保存结果图像
    cv::imshow("Fisheye Mask", mask);
    cv::imwrite("fisheye_mask.png", mask);
    cv::waitKey(0);

    return 0;
}
