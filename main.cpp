/* 
 * File:   main.cpp
 * Author: Feargus
 *
 * Serialize a binary tree into a string and 
 * de-serialize a string back into a binary
 * tree.
 * 
 */

#include <cstdlib>
#include <iostream>
#include "bTreeSerializer.h"

using namespace std;

/*
 * 
 */
int main() {
    string data = "174XX3XX56XX2XX";
    
    bTreeSerializer *serializer = new bTreeSerializer();
  
    bTreeLeaf *tree = new bTreeLeaf;
    tree = serializer->deserialize(data);
  
    bTreeSerializer::printTree(tree);
    cout << endl;
    //cout << tree->left->left->right->data << endl;
  
    //string treeString = serialize(tree);
  
    //cout << endl << treeString << endl;
  
    delete tree;
    return 0;
  
    return 0;
}

