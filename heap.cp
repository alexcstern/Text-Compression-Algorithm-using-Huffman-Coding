// Alexander Stern
// acs4wq
// heap.cpp

// methods and ideas used from binary heap class provided by CS2150 professors

#include "heap.h"
#include "huffNode.h"
#include "vecNode.h"
#include <typeinfo>

using namespace std;

huffHeap::huffHeap() : heap_size(0) {
  heap.push_back(0);
}

huffHeap::~huffHeap() {

}

void huffHeap::insert(huffNode* h) {
  heap.push_back(h);
  // re-adjust heap
  percolateUp(++heap_size);
}

void huffHeap::percolateUp(int hole) {
  // get Node
  huffNode* holeNode = heap[hole];
  for ( ; (hole > 1) && (holeNode->freq < (heap[hole/2])->freq); hole /= 2) {
    heap[hole] = heap[hole/2];
    // move parent down
  }
  heap[hole] = holeNode;
}

huffNode* huffHeap::deleteMin() {
  // make sure the heap is not empty
  if ( heap_size == 0 )
      throw "deleteMin() called on empty heap";
  // save the value to be returned
  huffNode* ret = heap[1];
  // move the last inserted position into the root
  heap[1] = heap[heap_size--];
  // make sure the vector knows that there is one less element
  heap.pop_back();
  // percolate the root down to the proper position
  percolateDown(1);
  // return the old root node
  return ret;
}

void huffHeap::percolateDown(int hole) {
  // get the value to percolate down
  huffNode* x = heap[hole];
  // while there is a left child...
  while ( hole*2 <= heap_size ) {
    int child = hole*2; // the left child
    // is there a right child?  if so, is it lesser?
    if ((child+1 <= heap_size) && ((heap[child+1])->freq < (heap[child])->freq))
      child++;
      // if the child is greater than the node...
    if ( x->freq > (heap[child])->freq ) {
      heap[hole] = heap[child]; // move child up
      hole = child;             // move hole down
    }
    else
      break;
  }
  // correct position found!  insert at that spot
  heap[hole] = x;
}

huffNode* huffHeap::buildHuffman() {
  // requires heap_size - 1 parent nodes to be created
  int h = heap_size;
  for (int i = 1; i < h; i++) {
    huffNode* one = deleteMin();
    huffNode* two = deleteMin();
    int f = one->freq + two->freq;
    huffNode* parent = new huffNode('~', f);
    parent->left = one;
    parent->right = two;
    // put tree back into heap
    insert(parent);
  }
  return heap[1];
}

vector<vecNode*> huffHeap::getCodes(huffNode* h, vector<char> letters) {
  vector<vecNode*> vec;
  for (int i = 0; i < letters.size(); i++) {
    vecNode* node = writeCodes(h, letters[i]);
    vec.push_back(node);
  }
  return vec;
}

vecNode* huffHeap::writeCodes(huffNode* h, char c) {
  string s = "";
  while (find(h->left, c) || find(h->right, c)) {
    if (find(h->left, c)) {
      s += "0";
      h = h->left;
    }
    else {
      s += "1";
      h = h->right;
    }
  }
  vecNode* node = new vecNode(c, s);
  
  return node;
}

bool huffHeap::find(huffNode* h, char c) {
  if (h == NULL) {
    return false;
  }
  else if (h->c == c) {
    return true;
  }
  else {
    return find(h->left, c) || find(h->right, c);
  }
}

string huffHeap::getString(char c, vector<vecNode*> v) {
  for (int i = 0; i < v.size(); i++) {
    if ((v[i])->c == c) {
      return (v[i])->s;
    }
  }
}


void huffHeap::print() {
  for (int i = 1; i <= heap_size; i++) {
    cout << (heap[i])->c << endl;
  }
}
