#include "Logger.h"
#include <iostream>

int main() {

  mk::Logger::config = {true, true, true};
  mk::Logger::true_or_err(false, "some message");

}
