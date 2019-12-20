// Alexander Stern
// acs4wq
// hNode.cpp

#include "hNode.h"

using namespace std;

hNode::hNode() {
  c = 'a';
  s = "";
  left = NULL;
  right = NULL;
  
}

hNode::hNode(char newC, string newS) {
  c = newC;
  s = newS;
  left = NULL;
  right = NULL;
}

hNode::~hNode() {

}
