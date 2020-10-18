#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int stealAsMuchAsPossible(std::vector<int>& weights, std::vector<int>& values, std::vector<bool>& inKnapsack, int capacity, int i, std::string indent, double totValue){

    int option1;
    int option2;

    //std::vector<bool> temporary(inKnapsack.size());

    if (capacity == 0 || weights.size() == i){
        return totValue;
    }else if (capacity > weights.at(i)){
        return stealAsMuchAsPossible(weights, values, inKnapsack, capacity, i + 1, indent + "   ", totValue);
    }else{

       // for (int i = 0; i < temporary.size(); ++i){
        //    temporary.at(i) = inKnapsack.at(i);
       // }

        option1 = stealAsMuchAsPossible(weights, values, inKnapsack, capacity, i + 1, indent + "   ", totValue);
        option2 = values.at(i) + stealAsMuchAsPossible(weights, values, inKnapsack, capacity - weights.at(i), i + 1, indent + "   ", totValue);

        if (option2 > option1){
           // temporary.at(i) = true;
           // for (int i = 0; i < temporary.size(); ++i){
               // inKnapsack.at(i) = temporary.at(i);
                std::cout << indent << "option2 larger: " << option2 << std::endl;
            //}
            return option2;
        }else{
            std::cout << indent << "option1 larger: " << option1 << std::endl;
            return option1;
        }
    }

   return 0;
}

/*int stealAsMuchAsPossible3(std::vector<int>& weights, std::vector<int>& values, std::vector<bool> inKnapsack, int capacity, int i, std::string indent){

    if (capacity == 0 || i == weights.size()){
        return 0;
    }
    else if (capacity < weights.at(i)){
        return stealAsMuchAsPossible(weights, values, inKnapsack, capacity, i + 1, indent + "   ", totValue);
    }
    else{

    }



    

   return 0;
}*/

int main(int argc, char* argv[]){
    int capacity;
    int i = 0;
    int j = 0;
    double totValue = 0;
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

    totValue = stealAsMuchAsPossible(weights, values, inKnapsack, capacity, i, "   ", totValue);

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

    /*for (int i = 0; i < inKnapsack.size(); ++i){
            std::cout << inKnapsack.at(i) << std::endl;
    }*/
    

    return 0; 
}