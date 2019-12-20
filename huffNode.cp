// Alexander Stern
// acs4wq
// huffNode.cpp

#include "huffNode.h"

using namespace std;

huffNode::huffNode() {
  c = 'a';
  freq = 0;
  left = NULL;
  right = NULL;
}

huffNode::huffNode(char newC) {
  c = newC;
  freq = 0;
  left = NULL;
  right = NULL;
}

huffNode::huffNode(char newC, int f) {
  c = newC;
  freq = f;
  left = NULL;
  right = NULL;
}

huffNode::~huffNode() {

}

