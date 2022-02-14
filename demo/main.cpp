#include <multithreads.hpp>

int main(int argc, char *argv[]) {
  unsigned int threadNum;
  logging_preparation();
  if (argc == 1) {
    threadNum = std::thread::hardware_concurrency();
  } else if (argc == 2) {
    threadNum = std::atoi(argv[1]);
  } else {
    BOOST_LOG_TRIVIAL(error) << "Invalid argument";
    throw std::invalid_argument("Invalid argument");
    return 1;
  }

  std::vector<std::thread> thread_arr;
  Hash hasher;
  std::signal(SIGINT, exit_handler);
  for (unsigned int i = 0; i < threadNum; ++i){
    thread_arr.emplace_back(threadWork, std::ref(hasher));
  }
  for (auto &thread : thread_arr) {
    thread.join();
  }

}