#include "bstHeader.h"
#include <vector>

class BST{           
    public:
        BST();
        BST(int newKey);
        ~BST();     //NO MEMORY LEAKS!
        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int getHeight();
    private:
        Node* root;
        //void insertHelper(Node*& root);

};

    BST::BST(){
        root = nullptr;
    }

    BST::BST(int newKey){
    
    }

    BST::~BST(){

    }

    void BST::insertKey(int newKey){
        //if tree empty: create root node
        //else 
            //search for empty subtree where key should be stored
            //create new node at location and link parent to this child
        if (root == NULL){
            *root = new Node;
        }

    }

    bool BST::hasKey(int searchKey){
        //if tree empty: search fails
        //else
            //if key = key of root node: found
            //if key < key of root node: search left ree
            //if key > key of root node: search right tree

    }

    std::vector<int> BST::inOrder(){

    }

    int BST::getHeight(){

    }