#include <iostream>
#include <cmath>
#include <stdexcept>

double compDiscriminant(double a, double b, double c){
    double valDiscr;
    valDiscr = pow(b, 2) - (4 * a * c);
    return valDiscr;
}

double solveQuadraticPos(double a, double b, double c, double valDiscr){
    double valSolution;
    valSolution = (-b + sqrt(valDiscr)) / (2 * a);
    return valSolution;
}

double solveQuadraticNeg(double a, double b, double c, double valDiscr){
     double valSolution;
    valSolution = (-b - sqrt(valDiscr)) / (2 * a);
    return valSolution;
}

double readDouble(){
    double input;
    std::cin >> input;

    if(std::cin.fail()){ 
        throw std::runtime_error("\nAn error occurred: Malformed user input");
    }

    return input;
}

int main(){
    double a;
    double b;
    double c;
    double valDiscr;
    double sol1;
    double sol2;

    std::cout << "Please enter the values of a, b, and c: ";
    //std::cin >> a >> b >> c;
    try{
        a = readDouble();
        if(a == 0.0){throw std::runtime_error("An error occurred: a must not be zero");}
        b = readDouble();
        c = readDouble();

        valDiscr = compDiscriminant(a, b, c);

        if (valDiscr > 0){
            sol1 = solveQuadraticPos(a, b, c, valDiscr);
            sol2 = solveQuadraticNeg(a, b, c, valDiscr);
            std::cout << "There are 2 solutions." << std::endl;
            std::cout << "The solutions are: " << sol1 << " and " << sol2 << std::endl;
        }
        else if (valDiscr == 0){
            sol1 = solveQuadraticPos(a, b, c, valDiscr);
            std::cout << "There is 1 solution." << std::endl;
            std::cout << "The solution is: " << sol1 << std::endl;
        }
        else{
            std::cout << "There is no solution." << std::endl;
        }
    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }
    
    //How to check how many inputs? QUESTION
    //How to not start the calculation after error? QUESTION

    return 0;
}