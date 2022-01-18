#include "Node.h"
#include <iostream>
#include <string>
#ifndef BinTree_h_
#define BinTree_h_

template <typename T> 
class BinTree
{
    private:
        Node<T>* root;
        
    public:
        BinTree(){root = nullptr;}
        BinTree(Node<T>* n){root = n;}
        void setRoot(Node<T>* r){root = r;}
        Node<T>* getRoot(){return root;}
        Node<T>* insert(Node<T>* n){return insert(root,n);} // helper function for insert method 
        Node<T>* insert(Node<T>*, Node<T>*);
        void ascSort(){ascSort(root);}//helper function for ascending sort method 
        void ascSort(Node<T>*);
        void desSort(){desSort(root);}//helper function for descending sort method 
        void desSort(Node<T>*);
        Node<T>* search(std::string str){return search(root,str);}//helper function for search method         
        Node<T>* search(Node<T>*,std::string);
        Node<T>* getMin(Node<T>*);
        Node<T>* removeNode(T key){return removeNode(root,key);} //helper function for remove method 
        Node<T>* removeNode(Node<T>*, T);
        int getHeight(){return getHeight(root);} //helper function for getHeight method 
        int getHeight(Node<T>*);
};
#endif

//inserts a node into the BST
template <typename T> 
Node<T>* BinTree<T>::insert(Node<T>* n1, Node<T>* n2)
{
    if(!n1) //if the root node is null return the inserted node 
    {
        return n2; 
    }
    if (n2->getData() < n1->getData()) //if the root node is is greater than the inserted node, go left 
    {
        n1->setLeft(insert(n1->getLeft(), n2));
    }
    else //if the root node is is less than the inserted node, go right 
    {
        n1->setRight(insert(n1->getRight(), n2));
    }
    return n1;
}
 
 
//displays the nodes in a BST in ascending order
template <typename T> 
void BinTree<T>::ascSort(Node<T>* n)
{
    if (!n) 
        return;
    ascSort(n->getLeft());
    std::cout << *n << std::endl;
    ascSort(n->getRight());
}

//displays the nodes in a BST in descending order
template <typename T> 
void BinTree<T>::desSort(Node<T>* n)
{
    if (!n) 
        return;
    desSort(n->getRight());
    std::cout << *n << std::endl;
    desSort(n->getLeft());
    
}

//searches for a given string within the BST 
template <typename T> 
Node<T>* BinTree<T>::search(Node<T>* n, std::string str)
{
    if (n == nullptr || n->getData() == str) // if the string is found or null, return the node 
    {
        return n;
    }
    if (n->getData() > str) // if the node's data is greater than the key, go left
        return search(n->getLeft(), str);
    else // if the node's data is less than the key, go right
        return search(n->getRight(), str);
    
}


//gets the minimum node within the tree starting from a given node
template <typename T> 
Node<T>* BinTree<T>::getMin(Node<T>* n)
{
    Node<T>* cur = n;

    while (cur && cur->getLeft() != nullptr)
        cur = cur->getLeft();
    return cur;
}

//removes a node from the BST 
template <typename T> 
Node<T>* BinTree<T>::removeNode(Node<T>* n, T key)
{
    if (n == nullptr)//if the root is null, return 
        return n;
        
    if (n->getData() > key) // if the root's data is greater than the key, go left 
    {
        n->setLeft(removeNode(n->getLeft(), key));
    }
    else if (n->getData() < key)// if the root's data is less than the key, go right
    {
        n->setRight(removeNode(n->getRight(), key));
    }
    else //if the node matches the key 
    {
        if (n->getLeft()==nullptr && n->getRight()==nullptr) // if the node has no children, delete node and return null 
        {
            if(n == root) // if the node is the root, sets the root to null  
            {
                root = nullptr;
            }
            delete n;
            return nullptr;
            
        }

        else if (n->getLeft() == nullptr) //if the node has only a right child, delete the node and replace it with the right child 
        {
            Node<T>* temp = n->getRight();
            if(n==root)
                root = temp;
            delete n;
            return temp;
        }
        else if (n->getRight() == nullptr) //if the node has only a left child, delete the node and replace it with the left child 
        { 
            Node<T>* temp = n->getLeft();
            if(n==root)
                root = temp;
            delete n;
            return temp;
        }
        
        //if the node has two children, replaces the node with the minimum value it its right subtree 
        Node<T>* temp = getMin(n->getRight());
        n->setData(temp->getData());
        n->setRight(removeNode(n->getRight(), temp->getData()));
    }
    return n;
}

//get the height of the tree 
template <typename T> 
int BinTree<T>::getHeight(Node<T>* n)
{
    if (n == nullptr)
        return 0;
    else 
    {
        int lheight = getHeight(n->getLeft());
        int rheight = getHeight(n->getRight());
        if (lheight > rheight) 
            return (lheight + 1);
        else 
            return (rheight + 1);
        
    }
}




