//
//  main.cpp
//  Lesson3_HW
//
//  Created by admin on 02.02.2021.
//
//TODO: The user enters 5 numbers. Find the difference between the minimum and maximum numbers.
//Use arrays and loops for the solution.

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int arr[] ={};
    int num, minNumber, maxNumber, diff = 0;
    minNumber = 2147483647;
    maxNumber = -2147483647;
    
    for (int i = 0; i < 5; ++i){
        cout << "Enter the " << i + 1 << " number." << endl;
        cin >> num;
        arr[i] = num;
        maxNumber = maxNumber > num ? maxNumber : num;
        minNumber = minNumber < num ? minNumber : num;
    }
    
    diff = abs(maxNumber - minNumber);
    
    cout << "The max number is: " << maxNumber << endl;
    cout << "The min number is: " << minNumber << endl;
    cout << "The difference between them: " << diff << endl;

    return 0;
}
