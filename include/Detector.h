#ifndef DETECTOR_H
#define DETECTOR_H

#include <opencv2/opencv.hpp>
#include "Detection.h"

class Detector {
public:
    Detector(const std::string& modelPath, bool useCUDA);
    void detect(const cv::Mat& image, std::vector<Detection>& output, const std::vector<std::string>& className);

private:
    cv::dnn::Net net;
    std::vector<std::string> classList;
    cv::Mat formatYOLOv5(const cv::Mat& source);
};

#endif // DETECTOR_H
