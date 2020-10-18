#include "maze_header.h"
#include <vector>
#include <cassert>

class MazeLayout {
    public:
        void appendGridElement(char gridElement);
        void setGridElement(char gridElement, int x, int y, int width);
        char getGridElement(int index);
        void setLayout(std::vector<char> layout);
        std::vector<char> getLayout();
    public:
        std::vector<char> layout;
        friend class MazeState;
};

void MazeLayout::appendGridElement(char gridElement){
    layout.push_back(gridElement);
}

void MazeLayout::setGridElement(char gridElement, int x, int y, int width){
    assert(layout.size() > ((y * width) + x));
    layout.at((y * width) + x) = gridElement;
}

char MazeLayout::getGridElement(int index){
    return layout.at(index);
}

void MazeLayout::setLayout(std::vector<char> layout){
    this-> layout = layout;
}

std::vector<char> MazeLayout::getLayout(){
    return layout;
}