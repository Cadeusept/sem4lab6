// Copyright 2021 Your Name <your_email>

#include <multithreads.hpp>

int main(int argc, char *argv[]) {
  srand(time(nullptr));
  unsigned int threadNum;
  logging_preparation();
  std::ofstream json_file;
  if (argc == 1) {
    threadNum = std::thread::hardware_concurrency();
  } else if (argc == 2 || argc == 3) {
    threadNum = std::atoi(argv[1]);
    if (threadNum > std::thread::hardware_concurrency())
      threadNum = std::thread::hardware_concurrency();
    if (argc == 3) {
      json_file.open(std::string(argv[2]));
      json_flag = true;
    }
  } else {
    BOOST_LOG_TRIVIAL(error) << "Invalid argument";
    throw std::invalid_argument("Invalid argument");
  }

  BOOST_LOG_TRIVIAL(trace) << "Number of threads is " << threadNum << std::endl;

  std::vector<std::thread> thread_arr;
  Hash hasher;
  std::signal(SIGINT, exit_handler);
  for (unsigned int i = 0; i < threadNum; ++i){
    thread_arr.emplace_back(threadWork, std::ref(hasher));
  }
  for (auto &thread : thread_arr) {
    thread.join();
  }

  if (json_flag) {
    json_file << json_arr.array << std::endl;
  }

  json_file.close();
  return 0;
}