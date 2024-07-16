#ifndef MASK_BOUNDING_BOX_H
#define MASK_BOUNDING_BOX_H

#include <opencv2/opencv.hpp>

cv::Rect computeMaskBoundingBox(const cv::Mat &mask);

#endif // MASK_BOUNDING_BOX_H
