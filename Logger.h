#pragma once

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

namespace mk {

class Logger {
public:
  static struct Config {
    bool show_line = false;
    bool show_file = false;
    bool show_func = false;
    bool to_file = false;
  } config;

  struct Info {
    std::string file;
    size_t line;
    std::string function;
  };

  static enum Level { all = 0, warning = 1, error = 2, none = 3 } level;

  static const Logger &get_instance();

  static void init(Logger::Level level = Logger::none,
                   Logger::Config config = {false, false, false, false},
                   std::string path = "./log");

  static void log(const std::string &, Info);
  static void warn(const std::string &, Info);
  static void err(const std::string &, Info);
  static void panic(const std::string &, Info);

  static void true_or_panic(bool, const std::string &, Info);
  static void true_or_err(bool, const std::string &, Info);

  static void log(const std::string &, size_t debug_flag);
  static void warn(const std::string &, size_t debug_flag);
  static void err(const std::string &, size_t debug_flag);

  static std::ostream &info(std::ostream &);
  static std::fstream &info(std::fstream &);

  // Level get_level();
  static void set_level(/* Log level */);

private:
  // singelton instance
  static Logger *instance;

  static std::fstream log_file_;

  Logger(/* Config */);
};

std::fstream &operator<<(std::fstream &, Logger::Info);
std::ostream &operator<<(std::ostream &ou, Logger::Info);

#define GET_CODE_INFO                                                          \
  { __FILE__, __LINE__, __PRETTY_FUNCTION__ }

#define LOG(message) mk::Logger::log(message, GET_CODE_INFO)
#define ERR(mess) mk::Logger::err(message, GET_CODE_INFO)
#define WARN(message) mk::Logger::warn(message, GET_CODE_INFO)
#define TRUE_OR_ERR(condition, message)                                        \
  mk::Logger::true_or_err(condition, message, (mk::Logger::Info)GET_CODE_INFO)
#define TURE_OR_PANIC(condition, message)                                      \
  mk::Logger::true_or_panic(condition, message, GET_CODE_INFO)

} // namespace mk
