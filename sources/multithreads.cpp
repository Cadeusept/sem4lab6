// Copyright 2021 Your Name <your_email>

#include <multithreads.hpp>

std::vector<char> datagen(){
  srand(time(nullptr));
  std::vector<char> data;
  for (int i=0; i<10; ++i)
    data.push_back(static_cast<char>(std::rand() % 95 + 32));
  return data;
}

void threadWork(Hash &hasher){
  hasher.work();
}

void Hash::work(){
  while(true) {
    std::vector<char> data = datagen();
    std::string hash = picosha2::hash256_hex_string(data);
    if (hash.substr(hash.size() - 4, hash.size()) == "0000") {
      std::cout << "" << hash << " respect" << std::endl;
    }
  }
}

void logging_preparation(){
  boost::log::register_simple_formatter_factory<
      boost::log::trivial::severity_level, char>("Severity");
  static const std::string format =
      "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%";

  auto all = boost::log::add_file_log(
      boost::log::keywords::file_name = "All/log_%N.log",
      boost::log::keywords::rotation_size = 128 * 1024 * 1024,
      boost::log::keywords::format = format);
  all->set_filter(boost::log::trivial::severity >= boost::log::trivial::trace);
}

void exit_handler(int signum){
  std::cout << "caught signal " << signum << std::endl;
  //terminate
  exit(signum);
}


