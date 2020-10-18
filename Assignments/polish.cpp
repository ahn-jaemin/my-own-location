#include <iostream>

int main(){

    char charOperator;
    int caseOperator;
    double numFirst = 0;
    double numSecond = 0;
    int endLoop = 0;

    while (endLoop == 0){

        std::cout << "Enter the expression: ";
        std::cin >> charOperator;
        std::cin >> numFirst;
        std::cin >> numSecond; 
        std::cout << std::endl;

        if (charOperator == '+'){
            caseOperator = 1;
        }
        if (charOperator == '-'){
            caseOperator = 2;
        }
        if (charOperator == '*'){
            caseOperator = 3;
        }
        if (charOperator == '/'){
            caseOperator = 4;
        }
        if (charOperator == 'q'){
            caseOperator = 5;
        }

        switch (caseOperator){
            case 1:
                std::cout << numFirst << " + " << numSecond << " = " << (numFirst + numSecond) << std::endl;
                break;
            case 2:
                std::cout << numFirst << " - " << numSecond << " = " << (numFirst - numSecond) << std::endl;
                break;
            case 3:
                std::cout << numFirst << " * " << numSecond << " = " << (numFirst * numSecond) << std::endl;
                break;
            case 4:
                std::cout << numFirst << " / " << numSecond << " = " << (numFirst / numSecond) << std::endl;
                break;
            case 5:
                endLoop = 1;
                break;
            default:
                std::cout << "Sorry, I didn't understand that. Enter an operator, followed by two numbers, or press q to exit." << std::endl;
                endLoop =1;
                break;
        }
    }
    return 0;
}