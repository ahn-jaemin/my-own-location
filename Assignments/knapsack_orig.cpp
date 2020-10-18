#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int knapsack(std::vector<int>& weights, std::vector<int>& values, std::vector<bool> inKnapsack, int capacity, int i, int& totWeight, int totValue, std::string indent){
    int option1;
    int option2;

    if (capacity <= 0){
        //std::cout << "Base case 1 reached: knapsack full, ";
        return 0;
    }
    if (i >= weights.size()){
        //std::cout << "Base case 2 reached: went through all items, ";
        return 0;
    }else{
        //std::cout << "Not base, ";

        if(weights.at(i) > capacity){
            ++i;
            return 0;

        }else{ 
            option1 = knapsack(weights, values, inKnapsack, (capacity - weights.at(i)), i++, totWeight, totValue, indent + "   ");     //adding i
            option2 = knapsack(weights, values, inKnapsack, capacity, ++i, totWeight, totValue, indent + "   ");                       //not adding i

            if (option1 > option2){
                inKnapsack.at(i) = true;
                totWeight += weights.at(i);
                totValue += values.at(i);
                std::cout << "2.2 ";
            }
        }   
    
    }

    return totValue;
}


int main(int argc, char* argv[]){
    int capacity;
    int numGoods;
    int i = 0;
    int j = 0;
    int totValue = 0;
    int totWeight = 0;
    std::vector<int> weights, values;

    std::ifstream inFS;
    inFS.open(argv[1]);
    if (argc == 1){
        std::cout << "No input filename given" << std::endl;
        return 1;
    }
    if (!inFS.is_open()){
        std::cout << "Could not open file " << argv[1] << std::endl;
        return 1;
    }

    inFS >> capacity;

    while (!inFS.eof()){
        int temp1, temp2;
        inFS >> temp1 >> temp2;
        weights.push_back(temp1);
        values.push_back(temp2);
        j++;
    }

    std::vector<bool> inKnapsack(weights.size(), false);

    knapsack(weights, values, inKnapsack, capacity, i, totWeight, totValue, "   ");

    for (int i = 0; i < inKnapsack.size(); i++){
        if (inKnapsack.at(i) == true){
            totWeight += weights.at(i);
        }
    }

    std::cout << "With a capacity of " << capacity << " kg, the total value is " << totValue << " Eur, leading to a total weight of " << totWeight << " kg" << std::endl;
    std::cout << "The following items are included: ";
    for (int i = 0; i < inKnapsack.size(); i++){
        if (inKnapsack.at(i) == true){
            std::cout << "[" << weights.at(i) << "," << values.at(i) << "] ";
        }
    }
    std::cout << std::endl;

    return 0; 
}