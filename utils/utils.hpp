#pragma once

#define IMAGE_SIZE 28

#include <iostream>
#include <iomanip>

#include <filesystem>

#include <cmath>
#include <opencv2/opencv.hpp>

void load_image(std::string, float[IMAGE_SIZE][IMAGE_SIZE]);
std::string interpolation(std::string, std::string, std::string, int);
int file_count(std::string);
int show_image(std::string);