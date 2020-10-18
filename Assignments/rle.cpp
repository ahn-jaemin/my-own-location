#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <vector>

void encodeRunLength(std::string uncompressedData, std::vector<int> &vecRunLengths, std::vector<char> &vecCharacters){
    int runLength = 1;

        for(int j = 1; j < uncompressedData.size(); ++j){
            if(uncompressedData.at(j) == uncompressedData.at(j - 1)){
                ++runLength;
            }else{
                vecRunLengths.push_back(runLength);
                vecCharacters.push_back(uncompressedData.at(j - 1));
                runLength = 1;
            }
        }
}

int main(){
    std::string uncompressedData;
    std::vector<int> vecRunLengths;
    std::vector<char> vecCharacters;

    std::cout << "Enter the data to be compressed: ";
    std::cin >> uncompressedData;

    try{
        for(int i = 0; i < uncompressedData.size(); ++i){       //Check if only lowercase letters
            if(uncompressedData.at(i) < 97 || uncompressedData.at(i) > 122){
                throw std::runtime_error("error: invalid input");
            }
        }

        uncompressedData.push_back(' ');        //Append space so that encodeRunLength catches last run
        encodeRunLength(uncompressedData, vecRunLengths, vecCharacters);

        std::cout << "The compressed data is: ";
        for(int i = 0; i < vecRunLengths.size(); ++i){
            std::cout << vecRunLengths.at(i) << vecCharacters.at(i);
        }
        std::cout << std::endl;

    }catch(std::runtime_error& excpt) {
        std::cout << excpt.what() << std::endl;
    }

    return 0;
}