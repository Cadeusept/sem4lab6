#include <multithreads.hpp>
#include <iostream>
#include <vector>

int main() {
  unsigned int M = 0;
  std::cout << "Enter max number of threads" << std::endl;
  std::cin >> M;
  if (M == 0 || M > std::thread::hardware_concurrency())
    M = std::thread::hardware_concurrency();

  std::vector<std::thread> thread_arr;
  for (unsigned int i = 0; i < M; ++i){
    std::thread thr(thread_fun);
    thread_arr.push_back(thr);
    thread_arr[i].join();
  }


}