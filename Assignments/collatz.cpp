#include <iostream>

int main(){

    int numCollatz;
    int countRepeat = 0;

    std::cout << "Enter the first number of the sequence: ";
    std::cin >> numCollatz;
    std::cout << std::endl;

    while (countRepeat != 3){

        std::cout << numCollatz << " ";

        if (numCollatz == 1){
            countRepeat++;
        }

        if (numCollatz % 2 == 0){
            numCollatz = numCollatz / 2;
        }
        else {
            numCollatz = 3 * numCollatz + 1;
        }

    }

    std::cout << " ... " << std::endl;

    return 0;
}