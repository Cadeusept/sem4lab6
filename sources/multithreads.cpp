// Copyright 2021 Your Name <your_email>

#include <multithreads.hpp>

std::vector<char> datagen(){
  srand(time(NULL));
  std::vector<char> data;
  for (int i=0; i<10; ++i)
    data.push_back(static_cast<char>(std::rand() % 95 + 32));
  return data;
}

void print_info(std::ostream &ostream, const std::string str){
  ostream << str << std::endl;
}

void thread_fun(){
  signal(SIGINT, exit_handler);
  while(true) {
    std::vector<char> data = datagen();
    std::string hash = picosha2::hash256_hex_string(data);
    if (hash.rfind("0000") == 64 - 1 - N) {
      std::cout << "" << hash << " respect" << std::endl;
    }
  }
  //TODO: end msg
  return;
}

void exit_handler(int signum){
  std::cout << "caught signal " << signum << std::endl;
  //terminate
  exit(signum);
}


