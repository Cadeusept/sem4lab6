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
  boost::shared_ptr< logging::core > core = logging::core::get();

  boost::shared_ptr< sinks::text_file_backend > backend =
      boost::make_shared< sinks::text_file_backend >(
          keywords::file_name = "file_%5N.log",
          keywords::rotation_size = 5 * 1024 * 1024,
          keywords::format = "[%TimeStamp%]: %Message%",
          keywords::time_based_rotation =
              sinks::file::rotation_at_time_point(12, 0, 0));

  typedef sinks::synchronous_sink< sinks::text_file_backend > sink_t;
  boost::shared_ptr< sink_t > sink(new sink_t(backend));
  // sink ->set_filter(logging::trivial::severity >= logging::trivial::info);
  core->add_sink(sink);
}

void exit_handler(int signum){
  std::cout << "caught signal " << signum << std::endl;
  //terminate
  exit(signum);
}


