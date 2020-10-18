#include <iostream>
#include <cmath>

double compDiscriminant(double a, double b, double c){
    double valDiscr;

    valDiscr = pow(b, 2) - (4 * a * c);

    return valDiscr;
}

double solveQuadratic(double a, double b, double c, double valDiscr, bool plus){
    double valSolution;

    if (plus = true){
        valSolution = (-b + sqrt(valDiscr)) / (2 * a);
    }
    else {
        valSolution = (-b - sqrt(valDiscr)) / (2 * a);
    }

    return valSolution;
}

int main(){
    double a;
    double b;
    double c;
    double valDiscr;
    double sol1; //notation okay? No caps.
    double sol2;

    std::cout << "Please enter the values of a, b, and c: ";
    std::cin >> a >> b >> c;

    valDiscr = compDiscriminant(a, b, c);

    if (valDiscr > 0){
        sol1 = solveQuadratic(a, b, c, valDiscr, true);
        sol2 = solveQuadratic(a, b, c, valDiscr, false);

        std::cout << "There are 2 solutions." << std::endl;
        std::cout << "The solutions are: " << sol1 << " and " << sol2 << std::endl;
    }
    else if (valDiscr == 0){
        sol1 = solveQuadratic(a, b, c, valDiscr, true);

        std::cout << "There is 1 solution." << std::endl;
        std::cout << "The solution is: " << sol1 << std::endl;
    }
    else{
        std::cout << "There is no solution." << std::endl;
    }

return 0;
}