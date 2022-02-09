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

