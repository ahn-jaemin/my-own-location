#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int lengthRectangle;
    int widthRectangle;

    std::cout << "Please enter the length and width of the rectangle: ";
    std::cin >> lengthRectangle;
    std::cin >> widthRectangle;
    std::cout << std::endl;

    int perimeterRectangle;
    int areaRectangle;
    double diagonalRectangle;

    perimeterRectangle = (2 * lengthRectangle) + (2 * widthRectangle);
    areaRectangle = lengthRectangle * widthRectangle;
    diagonalRectangle = sqrt(pow(lengthRectangle, 2) + pow(widthRectangle, 2));

    std::cout << "perimeter: " << perimeterRectangle << std::endl;
    std::cout << "area: " << areaRectangle << std::endl;
    std::cout << "diagonal: " << diagonalRectangle << std::endl;

    return 0;
}

// check style guidelines