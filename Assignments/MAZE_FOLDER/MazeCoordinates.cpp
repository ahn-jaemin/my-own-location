#include "maze_header.h"
#include <iostream>

class Coordinates {
    public:
        Coordinates();
        void setCors(int x, int y);
        void changeCors(int x, int y);
        int getXCor() const {return xCor;}
        int getYCor() const {return yCor;}

    private:
        int xCor;
        int yCor;
};

Coordinates::Coordinates(){
    xCor = 0;
    yCor = 0;
}

void Coordinates::setCors(int x, int y){
    xCor = x;
    yCor = y;
}

void Coordinates::changeCors(int x, int y){
    xCor += x;
    yCor += y;
}