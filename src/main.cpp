#include <iostream>
#include "Image.h"
#include "Detector.h"
#include "Utils.h"

int main(int argc, char** argv) {


    // Check if the user wants to use CUDA
    bool useCUDA = argc > 1 && strcmp(argv[1], "cuda") == 0;

    std::string imagePath = "../data/input/image.webp";
    Image image(imagePath);
    if (image.isEmpty()) {
        return -1;
    }

    std::string modelPath = "../models/yolov5s.onnx";
    Detector detector(modelPath, useCUDA);
    std::vector<Detection> detections;


    std::string classesPath = "../data/input/classes.txt";
    auto classList = loadClassList(classesPath);


    detector.detect(image.getMat(), detections, classList);

    
    image.drawDetections(detections, classList);
    image.show("Detections", 800);

    return 0;
}
