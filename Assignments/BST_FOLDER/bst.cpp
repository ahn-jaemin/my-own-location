#include <vector>
#include <iostream>
#include "bstHeader.h"

int main(){
    BST myBST;
    int temp;
    int searchNum;
    int heightTree;
    std::vector<int> sortedNums;

    myBST.insertKey(6);
    if (myBST.hasKey(6)){
        std::cout << "yes!" << std::endl;
    }else{
        std::cout << "no.." << std::endl;
    }

    return 0;
}