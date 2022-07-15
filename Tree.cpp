/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tree.cpp
 * Author: admin
 * 
 * Created on July 14, 2022, 12:33 PM
 */


#include <fstream>
#include "Tree.h"

using namespace std;

Tree::Tree() 
{
    rootNode = NULL;
    size = 0;
}

Tree::Tree(string inputFile)
{
    rootNode = NULL;
    size = 0;
    populateTree(inputFile);
}

Tree::Tree(const Tree& orig) 
{
    
}

Tree::~Tree() 
{
    while (rootNode != NULL)
        deleteNode(rootNode->getTitle());
}

void Tree::runTests()
{
    if (rootNode != NULL)
    {
        
        cout << "Deleting random nodes until size = 50" << endl;
        while (size > 50)
        {
            srand(time(NULL));
            deleteNode(grabRandomTitle(rand()%13, rootNode));
        }
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting random nodes until size = 5" << endl;
        while (size > 5)
            deleteNode(grabRandomTitle(rand()%5, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting random nodes until size = 4" << endl;
        while (size > 4)
            deleteNode(grabRandomTitle(rand()%5, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting random nodes until size = 3" << endl;
        while (size > 3)
            deleteNode(grabRandomTitle(rand()%3, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting random nodes until size = 2" << endl;
        while (size > 2)
            deleteNode(grabRandomTitle(rand()%2, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting random nodes until size = 1" << endl;
        while (size > 1)
            deleteNode(grabRandomTitle(rand()%1, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
        
        srand(time(NULL));
        cout << "Deleting last node" << endl;
        while (size > 0)
            deleteNode(grabRandomTitle(rand()%2, rootNode));
        cout << "Printing tree..." << endl;
        printTree();
        cout << endl;
    }
    else 
    {
        cout << "Empty tree, tests cannot be run until tree is populated with at least one film" << endl << endl;
    }
}

string Tree::grabRandomTitle(int remainingSteps, TreeNode* currNode)
{
    if (remainingSteps<1)
    {
        if (currNode != NULL)
        {
            return currNode->getTitle();
        }
        else 
        {
            return grabRandomTitle(0, rootNode);
        }
    }    
    else 
    {
        int tempRand = rand()%3;
        if (currNode == NULL)
        {
            return grabRandomTitle(remainingSteps-1, rootNode);
        }
        else if (tempRand > 0)
        {
            return grabRandomTitle(remainingSteps-1, currNode->getLeft());
        }
        else {
            return grabRandomTitle(remainingSteps-1, currNode->getRight());
        } 

    }
    return "*************** error in grabRandomTitle ***********************";
}

int Tree::getSize()
{
  return size;  
}

void Tree::insertNode(TreeNode* newNode)
{
    if (rootNode == NULL)
    {
        rootNode = newNode; 
        size++;
    }
    else insertNodeRecursive(rootNode, newNode);
}

void Tree::insertNodeRecursive(TreeNode* parentNode, TreeNode* newNode)
{
    if (newNode->getTitle().compare(parentNode->getTitle()) < 0)
    {
        if (parentNode->getLeft()==NULL)
        {
            parentNode->setLeft(newNode);
            size++;
        }            
        else insertNodeRecursive(parentNode->getLeft(), newNode);
    }
    else if (newNode->getTitle().compare(parentNode->getTitle()) > 0)
    {
        if (parentNode->getRight()==NULL)
        {            
            parentNode->setRight(newNode);
            size++;
        }
        else insertNodeRecursive(parentNode->getRight(), newNode);
    }
    else if (newNode->getTitle()==parentNode->getTitle())
    {
        cout << "Warning: attempting to add duplicate data entry for key: \"" << 
                newNode->getTitle() << "\", already exists...exiting process." << endl;
    }        
    else
    {
        cout << "Error, not able to add entry for key: \"" << newNode->getTitle() 
                << "\"...returning to menu." << endl;        
    }
}

void Tree::printTree()
{
    if (rootNode == NULL)
    {
        cout << "****************************************************************************" << endl;
        cout << "Empty tree, nothing to print!" << endl;
        cout << "****************************************************************************" << endl;
    }        
    else 
    {
        cout << "****************************************************************************" << endl;
        printTree(rootNode);
        cout << "****************************************************************************" << endl;
    }
}

void Tree::printTree(TreeNode* rootNode)
{
    if (rootNode == NULL)
        return;
    
    printTree(rootNode->getLeft());
    cout << rootNode->getTitle() << endl;
    printTree(rootNode->getRight());
}

void Tree::searchNode(string title)
{
    TreeNode* tempNode = rootNode;
    if (tempNode != NULL && tempNode->getTitle() != title)
    {
        tempNode = searchNodeRecursive(tempNode, title);
    }
    
    if (tempNode == NULL)
    {
        cout << "Film not found!" << endl;
        cout << endl;
    }
    else 
    {
        cout << "Film found! Details:" << endl << endl;
        tempNode->print();
        cout << endl;
    }
    
}

bool Tree::deleteNode(string title)
{
    bool successfulDelete = false;
    
    if (rootNode != NULL)
    {
        if (rootNode->getTitle() == title)
        {
            if (rootNode->getRight()==NULL && rootNode->getLeft() == NULL)
            {                
                TreeNode* tempNode = rootNode;
                rootNode = NULL;
                delete tempNode;
                successfulDelete = true;
            }
            else if (rootNode->getLeft() == NULL)
            {
                TreeNode* tempNode = rootNode;
                rootNode = rootNode->getRight();
                delete tempNode;
                successfulDelete = true;
            }
            else if (rootNode->getRight() == NULL)
            {
                TreeNode* tempNode = rootNode;
                rootNode = rootNode->getLeft();
                delete tempNode;
                successfulDelete = true;
            }
            else 
            {
                if (rootNode->getRight()->getLeft()==NULL)
                {
                    TreeNode* tempNode = rootNode;
                    rootNode = rootNode->getRight();
                    rootNode->setLeft(tempNode->getLeft());
                    delete tempNode;
                    successfulDelete = true;
                }
                else
                {
                    TreeNode* tempNode = getLeftMostChildCut(rootNode->getRight()->getLeft(), rootNode->getRight());
                    tempNode->setLeft(rootNode->getLeft());
                    tempNode->setRight(rootNode->getRight());
                    TreeNode* tempNode2 = rootNode;
                    rootNode = tempNode;
                    delete tempNode2;
                    successfulDelete = true;
                }
            }
        }
        //root node isnt null at this point but also isnt a match
        else
        {
            if (title.compare(rootNode->getTitle()) < 0)
            {
                if (rootNode->getLeft() != NULL)
                {
                    successfulDelete = deleteNode(rootNode->getLeft(), rootNode, true, title);
                }
            }
            else
            {
                if (rootNode->getRight() != NULL)
                {
                    successfulDelete = deleteNode(rootNode->getRight(), rootNode, false, title);
                }
            }
        }
    }  
    else
    {
        cout << "Empty database, nothing to delete!" << endl;
    }
    if (successfulDelete)
        size--;
    return successfulDelete;
}

bool Tree::deleteNode(TreeNode* parentNode, TreeNode* parentParentNode, bool amLeftChild, string title)
{
    if (title.compare(parentNode->getTitle()) == 0)
    {
        //delete here
        if (parentNode->getLeft() != NULL && parentNode->getRight() != NULL)
        {   
            TreeNode* tempNode = NULL;
            //    Find successor: Leftmost child in parentNodes right subtree.
            if (parentNode->getRight()->getLeft() != NULL)
            {
                tempNode = getLeftMostChildCut(parentNode->getRight()->getLeft(), parentNode->getRight());
                tempNode->setRight(parentNode->getRight());
                tempNode->setLeft(parentNode->getLeft());
                
            }
            else 
            {
                tempNode = parentNode->getRight();
                tempNode->setLeft(parentNode->getLeft());
            }
            
            //    Copy successor to current node.            
            
            if(amLeftChild)
            {
                parentParentNode->setLeft(tempNode);
            }
            else
            {
                parentParentNode->setRight(tempNode);
            }
            //    Remove successor from right subtree.
            delete parentNode;
            return true;
        }
        else if (parentNode->getLeft() == NULL && parentNode->getRight() == NULL)
        {
            if(amLeftChild)
            {
                parentParentNode->setLeft(NULL);
            }
            else
            {
                parentParentNode->setRight(NULL);
            }
            delete parentNode;
            return true;
        }
        else
        {
            //case for left child is null
            if (parentNode->getLeft() == NULL)
            {
                if(amLeftChild)
                {
                    parentParentNode->setLeft(parentNode->getRight());
                }
                else
                {
                    parentParentNode->setRight(parentNode->getRight());
                }               
            }
            
            //case for right child is null
            else
            {
                if(amLeftChild)
                {
                    parentParentNode->setLeft(parentNode->getLeft());
                }
                else
                {
                    parentParentNode->setRight(parentNode->getLeft());
                }               
            }
            delete parentNode;
            return true;
        }
    }
    else if (title.compare(parentNode->getTitle()) < 0)
    {
        if (parentNode->getLeft() != NULL)
            return deleteNode(parentNode->getLeft(), parentNode, true, title);
    }
    else if (title.compare(parentNode->getTitle()) > 0)
    {
        if (parentNode->getRight() != NULL)
            return deleteNode(parentNode->getRight(),parentNode, false, title);
    }
    return false;
}

TreeNode* Tree::getLeftMostChildCut(TreeNode* rootNode, TreeNode* rootParent)
{
    if (rootNode == NULL)
        return NULL;
    
    else if (rootNode->getLeft()==NULL)
    {
        if (rootNode->getRight() == NULL)
        {
            rootParent->setLeft(NULL);
            return rootNode;  
        }
        else 
        {
            rootParent->setLeft(rootNode->getRight());
            return rootNode;
        }
    }          
    else 
    {
        return getLeftMostChildCut(rootNode->getLeft(), rootNode);
    }
}

TreeNode* Tree::searchNodeRecursive(TreeNode* parentNode, string title)
{
    if (title.compare(parentNode->getTitle()) == 0)
    {
        return parentNode;
    }
    else if (title.compare(parentNode->getTitle()) < 0)
    {
        if (parentNode->getLeft() != NULL)
            return searchNodeRecursive(parentNode->getLeft(), title);
    }
    else if (title.compare(parentNode->getTitle()) > 0)
    {
        if (parentNode->getRight() != NULL)
            return searchNodeRecursive(parentNode->getRight(), title);
    }
    return NULL;
}

bool Tree::populateTree(string inputFile)
{
    int firstIndexAfterComma = 0;
    int currCommaIndex = 0;
    string inputString = "";
    
    string platform = "";
    string title = "";
    int releaseDate = 0;
    string rating = "";
    string categoryKeyWords = "";
    string description = "";
    
    ifstream infile;
    infile.open(inputFile);
    
    if(infile.fail())
    {
        cout << "Open file failed... exiting now.\n" << endl;
    }
    while(infile.peek() != EOF)
    {
        platform = "";
        title = "";
        releaseDate = 0;
        rating = "";
        categoryKeyWords = "";
        description = "";
        
        firstIndexAfterComma = 0;
        currCommaIndex = 0;
        getline(infile, inputString);
        
        //find first comma which will be after 'platform' string
        currCommaIndex = inputString.find(',');
        platform = inputString.substr(firstIndexAfterComma, currCommaIndex);        
        firstIndexAfterComma = currCommaIndex+1;
        
        //use index after first comma as start of second token, 'title' and up to following comma
        currCommaIndex = inputString.find(',', firstIndexAfterComma);        
        title = inputString.substr(firstIndexAfterComma, currCommaIndex-firstIndexAfterComma);
        firstIndexAfterComma = currCommaIndex+1;
        
        //same logic as above plus catch block for bad input data that can't be parsed as an int
        currCommaIndex = inputString.find(',', firstIndexAfterComma);
        try
        {
            releaseDate = stoi(inputString.substr(firstIndexAfterComma, currCommaIndex-firstIndexAfterComma));
        }
        catch (const std::invalid_argument& exception) 
        {
            cerr << "Invalid argument: " << exception.what() << endl;
            releaseDate = -1;
            continue;
        }
        firstIndexAfterComma = currCommaIndex+1;
        
        //same logic of walking indexes to get 'rating'
        currCommaIndex = inputString.find(',', firstIndexAfterComma);
        rating = inputString.substr(firstIndexAfterComma, currCommaIndex-firstIndexAfterComma);        
        firstIndexAfterComma = currCommaIndex+1;
        
        //same logic as above for 'categoryKeyWords'
        currCommaIndex = inputString.find(',', firstIndexAfterComma);
        categoryKeyWords = inputString.substr(firstIndexAfterComma, currCommaIndex-firstIndexAfterComma);        
        firstIndexAfterComma = currCommaIndex+1;
        
        //final token 'description' uses the entire input line size as the final end index
        currCommaIndex = inputString.length();
        description = inputString.substr(firstIndexAfterComma, currCommaIndex-firstIndexAfterComma);
        
        //call constructor for new Streaming object, assign to pointer, add pointer to vector
        TreeNode* newTreeNode = new TreeNode(platform, title, releaseDate, rating, 
                categoryKeyWords, description, NULL, NULL);
        //add node to tree
        insertNode(newTreeNode);
    }
    infile.close();
    return true;
}


