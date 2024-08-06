#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include "Detection.h"

class Image {
public:
    Image(const std::string& imagePath);
    bool isEmpty() const;
    cv::Mat& getMat();
    void drawDetections(const std::vector<Detection>& detections, const std::vector<std::string>& classNames);
    void show(const std::string& windowName, int width) const;

private:
    cv::Mat mat;
};

#endif // IMAGE_H
