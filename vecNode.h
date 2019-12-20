// Alexander Stern
// acs4wq
// vecNode.h

#ifndef VECNODE_H
#define VECNODE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vecNode {
 public:
  vecNode();
  vecNode(char c, string s);
  ~vecNode();
  string s;
  char c;

};

#endif
