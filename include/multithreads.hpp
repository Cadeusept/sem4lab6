// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <thread>
//#include <pthread.h>
#include <cmath>
#include <csignal>
#include <vector>
#include <boost/log/trivial.hpp>
#include <iostream> //TODO: убрать библиотеку после отладки
#include "../third-party/PicoSHA2/picosha2.h"

struct Hash{
  void work();
  const std::string requiredString = "0000";
};

void threadWork(Hash &hasher);

std::vector<char> datagen();

void logging_preparation();

void exit_handler(int signum);

#endif // INCLUDE_MULTITHREADS_HPP_
