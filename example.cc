#include "Logger.h"
#include <iostream>

int main() {
  mk::Logger::init();
  mk::Logger::level = mk::Logger::all;
  mk::Logger::config = {false, false, true, false};
  for (int i = 0; i < 30; i++) {
    TRUE_OR_ERR(false, "some message");
    LOG("hello");
    WARN("hello");
  }
}
