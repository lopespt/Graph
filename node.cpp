/*
 * node.cpp
 * Copyright (C) 2016 lopespt <lopespt@arch>
 *
 * Distributed under terms of the MIT license.
 */

#include "node.hpp"

int Node::actual_n = 0;

Node::Node() : n(Node::actual_n) {
  Node::actual_n++;
}

Node::~Node() {}
