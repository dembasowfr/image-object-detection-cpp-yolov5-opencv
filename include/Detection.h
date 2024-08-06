#ifndef DETECTION_H
#define DETECTION_H

#include <opencv2/opencv.hpp>

struct Detection {
    int class_id;
    float confidence;
    cv::Rect box;
};

#endif // DETECTION_H
