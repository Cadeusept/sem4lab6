// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <thread>
#include <cmath>
#include "../third-party/PicoSHA2/picosha2.h"

std::vector<char> datagen();

void print_info(std::ostream &ostream, const std::string str);

#endif // INCLUDE_MULTITHREADS_HPP_
