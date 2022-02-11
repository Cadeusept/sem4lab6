// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <thread>
#include <cmath>
#include <csignal>
#include <vector>
#include <iostream> //TODO: убрать библиотеку после отладки
#include "../third-party/PicoSHA2/picosha2.h"

#define N 4

std::vector<char> datagen();

void thread_fun();

void exit_handler(int signum);

#endif // INCLUDE_MULTITHREADS_HPP_
