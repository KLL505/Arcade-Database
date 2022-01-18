/******************************************************************************
Kenneth LY 
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <iomanip>
#include "Game.h"
#include "Node.h"
#include "BinTree.h"
using namespace std;

//the main Binary Search Tree that represents all the data of Cidercade 
BinTree<Game> BST;

//creates a game object from a given string and adds it into the the Binary search tree 
void add(string str)
{
    string name, highscore, initials,plays;
    auto index = str.rfind("\"");
    name = str.substr(1, index - 1);
    str.erase(0, name.length() + 3);
    istringstream iss (str);
    
    //parsing all the data from the string 
    iss >> highscore;
    iss >> initials;
    iss >> plays;
    Game g(name, stoi(highscore) ,initials, stoi(plays) );
    Node<Game>* n = new Node<Game>(g);
    
    //checks if the BST is empty and makes the inserted object the root if so 
    if(!BST.getRoot())
        BST.setRoot(BST.insert(n));
    else
        BST.insert(n);

}


//outputs the nodes withiin the current level 
template <typename T> 
void printLevel(Node<T>* n, int l, ofstream& out)
{
    if (n == nullptr)
        return;
    if (l == 1)
        out << n->getData() << endl;
    else if (l > 1) {
        printLevel(n->getLeft(), l - 1,out);
        printLevel(n->getRight(), l - 1,out);
    }
}

// breadth first transversal of a tree that goes to each level and outputs all the the nodes at that level 
void BreadthFirst()
{
    int h = BST.getHeight();
    int i;
    ofstream out("cidercade.dat");
    for (i = 1; i <= h; i++)
        printLevel(BST.getRoot(), i, out);
    out.close(); 
}

//converts all the data in the datafile to a string that can be parsed by the add method and added to the BST  
void ReadData(ifstream& input)
{
    if (input.is_open())
    {
        string line;
        while (getline (input, line))
        {
            //removes the "" around the name 
            auto index = line.find(",");
            line.insert(0, "\"");
            line.insert(index+1, "\"");
            
            //removes all the commas 
            while(line.find(",") != string::npos)
            {
                index = line.find(",");
                line.erase(index, 1);
            }
            
            //adds data to BST
            add(line);
        }
    }
}
 
int main()
{
    string dFile;
    string cFile;
    string line;
    
    //prompts suer for file names 
    cout << "ENTER DATA FILE:" << endl;
    cin >> dFile;
    cout << "ENTER COMMAND FILE:" << endl;
    cin >> cFile;
    //cFile = "update1.txt";
    //dFile = "cidercade1.bat";
    
    ifstream dInput (dFile);
    ReadData(dInput);
    ifstream cInput (cFile);
    if (cInput.is_open ())
    {
          while (getline (cInput, line))
          {
              string command;
              
              //checks the command number for the given line and removes it form the string 
              command = line[0]; 
              line = line.substr(2);
              if (command == "1") //adds a function to the BST
              {
                add(line); 
                cout << endl << endl;
              }
              else if (command == "2") //Searches BST for given term 
              {
                if(BST.search(line))
                {
                    cout << line << " FOUND" << endl;
                    BST.search(line)->getData().print();
                }
                else
                    cout << line << " NOT FOUND" << endl;
                cout << endl << endl;
              }
              else if (command == "3") //Edits a given value for a given term 
              {
                //gets the name of the object being edited 
                auto index = line.rfind("\"");
                string name = line.substr(1, index - 1);
                line.erase(0, name.length() + 3);
                
                if(BST.search(name))
                {
                    //creates a copy of the object from the BST 
                    Game g(BST.search(name)->getData());
                    
                    //checks which value is being updated 
                    command = line[0]; 
                    line = line.substr(2);
                    
                    //updates the value to the command 
                    cout << name << " UPDATED" << endl;
                    if(command == "1")
                    {
                        g.setHighScore(stoi(line));
                        cout << "UPDATE TO high score - VALUE " << line << endl;
                    }
                    if(command == "2")
                    {
                        g.setInitials(line);
                        cout << "UPDATE TO initials - VALUE " << line << endl;
                    }
                    if(command== "3")
                    {
                        g.setPlays(stoi(line));
                        cout << "UPDATE TO plays - VALUE " << line << endl;
                    }
                    
                    //changes the data for the object in the BST with the edited copy 
                    BST.search(name)->setData(g);
                    g.print(); 
                }
                cout << endl << endl;  
              }
              else if (command == "4") //Deletes a given record 
              {
                if(BST.search(line)) //searches to make sure data is within the BST 
                {
                    //creates a copy of the data beign deleted to use for the BST remove method 
                    Game g(BST.search(line)->getData());
                    BST.removeNode(g);
                    
                    cout << "RECORD DELETED" << endl;
                    cout << "Name: " << g.getName() << endl;
                    g.print();
                }
                else
                    cout << line << " NOT FOUND" << endl;
                cout << endl << endl;  
              }
              else if (command == "5") //displays the data in the BST by descending or ascending order 
              {
                if(line == "asc")
                {
                    cout << "RECORDS SORTED ASCENDING" << endl;
                    BST.ascSort(); 
                }
                else if(line == "des")
                {
                    cout << "RECORDS SORTED DESCENDING" << endl;
                    BST.desSort(); 
                }

                cout << endl << endl;
              }
              else
                continue;
          }
     cInput.close();
    }
    dInput.close();
    
    //outputs the BST to a file in a BreadthFirst transversal 
    BreadthFirst();
    return 0;
} 
