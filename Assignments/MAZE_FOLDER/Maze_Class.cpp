#include "maze_header.h"

class Maze {
    public:
        Maze();
        MazeLayout Layout;
        Coordinates PlayerCor;
        Coordinates ExitCor;
        MazeState State;

        class maybe{
            public:
                void output(){
                    std::cout << "It works!!" << std::endl;
                }
        };

};

Maze::Maze(){
    
}