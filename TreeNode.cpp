/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   TreeNode.cpp
 * Author: admin
 * 
 * Created on July 14, 2022, 12:25 PM
 */

#include "TreeNode.h"

TreeNode::TreeNode() 
{
    this->platform = "";
    this->title = "";
    this->releaseDate = -1;
    this->rating = "";
    this->categoryKeyWords = "";
    this->description = "";
    this->left = NULL;
    this->right = NULL;
}

TreeNode::TreeNode(string platform, string title, int releaseDate, string rating, string categoryKeyWords, 
        string description, TreeNode* left, TreeNode* right)
{
    this->platform = platform;
    this->title = title;
    this->releaseDate = releaseDate;
    this->rating = rating;
    this->categoryKeyWords = categoryKeyWords;
    this->description = description;
    this->left = left;
    this->right = right;
}

TreeNode::TreeNode(const TreeNode& orig) 
{
    
}

TreeNode::~TreeNode() 
{
    
}

void TreeNode::print()
{
    cout << "Title: " << title << endl;
    cout << "Platform: " << platform << endl;
    cout << "Release Date: " << releaseDate << endl; 
    cout << "Rating: " << rating << endl; 
    cout << "Category Key Words: " << categoryKeyWords << endl; 
    cout << "Description: " << description << endl;
}

void TreeNode::printShowChildren()
{
    cout << "Title: " << title << endl;
    cout << "Platform: " << platform << endl;
    cout << "Release Date: " << releaseDate << endl; 
    cout << "Rating: " << rating << endl; 
    cout << "Category Key Words: " << categoryKeyWords << endl; 
    cout << "Description: " << description << endl;
    cout << "Left Child: " << (left != NULL ?  left->getTitle() : "NULL") << endl;
    cout << "Right Child: " << (right != NULL ?  right->getTitle() : "NULL") << endl << endl;
}

string TreeNode::getTitle()
{
    return title;
}

void TreeNode::setLeft(TreeNode* treeNode)
{
    left = treeNode;
}

void TreeNode::setRight(TreeNode* treeNode)
{
    right = treeNode;
}

TreeNode* TreeNode::getLeft()
{
    return left;
}

TreeNode* TreeNode::getRight()
{
    return right;
}
