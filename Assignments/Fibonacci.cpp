#include <iostream>

int main(){
    int FnNew;
    int FnLast;
    int FnBeforeLast;
    int userFn;
    int count;

    FnNew = 0;
    count = 2;
    FnLast = 1;
    FnBeforeLast = 0; 

    std::cout << "Which Fibonacci number do you want to see? ";
    std::cin >> userFn;

    if (userFn == 1){
        std::cout << "0" << std::endl;
    }
    else if(userFn == 2){
        std::cout << "1" << std::endl;
    }
    else{
        while (count < userFn){
            FnNew = (FnLast + FnBeforeLast);
            FnBeforeLast = FnLast;
            FnLast = FnNew;
            count++;
        }
        std::cout << FnNew << std::endl;
    }

    return 0;
}