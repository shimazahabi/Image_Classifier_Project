#include "utils.hpp"

void load_image(std::string image_path, float image[IMAGE_SIZE][IMAGE_SIZE])
{
    cv::Mat matrix = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    cv::Mat converted_matrix;
    matrix.convertTo(converted_matrix, CV_32F, 1. / 255., 0);
    cv::MatConstIterator_<double> iter = converted_matrix.begin<double>(), end = converted_matrix.end<double>();
    // cv::MatConstIterator_<double> iter = matrix.begin<double>(), end = matrix.end<double>();

    int counter = 0;
    for (; iter != end; ++iter)
    {
        image[counter / 28][counter % 28] = *iter;
        counter++;
    }
}

std::string interpolation(std::string root, std::string type, std::string class_name, int index)
{
    std::string path = "";

    path.append(root);
    path.append("\\");
    path.append(type);
    path.append("\\");
    path.append(class_name);
    path.append("\\");
    path.append(std::to_string(index));
    path.append(".jpeg");

    return path;
}

int file_count(std::string path)
{
    int count{};
    std::filesystem::path directory_path{path};
    for (auto &p : std::filesystem::directory_iterator(directory_path))
    {
        ++count;
    }

    return count;
}