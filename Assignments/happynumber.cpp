#include <iostream>
#include <set>
#include <cmath>

int pdiFunction(int number){
    int total = 0;
    while (number > 0){
        total = total + std::pow(number % 10, 2);
        number = number / 10;
    }
    return total;
}

bool isHappy(int number){
    std::set<int> seenNumbers;

    while (number > 1 && !seenNumbers.count(number)){
        seenNumbers.insert(number);
        number = pdiFunction(number);
    }
    return number == 1;
}

int main(){
    int userNum;

    std::cout << "Which number do you want to test? ";
    std::cin >> userNum;
    std::cout << std::endl;

    if (isHappy(userNum) == true){
        std::cout << userNum << " is happy!" << std::endl;
    }else{
        std::cout << userNum << " is unhappy!" << std::endl;
    }

    return 0;
}