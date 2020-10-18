#include <iostream>
#include <vector>

int getVecSize(){
    int vecSize;
    std::cout << "How many numbers?" << std::endl;
    std::cin >> vecSize;

    return vecSize;
}

void getUserInput(int& vecSize, std::vector<int>& userList){

    std::cout << "Please enter the numbers ";
    for (int j = 0; j < vecSize; j++){
        std::cin >> userList.at(j);
    }
    std::cout << std::endl;
}

int findSmallest(const std::vector<int>& userList){
    int smallest = userList.at(0);
    for (int i = 0; i < userList.size(); ++i){
        if(userList.at(i) < smallest) {
            smallest = userList.at(i);
        }
    }
    
    return smallest;
}

int findSmallestMissing(int smallest, const int vecSize, const std::vector<int>& userList){

    for (int i = 0; i < vecSize; ++i){
        if (userList.at(i) == smallest + 1){
            smallest++;
            i = 0;
        }
        
    }

    return smallest + 1;
}

int main(){
    int vecSize;
    int smallest;

    vecSize = getVecSize();

    std::vector<int> userList(vecSize);
    
    getUserInput(vecSize, userList);
    smallest = findSmallest(userList);
    smallest = findSmallestMissing(smallest, vecSize, userList);

    std::cout << "The smallest missing number is " << smallest << std::endl;

    return 0;
}