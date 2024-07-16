#include <opencv2/opencv.hpp>
#include <iostream>
#include "mask_bounding.h"
#include "mask_generation.h"

// // Helper function to apply mask and build optical flow pyramid
// int buildOpticalFlowPyramidWithMask(const cv::Mat &image, const cv::Mat &mask,
//                                     std::vector<cv::Mat> &pyramid, cv::Size winSize, int maxLevel)
// {
//     cv::Mat masked_image;
//     image.copyTo(masked_image, mask);
//     int numLevels = cv::buildOpticalFlowPyramid(masked_image, pyramid, winSize, maxLevel);
//     return numLevels;
// }

// int main()
// {
//     // 读取输入图像
//     cv::Mat image = cv::imread("/home/yifanche/mask_produce/build/fisheye_mask.jpg", cv::IMREAD_GRAYSCALE);
//     if (image.empty())
//     {
//         std::cerr << "Error: Unable to load image!" << std::endl;
//         return -1;
//     }
//     // 创建掩码 (mask)
//     cv::Mat mask = cv::Mat::zeros(image.size(), image.type());
//     cv::circle(mask, cv::Point(mask.cols / 2, mask.rows / 2), mask.cols / 4, cv::Scalar(255), -1);

//     // 定义光流金字塔的参数
//     std::vector<cv::Mat> pyramid;
//     cv::Size winSize(21, 21);
//     int maxLevel = 3;

//     // 使用掩码构建光流金字塔
//     int numLevels = buildOpticalFlowPyramidWithMask(image, mask, pyramid, winSize, maxLevel);

//     std::cout << "Number of levels in pyramid: " << numLevels << std::endl;

//     // 可视化掩码和掩码图像
//     cv::imshow("Original Image", image);
//     cv::imshow("Mask", mask);
//     cv::imshow("Masked Image", mask);
//     cv::waitKey(0);

//     return 0;
// }

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    std::string image_path = argv[1];
    cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);

    if (image.empty())
    {
        std::cerr << "Error: Could not load image at " << image_path << std::endl;
        return -1;
    }

    // 假设图像中的掩码部分是黑色（值为0），其他部分为非黑色
    cv::Mat mask;
    cv::threshold(image, mask, 254, 255, cv::THRESH_BINARY);

    // 计算掩码的边界框
    cv::Rect boundingBox = computeMaskBoundingBox(mask);

    // 打印边界框信息
    std::cout << "Bounding box: x=" << boundingBox.x << ", y=" << boundingBox.y
              << ", width=" << boundingBox.width << ", height=" << boundingBox.height << std::endl;

    // 显示掩码和边界框
    cv::Mat result;
    cv::cvtColor(mask, result, cv::COLOR_GRAY2BGR);               // 转换为彩色图像以绘制边界框
    cv::rectangle(result, boundingBox, cv::Scalar(0, 255, 0), 2); // 绘制边界框
    cv::imshow("Mask with Bounding Box", result);
    cv::waitKey(0);

    return 0;
}

// int main()
// {
//     // 生成不同形状的掩码
//     cv::Size mask_size(640, 480);

//     // 矩形掩码
//     cv::Mat rect_mask = generateMask(mask_size, Shape::RECTANGLE, {cv::Point(0, 0), cv::Point(640, 400)});
//     cv::imwrite("rectangle_mask.png", rect_mask);

//     // 圆形掩码
//     cv::Mat circle_mask = generateMask(mask_size, Shape::CIRCLE, {cv::Point(320, 240), cv::Point(420, 240)});
//     cv::imwrite("circle_mask.png", circle_mask);

//     // 椭圆形掩码
//     cv::Mat ellipse_mask = generateMask(mask_size, Shape::ELLIPSE, {cv::Point(320, 240), cv::Point(420, 240), cv::Point(320, 340)});
//     cv::imwrite("ellipse_mask.png", ellipse_mask);

//     // 多边形掩码
//     std::vector<cv::Point> polygon_points = {cv::Point(100, 100), cv::Point(540, 100), cv::Point(540, 380), cv::Point(100, 380)};
//     cv::Mat polygon_mask = generateMask(mask_size, Shape::POLYGON, polygon_points);
//     cv::imwrite("polygon_mask.png", polygon_mask);

//     // 显示掩码
//     cv::imshow("Rectangle Mask", rect_mask);
//     cv::imshow("Circle Mask", circle_mask);
//     cv::imshow("Ellipse Mask", ellipse_mask);
//     cv::imshow("Polygon Mask", polygon_mask);
//     cv::waitKey(0);

//     return 0;
// }