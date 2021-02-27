#include "Logger.h"
#include <assert.h>
#include <bits/types/__FILE.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

namespace mk {

Logger::Logger() {}

void Logger::panic(const std::string &text) {
  std::cerr << Logger::info << text << std::endl;
  assert(false);
  exit(1);
}

void Logger::err(const std::string &text) {
  if (level <= Logger::all) {
    std::cerr << Logger::info << text << std::endl;
  }
}

void Logger::warn(const std::string &text) {
  if (level <= Logger::warning) {
    std::cerr << Logger::info << text << std::endl;
  }
}

void Logger::log(const std::string &text) {
  if (level <= Logger::all) {
    std::clog << Logger::info << text << std::endl;
  }
}

const Logger &Logger::get_instance() {
  // if instance does not exists create it
  if (!instance) {
    instance = new Logger;
  }
  return *instance;
}

void Logger::true_or_panic(bool condition, const std::string &text) {
  if (!condition) {
    Logger::panic(text);
  }
}

void Logger::true_or_err(bool condition, const std::string &text) {
  if (!condition) {
    std::cerr << Logger::info << text << std::endl;
  }
}

// @TODO refactor
std::ostream &Logger::info(std::ostream &in) {

  in << ((Logger::config.show_file && Logger::config.show_func &&
          Logger::config.show_line)
             ? "[ "
             : "");

  in << ((Logger::config.show_file) ? __FILE__ : "");
  in << ":";
  in << ((Logger::config.show_func) ? __PRETTY_FUNCTION__ : "");
  in << ":";
  in << ((Logger::config.show_line) ? std::to_string(__LINE__) : "");

  in << ((Logger::config.show_file && Logger::config.show_func &&
          Logger::config.show_line)
             ? " ] "
             : "");
  return in;
}

Logger::Config Logger::config = {false, false, false};
Logger::Level Logger::level = Logger::none;
Logger *Logger::instance = nullptr;

} // namespace mk
