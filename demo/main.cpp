#include <multithreads.hpp>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  unsigned int threadNum;
  if (argc == 1) {
    threadNum = std::thread::hardware_concurrency();
  } else if (argc == 2) {
    threadNum = std::atoi(argv[1]);
  } else {
    throw std::invalid_argument("Incorrect parameters!");
    return 1;
  }

  std::vector<std::thread> thread_arr;
  Hash hasher;
  for (unsigned int i = 0; i < threadNum; ++i){
    thread_arr.emplace_back(threadWork, std::ref(hasher));
  }
  for (auto &thread : thread_arr) {
    thread.join();
  }

}