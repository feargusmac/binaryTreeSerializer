/*
 * Source file for bTreeSerializer.h
 * 
 * Serialize a binary tree into a string and 
 * de-serialize a string back into a binary
 * tree.
 */

#include <iostream>
#include "bTreeSerializer.h"

bTreeLeaf *bTreeSerializer::makeLeaf(char c) {
    if (!isdigit(c))
        return NULL;
    
    int val = (int) (c - '0');
    
    bTreeLeaf *newLeaf = new bTreeLeaf;
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
    //std::cout << "in deserialize, made root" << std::endl;
    root = rdeserialize(treeString);
    //std::cout << "in deserialize, ran rdeserialize" << std::endl;
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
    bTreeSerializer *temp;
    bTreeLeaf *tree = temp->deserialize(str);
    printTree(tree);
}

void bTreeSerializer::serialize(bTreeLeaf *leaf, std::string &result) {
    if (leaf == NULL) {
        result += "X";
        return;
    }
    
    result += (char) (leaf->data +'0');
    serialize(leaf->left, result);
    serialize(leaf->right, result);
}

bTreeLeaf *bTreeSerializer::rdeserialize(std::string &str) {
    //std::cout << "in rdeserialize" << std::endl;
    //if (str.length() == 0) return NULL;
    if (!isdigit(str[0])) {
        str = str.substr(1);
        return NULL; 
    }
    bTreeLeaf *newLeaf = new bTreeLeaf;
    newLeaf = makeLeaf(str[0]);
    if (str.length() > 1) 
        str = str.substr(1);
    else if (str.length() == 1)
        str = "";
    std::cout << str << std::endl;
    //std::cout << "in rdeserialize, made new leaf" << std::endl;
 
    newLeaf->left = rdeserialize(str);
    //std::cout << "made left leaf" << std::endl;
    newLeaf->right = rdeserialize(str);
    //std::cout << "made right leaf" << std::endl;
    
    return newLeaf;
}

