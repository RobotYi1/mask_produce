#include "mask_bounding.h"
#include <iostream>

// 函数：计算掩码图片的黑色边界
cv::Rect computeMaskBoundingBox(const cv::Mat &mask)
{
    // 检查掩码是否为空
    if (mask.empty())
    {
        std::cerr << "Error: The mask image is empty!" << std::endl;
        return cv::Rect();
    }

    // 查找掩码的边界框
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 如果没有找到轮廓，返回一个空矩形
    if (contours.empty())
    {
        return cv::Rect();
    }

    // 获取最大的轮廓的边界框
    cv::Rect boundingBox = cv::boundingRect(contours[0]);
    for (size_t i = 1; i < contours.size(); i++)
    {
        boundingBox |= cv::boundingRect(contours[i]);
    }

    return boundingBox;
}
