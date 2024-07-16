#include "mask_generation.h"

cv::Mat generateMask(cv::Size size, Shape shape, std::vector<cv::Point> points, int thickness)
{
    cv::Mat mask = cv::Mat::zeros(size, CV_8UC1);

    switch (shape)
    {
    case Shape::RECTANGLE:
    {
        if (points.size() < 2)
        {
            std::cerr << "Error: RECTANGLE shape requires 2 points." << std::endl;
            return mask;
        }
        cv::rectangle(mask, points[0], points[1], cv::Scalar(255), thickness);
        break;
    }

    case Shape::CIRCLE:
    {
        if (points.size() < 2)
        {
            std::cerr << "Error: CIRCLE shape requires center point and radius." << std::endl;
            return mask;
        }
        cv::circle(mask, points[0], cv::norm(points[0] - points[1]), cv::Scalar(255), thickness);
        break;
    }

    case Shape::ELLIPSE:
    {
        if (points.size() < 3)
        {
            std::cerr << "Error: ELLIPSE shape requires center point, axes lengths and angle." << std::endl;
            return mask;
        }
        cv::ellipse(mask, points[0], cv::Size(cv::norm(points[0] - points[1]), cv::norm(points[0] - points[2])), 0, 0, 360, cv::Scalar(255), thickness);
        break;
    }

    case Shape::POLYGON:
    {
        if (points.size() < 3)
        {
            std::cerr << "Error: POLYGON shape requires at least 3 points." << std::endl;
            return mask;
        }
        std::vector<std::vector<cv::Point>> pts = {points};
        cv::fillPoly(mask, pts, cv::Scalar(255));
        break;
    }

    default:
    {
        std::cerr << "Error: Unknown shape." << std::endl;
        return mask;
    }
    }

    return mask;
}
