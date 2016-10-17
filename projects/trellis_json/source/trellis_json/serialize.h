#pragma once

#include <functional>
#include <memory>
#include <string>

namespace vineyard {
  class Trellis;
}

namespace trellis_json {

  using Trellis_Delegate =std::function<void(const std::unique_ptr<vineyard::Trellis> &)>;

  void load(const std::string &filename, const Trellis_Delegate &delegate);
}
