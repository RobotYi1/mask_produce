#ifndef MASK_GENERATOR_H
#define MASK_GENERATOR_H

#include <opencv2/opencv.hpp>

enum class Shape
{
    RECTANGLE,
    CIRCLE,
    ELLIPSE,
    POLYGON
};

cv::Mat generateMask(cv::Size size, Shape shape, std::vector<cv::Point> points = {}, int thickness = -1);

#endif // MASK_GENERATOR_H
