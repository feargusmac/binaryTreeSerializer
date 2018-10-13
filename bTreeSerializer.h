/* 
 * File:   bTreeSerializer.h
 * Author: Feargus
 *
 * Created on October 12, 2018, 3:13 PM
 * 
 * Serialize a binary tree into a string and 
 * de-serialize a string back into a binary
 * tree.
 * 
 * TODO: Currently only works for single digit numbers
 */
#ifndef BTREESERIALIZER_H
#define BTREESERIALIZER_H

#include <string>

struct bTreeLeaf {
    bTreeLeaf *left;
    bTreeLeaf *right;
        
    int data;
};
    
class bTreeSerializer {
    
public:
    bTreeSerializer() {
        
    }
    
    ~bTreeSerializer() {
        
    }
    
    bTreeLeaf *makeLeaf(std::string, int);
    std::string serialize(bTreeLeaf*);
    bTreeLeaf *deserialize(std::string);
    void printTree(bTreeLeaf*);
    void printTree(std::string);
    
private:
    void serialize(bTreeLeaf*, std::string&);
    void deserialize(bTreeLeaf*, std::string, int);
    
};

#endif /* BTREESERIALIZER_H */

