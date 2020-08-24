#ifndef COORDINATE_MAP_H
#define COORDINATE_MAP_H

#include "agent.hpp"
#include "coordinate.hpp"
#include <unordered_map>

struct hash_pair {
  template <typename T1, typename T2>
  size_t operator()(const std::pair<T1, T2>& p) const {
    auto hash1 = std::hash<T1>{}(p.first);
    auto hash2 = std::hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

typedef std::unordered_map<Point, Agent*, hash_pair> Map;

class CoordinateMap {
  int x_bound;
  int y_bound;

  public:
  Map map;
  CoordinateMap(int x_bound, int y_bound);
  ~CoordinateMap();
  bool add_agent(Point point, Agent* agent);
  bool remove_agent(Point point, Agent* agent);
  bool is_empty(Point point);
  Point get_empty_point();
  Point get_empty_point(Point origin);
};

#endif