#include <iostream>
#include <fstream>

int output(){
    std::ofstream outFS;

    outFS.open("myoutfile2.txt");

    if (!outFS.is_open()){
        std::cout << "Could not open file myoutfile.txt." << std::endl;
        return 1;
    }

    outFS << "Hello" << std::endl;
    outFS << "1 2 3" << std::endl;

    outFS.close();

    return 0;
}

int input(){
    std::ifstream inFS;
    int fileNum1, fileNum2;

    inFS.open("myoutfile.txt");
    if (!inFS.is_open()){
        std::cout << "Could not open." << std::endl;
        return 1;
    }

    inFS >> fileNum1;
    inFS >> fileNum2;

    inFS.close();

    std::cout << fileNum1 << std::endl;
    std::cout << fileNum2 << std::endl;

    return 0;
}

int main(){
    input();

    return 0;
}