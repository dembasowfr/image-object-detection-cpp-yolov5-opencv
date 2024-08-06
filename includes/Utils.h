#ifndef UTILS_H
#define UTILS_H


#include <opencv2/opencv.hpp>
#include <fstream>
#include <vector>

public:

    Utils(); //Constructor 


    // This function reads the class names from the file and returns them as a vector
    std::vector<std::string> load_class_list();


    // This function loads the yolov5s model and sets the prefered backend and target
    void load_net(cv::dnn::Net& net, bool is_cuda);


    ~Utils(); //Destructor


#endif // UTILS_H