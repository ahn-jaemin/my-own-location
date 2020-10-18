#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <stdexcept>

class Coordinates {
    public:
        Coordinates();
        void setCors(int x, int y);
        void changeCors(int x, int y);
        int getXCor() const {return xCor;}
        int getYCor() const {return yCor;}

    private:
        int xCor;
        int yCor;
};

    Coordinates::Coordinates(){
        xCor = 0;
        yCor = 0;
    }

    void Coordinates::setCors(int x, int y){
        xCor = x;
        yCor = y;
    }

    void Coordinates::changeCors(int x, int y){
        xCor += x;
        yCor += y;
    }

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

class MazeState {
    public:
        MazeState(int width, int height, int Px, int Py, int Ex, int Ey, std::vector<char> layout, std::vector<char> playerMoves);
        bool processPlayerMoves(std::vector<char> playerMoves, int width, int height);
        void movePlayer(char movement, int width, int height);
        bool checkFinish(int playerXCor, int playerYCor, int exitXCor, int exitYCor);
    private:
        int mazeWidth;
        int mazeHeight;
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

int main(int argc, char* argv[]){
    std::ifstream inFS;
    std::pair<int, int> mazeDimensions;     //first: height; second: width

    try{

        //read file name, check for errors
        inFS.open(argv[1]);
        if (argc == 1){
            throw std::runtime_error("an error occurred: no input filename given");
        }
        if (!inFS.is_open()){
            std::cout << "an error occurred: could not open input file " << argv[1] << std::endl;
            return 1;
        }

        //read dimensions of maze
        inFS >> mazeDimensions.first;
        inFS >> mazeDimensions.second;
        if (inFS.fail()){
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