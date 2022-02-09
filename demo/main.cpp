#include <multithreads.hpp>
#include <iostream>

int main() {
  unsigned int M = 0, N = 0;
  std::cout << "Enter max number of threads" << std::endl;
  std::cin >> M;
  if (M == 0 || M > std::thread::hardware_concurrency())
    M = std::thread::hardware_concurrency();
  std::cout << "Enter the number of zeros" << std::endl;
  std::cin >> N;
  std::string str = picosha2::hash256_hex_string(datagen());
  print_info(std::cout, str);
}