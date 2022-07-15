/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   TreeNode.h
 * Author: admin
 *
 * Created on July 14, 2022, 12:25 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    TreeNode();
    TreeNode(string platform, string title, int releaseDate, string rating, string categoryKeyWords, 
        string description, TreeNode* left, TreeNode* right);
    TreeNode(const TreeNode& orig);
    virtual ~TreeNode();    
    void print();
    void printShowChildren();
    string getTitle();
    void setLeft(TreeNode* treeNode);
    void setRight(TreeNode* treeNode);
    
    TreeNode* getLeft();
    TreeNode* getRight();
    
private:
    string platform;
    string title;
    int releaseDate;
    string rating;
    string categoryKeyWords;
    string description;
    TreeNode* left;
    TreeNode* right;
};

#endif /* TREENODE_H */

