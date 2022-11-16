#include "timer.hpp"

Timer::Timer()
{
    this->start_time = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    this->end_time = std::chrono::high_resolution_clock::now();
    long duration = std::chrono::duration_cast<std::chrono::microseconds>(
        this->end_time - this->start_time).count();

    std::cout << "Runtime time: " << duration << std::endl;
}