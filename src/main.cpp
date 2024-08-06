#include <iostream>
#include "Image.h"
#include "Detector.h"
#include "Utils.h"

int main(int argc, char** argv) {
    std::string imagePath = "../data/input/image.png";
    bool useCUDA = argc > 1 && strcmp(argv[1], "cuda") == 0;

    Image image(imagePath);
    if (image.isEmpty()) {
        return -1;
    }

    Detector detector("../models/yolov5s.onnx", useCUDA);
    std::vector<Detection> detections;
    detector.detect(image.getMat(), detections);

    auto classList = loadClassList("../data/classes.txt");
    image.drawDetections(detections, classList);
    image.show("output", 800);

    return 0;
}
