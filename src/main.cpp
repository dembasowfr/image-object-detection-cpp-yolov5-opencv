#include "Detector.h"

int main(int argc, char** argv)
{
    Utils utils;

    Detector detector;

    std::vector<std::string> class_list = utils.load_class_list();

    cv::Mat image = cv::imread("data/image.png"); // Provide the path to your input image
    if (image.empty())
    {
        std::cerr << "Error loading image\n";
        return -1;
    }

    bool is_cuda = argc > 1 && strcmp(argv[1], "cuda") == 0;

    cv::dnn::Net net;
    utils.load_net(net, is_cuda);

    std::vector<Detection> output;
    detector.detect(image, net, output, class_list);

    for (const auto& detection : output)
    {
        auto box = detection.box;
        auto classId = detection.class_id;
        const auto color = colors[classId % colors.size()];
        cv::rectangle(image, box, color, 3);

        cv::rectangle(image, cv::Point(box.x, box.y - 20), cv::Point(box.x + box.width, box.y), color, cv::FILLED);
        cv::putText(image, class_list[classId].c_str(), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
    }

    // As giving fixed value for width, and protecting original image ratio, output resolution declares in here.
    
    int targetWidth = 800;
    int targetHeight = static_cast<int>(image.rows * static_cast<float>(targetWidth) / image.cols);

    cv::Size newSize(targetWidth, targetHeight);

    // Resize image
    cv::Mat resized_image;
    cv::resize(image, resized_image, newSize);

    cv::imshow("output", resized_image);
    cv::waitKey(0);

    return 0;
}
