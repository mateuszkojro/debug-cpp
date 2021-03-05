#include "Logger.h"
#include <iostream>

void hello(){
  ERR("thats an err");
}

int main() {

  mk::Logger::Config config{.show_line = true,
                            .show_file = true,
                            .show_func = true,
                            .to_file = false};

  mk::Logger::init(mk::Logger::all, config);

  for (int i = 0; i < 30; i++) {
    TRUE_OR_ERR(false, "some message");
    TRUE_OR_PANIC(false,"message ");
    LOG("hello");
    WARN("hello");
    hello();
  }
}
