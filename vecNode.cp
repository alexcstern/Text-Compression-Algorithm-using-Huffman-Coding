// Alexander Stern
// acs4wq
// vecNode.cpp

#include "vecNode.h"

using namespace std;

vecNode::vecNode() {
  s = "";
  c = 'a';
}

vecNode::vecNode(char newC, string newS) {
  s = newS;
  c = newC;
}

vecNode::~vecNode() {

}
