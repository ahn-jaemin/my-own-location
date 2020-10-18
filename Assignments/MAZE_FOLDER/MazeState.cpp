#include "maze_header.h"
#include <iostream>
#include <vector>

class MazeState {
    public:
        MazeState(int width, int height, int Px, int Py, int Ex, int Ey, std::vector<char> layout, std::vector<char> playerMoves);
        bool processPlayerMoves(std::vector<char> playerMoves, int width, int height);
        void movePlayer(char movement, int width, int height);
        bool checkFinish(int playerXCor, int playerYCor, int exitXCor, int exitYCor);
    private:
        int mazeWidth;
        int mazeHeight;
        int playerMoveIndex;
        std::vector<char> playerMoves;
        std::vector<char> layout;
        Coordinates PlayerCor;
        Coordinates ExitCor;
        Coordinates NextCor;
        MazeLayout Layout;

};

MazeState::MazeState(int width, int height, int Px, int Py, int Ex, int Ey, std::vector<char> layout, std::vector<char> playerMoves){
    this->playerMoves = playerMoves;
    Layout.setLayout(layout);
    playerMoveIndex = 0;
    PlayerCor.setCors(Px, Py);
    ExitCor.setCors(Ex, Ey);
    mazeWidth = width;
    mazeHeight = height;
}

bool MazeState::processPlayerMoves(std::vector<char> playerMoves, int width, int height){
    int i = 0;

    for (int i = 0; i < playerMoves.size(); ++i){
        movePlayer(playerMoves.at(i), width, height);
    }

    //output maze to screen
        for (int i = 0; i < height; ++i){
            for (int j = 0; j < width; ++j){
                std::cout << Layout.getGridElement(j + (i * width));
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

    if (checkFinish(PlayerCor.getXCor(), PlayerCor.getYCor(), ExitCor.getXCor(), ExitCor.getYCor()) == true){
        return true;
    }else{
        return false;
    }
}

void MazeState::movePlayer(char movement, int width, int height){
    Layout.setGridElement('.', PlayerCor.getXCor(), PlayerCor.getYCor(), mazeWidth);

        switch(movement){
            case 'u':
                PlayerCor.changeCors(0, -1);
                break;
            case 'd':
                PlayerCor.changeCors(0, 1);
                break;
            case 'l':
                PlayerCor.changeCors(-1, 0);
                break;
            case 'r':
                PlayerCor.changeCors(1, 0);
                break;
            default:
                std::cout << "an error occurred: movement error" << std::endl;
                break;
        }

    if (Layout.getGridElement((PlayerCor.getYCor() * width) + PlayerCor.getXCor()) == 'l'){
            throw std::runtime_error("an error occurred: player outside maze or off the path");
        }

    Layout.setGridElement('P', PlayerCor.getXCor(), PlayerCor.getYCor(), mazeWidth);
}

bool MazeState::checkFinish(int playerXCor, int playerYCor, int exitXCor, int exitYCor){
    if (playerXCor == exitXCor && playerYCor == exitYCor){
        return true;
    }else{
        return false;
    }
}