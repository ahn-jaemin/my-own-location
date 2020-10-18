#include <iostream>
#include <vector>
#include <cmath>

int main(){
    std::vector<double> userVctr(3);
    std::vector<double> ansVctr(3);
    std::vector<std::vector<double>> mtrxVctr = { {1.0, 2.0, 3.0},
                                                  {4.0, 5.0, 6.0},
                                                  {7.0, 8.0, 9.0} };

    std::cout << "Please enter the three vector coefficients" << std::endl;
    std::cin >> userVctr.at(0);
    std::cin >> userVctr.at(1);
    std::cin >> userVctr.at(2);
    std::cout << std::endl;

    for (int i = 0; i < 3; i++){
        ansVctr.at(i) = 0;
        for (int j = 0; j < 3; j++){
            ansVctr.at(i) += userVctr.at(j) * mtrxVctr.at(i).at(j);
        }
    }

    std::cout << "The result vector is [" << ansVctr.at(0) << ", " << ansVctr.at(1) << ", " << ansVctr.at(2) << "]" << std::endl;

    return 0;
}