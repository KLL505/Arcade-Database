#include <iostream>
#ifndef Node_h_
#define Node_h_

template <typename T> 
class Node
{
    private:
        T data;
        Node<T> *left; 
        Node<T> *right;
    
    public:

        Node(){data = NULL;}
        Node(T d){data = d; left = nullptr; right = nullptr;}
        void setData(T d){data = d;}
        void setLeft(Node<T>* n){left = n;}
        void setRight(Node<T>* p){right = p;}
        T getData(){return data;}
        Node<T>* getLeft(){return left;}
        Node<T>* getRight(){return right;}
        bool operator== (Node<T> n){return (data == n.data && left == n.left && right == n.right)?true:false;}
        bool operator!= (Node<T> n){return (data != n.data || left != n.left || right != n.right)?true:false;}
        bool operator> (Node<T> n){return (data > n.data)?true:false;}
        bool operator< (Node<T> n){return (data < n.data)?true:false;}
        friend std::ostream& operator<<(std::ostream& out, Node<T>& n){out << n.data; return out;}
    
};
#endif