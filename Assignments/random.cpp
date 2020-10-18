#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   cout << (rand() % 100) << endl;
   cout << (rand() % 100) << endl;
   cout << (rand() % 100) << endl;

   cout << "(RAND_MAX: " << RAND_MAX << ")" << endl;

   return 0;
}