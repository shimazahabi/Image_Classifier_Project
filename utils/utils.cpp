#include "utils.hpp"

void load_image(std::string image_path, int index, float image[IMAGE_SIZE][IMAGE_SIZE])
{
    // cv::Mat matrix = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
    // cv::Mat converted_matrix;
    // matrix.convertTo(converted_matrix, CV_32F, 1. / 255., 0);
    // cv::MatConstIterator_<double> iter = converted_matrix.begin<double>(), end = converted_matrix.end<double>();

    // int counter = 0;
    // for (; iter != end; ++iter)
    // {
    //     image[counter / 28][counter % 28] = *iter;
    //     counter++;
    // }
    char buffer[IMAGE_BUFFER_SIZE];
    std::fstream file_stream(image_path, std::ios::in | std::ios::binary);
    file_stream.seekg(IMAGE_BUFFER_SIZE * sizeof(char) * index, std::ios::beg);
    file_stream.read(buffer, IMAGE_BUFFER_SIZE * sizeof(char));

    for (int i = 0; i < IMAGE_SIZE; i++)
    {
        for (int j = 0; j < IMAGE_SIZE; j++)
            image[i][j] = (int)(unsigned char)buffer[j + i * IMAGE_SIZE];
    }
}

std::string interpolation(std::string root, std::string type, std::string class_name)
{
    std::string path = "";

    path.append(root);
    path.append("\\");
    path.append(type);
    path.append("\\");
    path.append(class_name);
    path.append("\\data.dat");

    return path;
}

int file_count(std::string path)
{
    std::ifstream in_file(path, std::ios::binary);
    in_file.seekg(0, std::ios::end);
    int file_size = in_file.tellg();

    return file_size / IMAGE_BUFFER_SIZE;
}
