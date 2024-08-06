#ifndef DETECTOR_H
#define DETECTOR_H

#include "Utils.h"

class Detector {
public:
    // Constructor
    Detector();

    // The constant values for the YOLOv5 model
    static constexpr float INPUT_WIDTH = 640.0;
    static constexpr float INPUT_HEIGHT = 640.0;
    static constexpr float SCORE_THRESHOLD = 0.2;
    // This threshold used for non-maximum suppression to remove overlapping bounding boxes
    static constexpr float NMS_THRESHOLD = 0.4;   
    static constexpr float CONFIDENCE_THRESHOLD = 0.4;

    // This function converts the input image to a blob suitable for model input
    cv::Mat format_yolov5(cv::Mat&);

    /*
    Performs object detection on an input image using the YOLOv5 model
    Converts the input image to a blob suitable for model input
    Processes the model outputs to extract class IDs, confidences, and bounding box coordinates
    Applies confidence and threshold filtering and performs non-maximum suppression to eliminate redundant detections
    */
    void detect(cv::Mat&, std::vector<Detection>&);

    // Destructor
    ~Detector();

private:
    int class_id;
    float confidence;
    cv::Rect box;
};

#endif // DETECTOR_H
