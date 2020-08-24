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

typedef std::unordered_map<Point, Agent*, hash_pair> CoordinateMap;

bool add_element(CoordinateMap space, Point point, Agent* element);

bool is_empty(CoordinateMap space, Point point);

Point get_empty_point(CoordinateMap space);

Point get_empty_point(CoordinateMap space, Point origin);

#endif