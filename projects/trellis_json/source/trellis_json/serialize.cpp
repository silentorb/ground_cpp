#include "serialize.h"
#include <vineyard/Trellis.h>

#include "rapidjson/document.h"
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include <fstream>

using namespace rapidjson;
using namespace std;
using namespace vineyard;

namespace trellis_json {

  void load_trellises(const Value &trellises, vector<unique_ptr<Trellis>> &trellis_buffer) {
    trellis_buffer.reserve(trellises.GetArray().Size());

    for (auto &trellis_node: trellises.GetArray()) {
      trellis_buffer.push_back(unique_ptr<Trellis>(new Trellis(trellis_node["name"].GetString())));
      auto &trellis = trellis_buffer[trellis_buffer.size() - 1];
    }
  }

  void load(const std::string &filename, vector<unique_ptr<Trellis>> &trellis_buffer) {
    ifstream file_stream(filename);
    IStreamWrapper stream_wrapper(file_stream);
    Document document;
    document.ParseStream(stream_wrapper);

    load_trellises(document["trellises"], trellis_buffer);
  }
}