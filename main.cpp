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
    //cout << "here" << endl;
    bTreeLeaf *tree = new bTreeLeaf;
    //cout << "here" << endl;
    tree = serializer->deserialize(data);
    //cout << "tree made" << endl;
    
    bTreeSerializer::printTree(tree);
    cout << endl;
    //cout << tree->right->left->data << endl;
  
    string treeString = serializer->serialize(tree);
  
    cout << endl << treeString << endl;
  
    delete tree;
  
    return 0;
}

