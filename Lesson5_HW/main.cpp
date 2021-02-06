//
//  main.cpp
//  HW
//
//  Created by admin on 06.02.2021.
//
//TODO:
//The user enters two strings.
//Insert string 2 into the first string beginning from position 5 .
//
//For example:
//asdjkfasfsadfsdfg
//ABCDEF
//Result: asdjABCDEFkfasfsadfsdfg




#include <iostream>
#define SIZE 255
#define change_pos 5

int main(int argc, const char * argv[]) {

    char first_string[SIZE];
    char second_string[SIZE];
    
    std::cout << "Enter your first string:" << std::endl;
    std::cin.getline(first_string, SIZE);
    
    std::cout << "Enter your second string:" << std::endl;
    std::cin.getline(second_string, SIZE) ;

    const auto FIRST_SIZE = strlen(first_string);
    const auto SECOND_SIZE = strlen(second_string);
    char third_string[FIRST_SIZE + SECOND_SIZE];


    std::cout << "FIRST_SIZE: "<< FIRST_SIZE << std::endl;
    std::cout << "SECOND_SIZE: "<< SECOND_SIZE << std::endl;

    if (FIRST_SIZE < 5 || SECOND_SIZE == 0)
    {
        std::cout << "Bad string length in 1 or 2 string." << std::endl;
        return 0;
    };
    
    int i = 0;
    while(i <= (FIRST_SIZE + SECOND_SIZE))
    {
        char tmp;
        tmp = (i >= change_pos) ? ( i < (change_pos + SECOND_SIZE) ? second_string[i-change_pos] : first_string[i-SECOND_SIZE]) : first_string[i];
        third_string[i] = tmp;
        
        if (i == (FIRST_SIZE + SECOND_SIZE)) third_string[i+1] = '\0';
        i++;
    };
    
    std::cout << "Rezult sring:\n";
    for (int i = 0; i < strlen(third_string); i++)
    {
        std::cout << third_string[i];
    };
    std::cout << "\nTotal lenght: " << strlen(third_string) << std::endl;
    return 0;
}
