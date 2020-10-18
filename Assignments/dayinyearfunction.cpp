#include <vector>
#include <iostream>

int dayInYear(int day, int month, int year){
    int dayInYear = 0;
    std::vector<int> vecMonths = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};

    if(year % 4 == 0){vecMonths.at(2)++;}   //determine leap year
    if(year % 100 == 0){vecMonths.at(2)--;}
    if(year % 400 == 0){vecMonths.at(2)++;}

    for(int i = 1; i <= month; ++i){
        dayInYear += vecMonths.at(i - 1);
    }

    dayInYear += day;

return dayInYear;
}