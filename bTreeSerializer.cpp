/*
 * Source file for bTreeSerializer.h
 */

#include <iostream>
#include "bTreeSerializer.h"

bTreeLeaf *bTreeSerializer::makeLeaf(std::string str, int idx) {
    if (idx >= str.length())
        return NULL;
    if (!isdigit(str[idx]))
        return NULL;
    
    bTreeLeaf *newLeaf = new bTreeLeaf;
    int val = (int) (str[idx] - '0');
    newLeaf->data = val;
    newLeaf->left = NULL;
    newLeaf->right = NULL;
    
    return newLeaf;
}

std::string bTreeSerializer::serialize(bTreeLeaf* root) {
    std::string result = "";
    
    serialize(root, result);
    return result;    
}

bTreeLeaf *bTreeSerializer::deserialize(std::string treeString) {
    bTreeLeaf *root = new bTreeLeaf;
    int val = (int) (treeString[0] - '0');
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    
    int index = 1;
    deserialize(root, treeString, index);
    
    return root;
}

void bTreeSerializer::printTree(bTreeLeaf* leaf) {
    if (leaf == NULL) {
        return;
    }
    
    std::cout << leaf->data << " ";
    printTree(leaf->left);
    printTree(leaf->right);
}

void bTreeSerializer::printTree(std::string str) {
    bTreeLeaf *tree = deserialize(str);
    printTree(tree);
}

void bTreeSerializer::serialize(bTreeLeaf *leaf, std::string &result) {
    if (leaf == NULL) {
        result += "X";
        return;
    }
    
    result += (char) (leaf->data -'0');
    serialize(leaf->left, result);
    serialize(leaf->right, result);
}

void bTreeSerializer::deserialize(bTreeLeaf *leaf, std::string str, int idx) {
    if (leaf == NULL || idx >= str.length()) return;
    
    bTreeLeaf *leftLeaf = makeLeaf(str, idx);
    leaf->left = leftLeaf;
    deserialize(leftLeaf, str, ++idx);
    
    bTreeLeaf *rightLeaf = makeLeaf(str, ++idx);
    leaf->right = rightLeaf;
    deserialize(rightLeaf, str, ++idx);
}

