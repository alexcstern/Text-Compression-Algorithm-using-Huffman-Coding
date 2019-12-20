// Alexander Stern
// acs4wq
// huffmanenc.cpp

// ideas used from fileio.cpp from CS2150 professors

#include "heap.h"
#include "huffNode.h"
#include "vecNode.h"
#include <stdio.h>

int main(int argc, char **argv) {
  if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
  }

  FILE *fp = fopen(argv[1], "r");

  if ( fp == NULL ) {
      cout << "File '" << argv[1] << "' does not exist!" << endl;
      exit(2);
  }

  char g;


  vector<int> counts;
  vector<char> letters;
    
  while ( (g = fgetc(fp)) != EOF ){
    bool found = false;
    if (g == '\n' || g == '\t' || g == '\r') {
      found = true;
    }
    for (int i = 0; i < letters.size(); i++) {
      if (letters[i] == g) {
	counts[i] = counts[i] + 1;
        found = true;
      }
    }
    if (!found) {
      letters.push_back(g);
      counts.push_back(1);
    }
  }


  huffHeap heap;

  for (int i = 0; i < letters.size(); i++) {
    int f = counts[i];
    char c = letters[i];
    huffNode *node = new huffNode(c, f);
    heap.insert(node);
  }

  huffNode* tree = heap.buildHuffman();
  vector<vecNode*> lookup = heap.getCodes(tree, letters);

  for (int i = 0; i < lookup.size(); i++) {
    if ((lookup[i])->c != ' ') {
      cout << (lookup[i])->c << " " << (lookup[i])->s << endl;
    }
    else {
      cout << "space" << " " << (lookup[i])->s << endl;
    }
  }

  cout << "----------------------------------------" << endl;

  string fullString = "";
  int white = 0;
  int symbols = 0;
  rewind(fp);
  while ( (g = fgetc(fp)) != EOF ) {
    if (g != '\n') {
      fullString += heap.getString(g, lookup);
      fullString += " ";
      symbols++;
      white++;
    }
  }
  cout << fullString << endl;

  cout << "----------------------------------------" << endl;

  cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
  cout << "There were " << lookup.size() << " distinct symbols used." << endl;
  cout << "There were " << (symbols * 8) << " bits in the original file." << endl;
  cout << "There were " << (fullString.length() - white) << " bits in the compressed file." << endl;
  float cRatio = (float)(symbols * 8) / (fullString.length() - white);
  cout << "This gives a compression ratio of " << cRatio << "." << endl;
  float hRatio = (fullString.length() - white) / (float)(symbols);
  cout << "The cost of the Huffman tree is " << hRatio << " bits per character." << endl;


  fclose(fp);

  return 0;
}
