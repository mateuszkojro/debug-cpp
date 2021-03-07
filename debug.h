#ifndef DEBUG_TOOLS_H
#define DEBUG_TOOLS_H

#include <chrono>
#include <exception>
#include <iostream>

class not_implemented_exception : std::exception {
public:
  virtual const char *what() const throw() override {
    return "Function is not yet implemented";
  }
};
#ifdef LEGACY_DEBUG

// Sends a message and exits program
#define ERR(message)                                                           \
  std::cerr << "_________"                                                     \
            << "Error"                                                         \
            << "_________" << std::endl                                        \
            << "(" << __FILE__ << ":" << __LINE__ << ")" << std::endl                                         \
            << message << std::endl;                                           \
  exit(111)

// Sends message ands pauses the program
#define WARN(message)                                                          \
  std::clog << "________"                                                      \
            << "Warn"                                                          \
            << "________" << std::endl                                         \
            << "(" << __FILE__ << ":" << __LINE__ << ")" << std::endl                                         \
            << message << std::endl;                                           \
  std::string a;                                                               \
  std::cin >> a;

// Logs a message
#define LOG(message) std::clog << std::endl << "LOG ("  << __FILE__ << ":" << __LINE__   << "): "<< message << std::endl

#define DEBC(value, message)                                                   \
  (std::clog << value << " (int)" << (int)value << ": " << message << std::endl)
#define DEB(message) (std::clog << "___" << message << "___" << std::endl)

#define TIME_START(name) auto name = std::chrono::high_resolution_clock::now()
#define TIME_STOP(name, desc)                                                  \
  auto stop = std::chrono::high_resolution_clock::now();                       \
  std::clog << "TIME: " << desc << " took: "                                   \
            << std::chrono::duration_cast<std::chrono::microseconds>(stop -    \
                                                                     name)     \
                   .count()                                                    \
            << std::endl
#else


#endif
#endif
