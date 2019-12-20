// Alexander Stern
// acs4wq
// huffNode.h

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class huffNode {

 public:
  huffNode();
  huffNode(char newC);
  huffNode(char newC, int f);
  ~huffNode();
  char c;
  int freq;
  huffNode* left;
  huffNode* right;


};

#endif
