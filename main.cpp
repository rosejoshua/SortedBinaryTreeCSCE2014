/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on July 14, 2022, 12:24 PM
 */

#include "Tree.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string DEFAULT_FILENAME = "streaming-year.txt";
    string menuChoice = "";
    string tempString = "";
    
    cout << "Attempting to populate tree from file: \"" << DEFAULT_FILENAME << "\"..." << endl;
    Tree tree(DEFAULT_FILENAME);
    if (tree.getSize() > 0)
        cout << "Success! Tree contains " << tree.getSize() << " entries." << endl;
    
    while(menuChoice != "4") 
    {
        while (menuChoice != "1" && menuChoice != "2" && menuChoice != "3" && menuChoice != "4")
        {
            cout << "Please enter an option (1, 2, 3, or 4):" << endl;
            cout << "\t1. Search for film by title and print details" << endl;
            cout << "\t2. Delete film by title" << endl;
            cout << "\t3. Run tests to verify program functionality" << endl;
            cout << "\t4. Quit and print all film titles" << endl;
            cout << "\t>>";
            cin >> menuChoice;

            if (menuChoice == "4")
            {
                cout << "Printing entire list of films by title..." << endl;
                tree.printTree();
                cout << "Why don't you make like a tree, and get outta here!" << endl;
                break;
            }

            if (menuChoice != "1" && menuChoice != "2" && menuChoice != "3" && menuChoice != "4")
            {
                cout << "invalid input, please try again" << endl;
                continue;
            }

            if (menuChoice == "1")
            {   
                cin.ignore();
                tempString = "";
                cout << "Enter film title to search: " << endl;
                cout << "\t>>";
                cin.clear();
                getline(cin, tempString);
                cout << "Searching for : " << "\"" << tempString << "\"" << endl;
                tree.searchNode(tempString);
                menuChoice="";
            }
            else if (menuChoice == "2")
            {   
                cin.ignore();
                tempString = "";
                cout << "Enter film title to delete: " << endl;
                cout << "\t>>";
                cin.clear();
                getline(cin, tempString);
                
                bool success = tree.deleteNode(tempString);
                if (success)
                {
                    cout << "Successfully deleted film titled: " << tempString << endl;
                    cout << "Remaining films in database: " << tree.getSize() << endl << endl;
                }
                
                menuChoice="";
            }
            else if (menuChoice == "3")
            {   
                tree.runTests();
                menuChoice="";
            }
        }
    }
    return 0;
}

