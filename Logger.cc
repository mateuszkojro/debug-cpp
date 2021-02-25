#include "Logger.h"
#include <iostream>

namespace mk {

void Logger::err(const std::string &text) {
  if (level <= Logger::info) {
    std::cerr << text << std::endl;
  }
}

void Logger::warn(const std::string &text) {
  if (level <= Logger::warning) {
    std::cerr << text << std::endl;
  }
}

void Logger::log(const std::string &text) {
  if (level <= Logger::info) {
    std::clog << text << std::endl;
  }
}

const Logger &Logger::get_instance() {
  if (!instance) {
    instance = new Logger;
  }
  return *instance;
}

} // namespace mk
