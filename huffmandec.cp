// Alexander Stern
// acs4wq
// huffmandec.cpp


// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.
// ^ from CS2150 professors

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "hNode.h"
#include <vector>
#include <string.h>

using namespace std;

hNode* makeTree(vector<hNode*> v) {
  // take vector and make tree through traversal
  // create blank nodes along the way for parents
  // blank nodes will have char '~'

  hNode* topParent = new hNode('~', "");

  int size = v.size();
  for (int p = 0; p < size; p++) {
    hNode* current  = topParent;
    hNode* leaf = v[p];
    string ls = leaf->s;
    bool keepGoing = true;
    while (keepGoing) {
      char cur = ls[0];
      if (ls.length() == 1) {
	if (ls == "0") {
	  current->left = leaf;
	  keepGoing = false;
	}
	else {
	  current->right = leaf;
	  keepGoing = false;
	}
      } 
     
      else {
	if (cur == '0') {
	  if (current->left != NULL) {
	    current = current->left;
	    ls = ls.substr(1, ls.length() - 1);
	  }
	  else {
	    hNode* node = new hNode('~', "");
	    current->left = node;
	    current = node;
	    ls = ls.substr(1, ls.length() - 1);
	  }
	}
	else {
	  if (current->right != NULL) {
	    current = current->right;
	    ls = ls.substr(1, ls.length() - 1);
	  }
	  else {
	    hNode* node = new hNode('~', "");
	    current->right = node;
	    current = node;
	    ls = ls.substr(1, ls.length() - 1);
	  }
	}
      }
    }
  }
  return topParent;
}


int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes

    vector<hNode*> list;
    
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
	// make string character into char
	char c = character[0];

	hNode* node = new hNode(c, prefix);
	list.push_back(node);
	
    }

    // take vector of character, prefix nodes and make tree

    hNode* fullTree = makeTree(list);
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // set curr node to tree root
    hNode* currNode = fullTree;

    for (int k = 0; k < allbits.length(); k++) {
      char myChar = allbits[k];
      if (myChar == '0') {
	currNode = currNode->left;
      }
      else {
	currNode = currNode->right;
      }
      if (currNode->left == NULL) {
	cout << currNode->c;
	currNode = fullTree;
      }
	
    }
    cout << endl;
    
    // close the file before exiting
    file.close();
}
