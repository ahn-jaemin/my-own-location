#ifndef BSTHEADER_H
#define BSTHEADER_H
#endif

class Node{
    public:
        Node();
        int getVal(){return value;}
    private:
        int value;
        int* ptrLeft;
        int* ptrRight;
};

    Node::Node(){
        ptrLeft = nullptr;
        ptrRight = nullptr;
    }