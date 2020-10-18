#include <iostream>
#include <vector>
#include <cassert>

void Merge(std::vector<int>& numbers, int i, int j, int k) {                           
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   std::vector<int> mergedNumbers;

   mergePos = 0;
   leftPos = i;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
  
      if (numbers.at(leftPos) < numbers.at(rightPos)) {
         mergedNumbers.push_back(numbers.at(leftPos));
         ++leftPos;
      }
      else {
         mergedNumbers.push_back(numbers.at(rightPos));
         ++rightPos;
         
      }
      ++mergePos;
   
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers.push_back(numbers.at(leftPos));
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers.push_back(numbers.at(rightPos));
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedNumbers.size(); ++mergePos) {
      numbers.at(i + mergePos) = mergedNumbers.at(mergePos);
   }
}

void MergeSort(std::vector<int>& numbers, int i, int k) {
   int j;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      MergeSort(numbers, i, j);
      MergeSort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      Merge(numbers, i, j, k);
   }
}

int main() {
   std::vector<int> numbers = { 10, 2, 78, 4, 45, 32, 7, 11 };
   //const int NUMBERS_SIZE = 8;
   int i;
   
   std::cout << "UNSORTED: ";
   for(i = 0; i < numbers.size(); ++i) {
      std::cout << numbers.at(i) << " ";
   }
   std::cout << std::endl;

   MergeSort(numbers, 0, (numbers.size()-1));
   
   std::cout << "SORTED: ";
   for(i = 0; i < numbers.size(); ++i) {
      std::cout << numbers.at(i) << " ";
   }
   std::cout << std::endl;
   
   return 0;
}