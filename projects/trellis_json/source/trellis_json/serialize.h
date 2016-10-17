#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace vineyard {
  class Trellis;
}

namespace trellis_json {

  using Trellis_Delegate =std::function<void(const std::unique_ptr<vineyard::Trellis> &)>;

  void load(const std::string &filename, std::vector<std::unique_ptr<vineyard::Trellis>> &trellis_buffer);
}
