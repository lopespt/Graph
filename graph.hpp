
#include "edge.hpp"
#include "node.hpp"
#include <functional>
#include <map>
#include <memory>
#include <vector>

using namespace std;

class Graph {
public:
  typedef reference_wrapper<Node> refNode;
  typedef reference_wrapper<Edge> refEdge;
  typedef const reference_wrapper<Node> crefNode;
  typedef const reference_wrapper<Edge> crefEdge;
  typedef map<pair<refNode, refNode>, refEdge,
              bool (*)(pair<refNode, refNode>, pair<refNode, refNode>)>
      edgeIndex;

public:
  vector<unique_ptr<Node>> nodes;
  vector<unique_ptr<Edge>> edges;
  edgeIndex edgesTo;
  // edgeIndex edgesFrom;

  static bool nodeLessThan(crefNode &a, crefNode &b) {
    return a.get().n < b.get().n;
  }
  static bool nodeKeysLessThan(const edgeIndex::key_type a,
                               const edgeIndex::key_type b) {
    if (!nodeLessThan(a.first, b.first) && !nodeLessThan(b.first, a.first))
      return nodeLessThan(a.second, b.second);

    return nodeLessThan(a.first, b.first);
  }

public:
  Graph() : edgesTo(&Graph::nodeKeysLessThan){};
  ~Graph(){};
  refNode addNode() {
    unique_ptr<Node> n(new Node());
    nodes.push_back(move(n));
    return *nodes.back();
  }

  Node &getNode(int index) {
    return *nodes[index];
  }

  vector<unique_ptr<Node>>::iterator begin() {
    return nodes.begin();
  }
  vector<unique_ptr<Node>>::iterator end() {
    return nodes.end();
  }

  Edge &addEdge(refNode a, refNode b) {
    unique_ptr<Edge> n(new Edge);
    edges.push_back(move(n));
    pair<refNode, refNode> key(a, b);
    // pair<edgeIndex::iterator, bool> res =
    edgesTo.insert(make_pair(key, refEdge(*edges.back())));
    return *edges.back();
  }

  edgeIndex::iterator getBeginEdgesIterator(crefNode n) {
    return edgesTo.lower_bound(edgeIndex::key_type(n, *nodes.front()));
  }
  edgeIndex::iterator getEndEdgesIterator(crefNode n) {
    return edgesTo.upper_bound(edgeIndex::key_type(n, *nodes.back()));
  }
};
