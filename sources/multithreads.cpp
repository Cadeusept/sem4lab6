// Copyright 2021 Your Name <your_email>

#include <multithreads.hpp>

std::string datagen(){
  std::vector<char> data;
  for (int i=0; i<50; ++i)
    data.push_back(static_cast<char>(std::rand() % 95 + 32));
  std::string outp(data.begin(), data.end());
  return outp;
}

void threadWork(Hash &hasher){
  hasher.work();
}

void logging_preparation(){
  logging::register_simple_formatter_factory<
      logging::trivial::severity_level, char>("Severity");
  static const std::string format =
      "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%";

  auto all = logging::add_file_log(
      logging::keywords::file_name = "All/log_%N.log",
      logging::keywords::rotation_size = 128 * 1024 * 1024,
      logging::keywords::format = format);
  all->set_filter(logging::trivial::severity >= logging::trivial::trace);

  auto correct = logging::add_file_log(
      logging::keywords::file_name = "Correct/log_%N.log",
      logging::keywords::rotation_size = 128 * 1024 * 1024,
      logging::keywords::format = format);
  correct->set_filter(logging::trivial::severity >=
                      logging::trivial::info);

  auto console = logging::add_console_log(
      std::cout, logging::keywords::format = format);
  console->set_filter(logging::trivial::severity >=
                      logging::trivial::info);

  logging::add_common_attributes();
}

void Hash::work(){
  while(thread_flag) {
    std::string data = datagen();
    std::string hash = picosha2::hash256_hex_string(data);
    BOOST_LOG_TRIVIAL(trace) << "ATTEMPT\t" << data << "\tHash\t" << hash
                             << std::endl;
    if (hash.substr(hash.size() - 4, hash.size()) == "0000") {
      BOOST_LOG_TRIVIAL(info) << "CORRECT\t" << data << "\tHash\t" << hash
                             << std::endl;
    }
  }

  return;
}

void exit_handler(int signum){
  BOOST_LOG_TRIVIAL(trace) << "Caught signal " <<
      signum << ", terminating program..." << std::endl;
  thread_flag = false;
}


