#include <iostream>

int main(){
int x = 0;
int y = 49;     //N is some constant value
while (y > 0) {
    y = y - 1;
    for (int i = 0; i < y; i++) { 
       if (i == y - 1) { std::cout << "The current number is " << y << std::endl;}
    }
}
}