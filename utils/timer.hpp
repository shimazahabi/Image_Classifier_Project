#pragma once

#include <iostream>
#include <chrono>
#include <ctime>


class Timer
{
public:
    Timer();
    ~Timer();

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
};