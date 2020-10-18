#ifndef BSTHEADER_H
#define BSTHEADER_H
#include "bstHeader.h"
#include <vector>

class BST{           
    public:
        BST();
        ~BST();

        void insertKey(int newKey);
        bool hasKey(int searchKey);
        std::vector<int> inOrder();
        int getHeight();
    private:
        int* root;
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    
}

void BST::insertKey(int newKey){
    if (root == NULL){
        root = new Node;
    }else{

    }
}

#endif