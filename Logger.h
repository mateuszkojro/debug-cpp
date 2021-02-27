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

  static const Logger &get_instance();

  static void log(const std::string &);
  static void warn(const std::string &);
  static void err(const std::string &);
  static void panic(const std::string&);

  static void true_or_panic(bool, const std::string&);
  static void true_or_err(bool, const std::string&);

  static void log(const std::string &, size_t debug_flag);
  static void warn(const std::string &, size_t debug_flag);
  static void err(const std::string &, size_t debug_flag);

  static std::ostream& info(std::ostream&); 

  // Level get_level();
  void set_level(/* Log level */);

private:
  static enum Level {
    all = 0,
    warning = 1,
    error = 2,
    none = 3
  } level;

  // singelton instance
  static Logger *instance;

  Logger(/* Config */);
};

} // namespace mk
