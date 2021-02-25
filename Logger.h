#pragma once

#include <cstddef>
#include <iostream>

namespace mk {

class Logger {
public:
  static struct Config {
    bool show_line = false;
    bool show_file = false;
    bool show_func = false;
  } config;

  static const Logger &get_instance();

  static void log(const std::string &);
  static void warn(const std::string &);
  static void err(const std::string &);

  static void log(const std::string &, size_t debug_flag);
  static void warn(const std::string &, size_t debug_flag);
  static void err(const std::string &, size_t debug_flag);

  // Level get_level();
  void set_level(/* Log level */);

private:
  static enum Level {
    all = 0,
    info = 1,
    warning = 2,
    error = 3,
    none = 4
  } level;

  static Logger *instance;

  Logger(/* Config */);
};

} // namespace mk
