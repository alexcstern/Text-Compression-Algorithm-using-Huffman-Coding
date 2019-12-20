// Alexander Stern
// acs4wq
// hNode.h

#ifndef HNODE_H
#define HNODE_H

#include <iostream>
#include <string>

using namespace std;

class hNode {

 public:
  hNode();
  hNode(char c, string s);
  ~hNode();
  char c;
  string s;
  hNode* left;
  hNode* right;

};

#endif
