#include "Image.h"
#include <iostream>

const std::vector<cv::Scalar> COLORS = { cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0) };

Image::Image(const std::string& imagePath) {
    mat = cv::imread(imagePath);
    if (mat.empty()) {
        std::cerr << "Error loading image\n";
    }
}

bool Image::isEmpty() const {
    return mat.empty();
}

cv::Mat& Image::getMat() {
    return mat;
}

void Image::drawDetections(const std::vector<Detection>& detections, const std::vector<std::string>& classNames) {
    
    for (const auto& detection : detections) {
        auto box = detection.box;
        auto classId = detection.class_id;
        const auto color = COLORS[classId % COLORS.size()];
        cv::rectangle(mat, box, color, 3);
        cv::rectangle(mat, cv::Point(box.x, box.y - 20), cv::Point(box.x + box.width, box.y), color, cv::FILLED);
        cv::putText(mat, classNames[classId], cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
    }
}

void Image::show(const std::string& windowName, int width) const {


    int targetHeight = static_cast<int>(mat.rows * static_cast<float>(width) / mat.cols);
    cv::Size newSize(width, targetHeight);
    cv::Mat resizedImage;
    cv::resize(mat, resizedImage, newSize);

    // The GUI window is not displayed in the browser because I am using WSL(Windows Subsystem for Linux)
    //cv::imshow(windowName, resizedImage);
    //instead of showing the image, save it to a file
    cv::imwrite("output.jpg", resizedImage);
    cv::waitKey(0);
}
