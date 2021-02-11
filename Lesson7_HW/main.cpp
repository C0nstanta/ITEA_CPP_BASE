//
//  main.cpp
//  HW_BinarySearch
//
//  Created by admin on 11.02.2021.
//
//Create a function to find an element by a sorted array.
//
//Prototype:
//int GetElementPos (const int inpArr [], int element, int arrSize);
//
//Example of work1:
//Array: 3 5 6 16 20 23 45 667
//Number: 6
//Result: 3
//
//Example of work2:
//Array: 3 5 6 16 20 23 45 667
//Number: 23
//Position: 6
//
//Example of work3:
//Array: 3 5 6 16 20 23 45 667
//Number: 19
//Result: -1
//
//Use Binary Search for optimization

#include <iostream>


int GetElementPos(const int *const source, int arrayLength, int searchNum, int *ptr_count);


int main(int argc, const char * argv[]) {

    int sourceArray[] {3, 5, 6, 16, 20, 23, 30, 45, 47, 78, 90, 123, 129, 230,667};
    const int *const ptr_sourceArray = sourceArray;
    
    int searchNum = 0, pos = 0, arrLength = 0, count = 0;
    int *ptr_count = &count;
    
    std::cout << "Enter number you search:" << std::endl;
    std::cin >> searchNum;
    arrLength = sizeof(sourceArray) / sizeof(int);
    
    pos = GetElementPos(ptr_sourceArray, arrLength, searchNum, ptr_count);
    
    if (pos == -1)
    {
        std::cout << "There is no number in the array we search" << std::endl;
        std::cout << "Number of rounds: " << count << std::endl;
        return 0;
    }
    
    std::cout << "Our Pos: " << pos + 1 << std::endl;
    std::cout << "Number of rounds: " << count << std::endl;
    return 0;
}


int GetElementPos(const int *const source, int arrayLength, int searchNum, int *ptr_count)
{
    int start_idx = 0, end_idx = arrayLength - 1, sNum = searchNum,
        middle = 0;
    
    while (1)
    {
        middle = (start_idx + end_idx) / 2;
        
     
        if(sNum < source[start_idx] || sNum > source[end_idx])
        {
            (*ptr_count)++;
            return -1;
        }
        
        if (source[middle] > sNum)
        {
            end_idx = middle - 1;
        }
        else if (source[middle] < sNum)
        {
            start_idx = middle + 1;
        }
        if (source[middle] == sNum)
        {
            
            (*ptr_count)++;
            return middle;
        }
        
        (*ptr_count)++;
    }
    
    return -1;
}
