#include "utils\\utils.hpp"
#include "utils\\timer.hpp"

int main()
{
    Timer timer;
    
    std::string image_path = interpolation("data\\mnist", "train", "0", 1);
    show_image(image_path);

    return 0;
}