#pragma once

#define IMAGE_SIZE 28
#define BATCH_SIZE 100
#define IMAGE_BUFFER_SIZE 784

#include <iostream>
#include <iomanip>
#include <filesystem>
#include <cmath>
#include <fstream>

void load_image(std::string, int, float[IMAGE_SIZE][IMAGE_SIZE]);
std::string interpolation(std::string, std::string, std::string);
int file_count(std::string);