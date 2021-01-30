//
//  main.cpp
//  Lesson2_HW
//
//  Created by admin on 30.01.2021.
//TODO:
//Split a five-digit number into separate digits

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {

    int maxNum = 0, minNum = 9, num, separateNum;
    
    cout << "Enter your number:" << endl;
    cin >> num;
    
    while (num)
    {
        separateNum = num % 10;
        maxNum = maxNum > separateNum ? maxNum : separateNum;
        minNum = minNum < separateNum ? minNum : separateNum;
        cout << separateNum << " ";
        num /= 10;
    }

    cout << "\nOur min number is:" << minNum << endl;
    cout << "Our max number is:" << maxNum << endl;
    
    
    return 0;
}
