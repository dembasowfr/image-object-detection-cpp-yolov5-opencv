#include "Utils.h"


Utils::Utils() {}



std::vector<std::string> Utils::load_class_list() {
    std::vector<std::string> class_names;
    std::ifstream ifs("coco.names");
    std::string line;
    while (std::getline(ifs, line)) {
        class_names.push_back(line);
    }
    return class_names;
}



void Utils::load_net(cv::dnn::Net& net, bool is_cuda) {

    auto result = cv::dnn::readNet("models/yolov5s.onnx");

    if (is_cuda) {
        std::cout << "Attempting to use CUDA\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA_FP16);
    }
    else {
        std::cout << "Running on CPU\n";
        result.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        result.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }
    net = result;
}



Utils::~Utils() {}