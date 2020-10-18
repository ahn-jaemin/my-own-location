#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <stdexcept>
#include "maze_header.h"

int main(int argc, char* argv[]){
    std::ifstream inFS;
    std::pair<int, int> mazeDimensions;     //first: height; second: width

    try{

        //read file name, check for errors
        inFS.open(argv[1]);
        if (argc == 1){
            throw std::runtime_error("an error occurred: no input filename given");
            //return 1;
        }
        if (!inFS.is_open()){
            std::cout << "an error occurred: could not open input file " << argv[1] << std::endl;
            return 1;
        }

        //read dimensions of maze
        inFS >> mazeDimensions.first;
        inFS >> mazeDimensions.second;

        if (std::cin.fail()){
            throw std::runtime_error("an error occurred: could not read height and width of the maze");
        }

        //read maze layout
        MazeLayout Layout;
        char temp;

        for (int i = 0; i < (mazeDimensions.first * mazeDimensions.second); ++i){
            inFS >> temp;
            if (inFS.fail()){throw std::runtime_error("an error occurred: could not read maze layout");}
            if (temp != '.' && temp != 'l'){throw std::runtime_error("an error occurred: could not read maze layout");}
            Layout.appendGridElement(temp);
        }

        //read player and exit coordinates
        int playerXCor;
        int playerYCor;
        int exitXCor;
        int exitYCor;
        inFS >> exitYCor;
        if (inFS.fail()){throw std::runtime_error("an error occurred: could not read coordinates");}
        inFS >> exitXCor;
        if (inFS.fail()){throw std::runtime_error("an error occurred: could not read coordinates");}
        inFS >> playerYCor;
        if (inFS.fail()){throw std::runtime_error("an error occurred: could not read coordinates");}
        inFS >> playerXCor;
        if (inFS.fail()){throw std::runtime_error("an error occurred: could not read coordinates");}
        
        if (exitYCor > mazeDimensions.first || exitXCor > mazeDimensions.second){
            throw std::runtime_error("an error occurred: exit outside maze or off the path");
        }
        if (playerYCor > mazeDimensions.first || playerXCor > mazeDimensions.second){
            throw std::runtime_error("an error occurred: player outside maze or off the path");
        }
        if (Layout.getGridElement((exitYCor * mazeDimensions.second) + exitXCor) != '.'){
            throw std::runtime_error("an error occurred: exit outside maze or off the path");
        }
        if (Layout.getGridElement((playerYCor * mazeDimensions.second) + playerXCor) != '.'){
            throw std::runtime_error("an error occurred: player outside maze or off the path");
        }

        //read player moves
        std::vector<char> playerMoves;
        char temp4;

        while (!inFS.eof()){
            inFS >> temp4;
            if (temp4 != 'u' && temp4 != 'd' && temp4 != 'l' && temp4 != 'r'){
                throw std::runtime_error("an error occurred: invalid move");
            }
            playerMoves.push_back(temp4);
        }
        playerMoves.pop_back();

        //Alter exit and player coordinates
        Layout.setGridElement('x', exitXCor, exitYCor, mazeDimensions.second);
        Layout.setGridElement('P', playerXCor, playerYCor, mazeDimensions.second);

        //Create MazeState
        MazeState MazeState(mazeDimensions.second, mazeDimensions.first, playerXCor, playerYCor, exitXCor, exitYCor, Layout.getLayout(), playerMoves);
        
        //output maze to screen
        for (int i = 0; i < mazeDimensions.first; ++i){
            for (int j = 0; j < mazeDimensions.second; ++j){
                std::cout << Layout.getGridElement(j + (i * mazeDimensions.second));
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        //Process player moves
        if (MazeState.processPlayerMoves(playerMoves, mazeDimensions.second, mazeDimensions.first) == true){
            std::cout << "The player reached the exit!" << std::endl;
        }else{
            std::cout << "The player did not reach the exit." << std::endl;
        }

    }catch(std::runtime_error& excpt){
        std::cout << excpt.what() << std::endl;
    }

}