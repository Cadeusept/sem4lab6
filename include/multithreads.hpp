// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include <thread>
//#include <pthread.h>
#include <cmath>
#include <csignal>
#include <vector>
#include <boost/log/utility/setup.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/expressions/keyword.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iostream> //TODO: убрать библиотеку после отладки
#include "../third-party/PicoSHA2/picosha2.h"

namespace logging = boost::log;

struct Hash{
  void work();
  const std::string requiredString = "0000";
};

void threadWork(Hash &hasher);

std::vector<char> datagen();

void logging_preparation();

void exit_handler(int signum);

#endif // INCLUDE_MULTITHREADS_HPP_
