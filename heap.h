// Alexander Stern
// acs4wq
// heap.h

// ideas used from binary heap class provided by the CS2150 professors

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "huffNode.h"
#include "vecNode.h"

using namespace std;

class huffHeap {

 public:
  huffHeap();
  ~huffHeap();
  vector<huffNode*> heap;
  unsigned int size();
  unsigned int heap_size;
  void percolateUp(int hole);
  void percolateDown(int hole);
  void makeEmpty();
  bool isEmpty();
  void insert(huffNode* h);
  void print();
  huffNode* deleteMin();
  huffNode* buildHuffman();
  vector<vecNode*> getCodes(huffNode* h, vector<char> letters);
  vecNode* writeCodes(huffNode* h, char c);
  bool find(huffNode* h, char c);
  string getString(char c, vector<vecNode*> v);
  
  

 private:
  


};

#endif
