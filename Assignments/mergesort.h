#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T> void merge(std::vector<T>& data, int firstToSort, int j, int lastToSort){                           
   int mergePos;                              // Position to insert merged number
   int leftPos;                               // Position of elements in left partition
   int rightPos;                              // Position of elements in right partition
   std::vector<T> mergedNumbers;

   mergePos = 0;
   leftPos = firstToSort;                               // Initialize left partition position
   rightPos = j + 1;                          // Initialize right partition position
   
   // Add smallest element from left or right partition to merged data
   while (leftPos <= j && rightPos <= lastToSort) {
  
      if (data.at(leftPos) < data.at(rightPos)) {
         mergedNumbers.push_back(data.at(leftPos));
         ++leftPos;
      }
      else {
         mergedNumbers.push_back(data.at(rightPos));
         ++rightPos;
      }

      ++mergePos;

   }
   
   // If left partition is not empty, add remaining elements to merged data
   while (leftPos <= j) {
      mergedNumbers.push_back(data.at(leftPos));
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged data
   while (rightPos <= lastToSort) {
      mergedNumbers.push_back(data.at(rightPos));
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to data
   for (mergePos = 0; mergePos < mergedNumbers.size(); ++mergePos) {
      data.at(firstToSort + mergePos) = mergedNumbers.at(mergePos);
   }
}

template <typename T> void mergeSort(std::vector<T>& data, unsigned int firstToSort, unsigned int lastToSort){
   int j;
   
   if (firstToSort < lastToSort) {
      j = (firstToSort + lastToSort) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      mergeSort(data, firstToSort, j);
      mergeSort(data, j + 1, lastToSort);
      
      // Merge left and right partition in sorted order
      merge(data, firstToSort, j, lastToSort);
   }
}

#endif