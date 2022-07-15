/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tree.h
 * Author: admin
 *
 * Created on July 14, 2022, 12:33 PM
 */

#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

class Tree {
public:
    Tree();
    Tree(string inputFile);
    Tree(const Tree& orig);
    virtual ~Tree();
    void insertNode(TreeNode* newNode);
    bool deleteNode(string title);
    void searchNode(string title);
    void printTree();
    int getSize();
    
    void runTests();
    
    
private:
    TreeNode* rootNode;
    int size;
    string grabRandomTitle(int remainingSteps, TreeNode* treeNode);
    TreeNode* searchNodeRecursive(TreeNode* parentNode, string title);
    TreeNode* searchNodeWithParentRecursive(TreeNode* parentParentNode, string title);
    TreeNode* getLeftMostChildCut(TreeNode* rootNode, TreeNode* rootParent);
    void insertNodeRecursive(TreeNode* parentNode, TreeNode* newNode);
    bool populateTree(string inputFile);
    bool deleteNode(TreeNode* parentNode, TreeNode* parentParentNode, bool amLeftChild, string title);
    void printTree(TreeNode* rootNode);
};

#endif /* TREE_H */

