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

    int maxNum = 0, minNum = 9, num = 0, separateNum = 0;
    
    cout << "Enter your number:" << endl;
    cin >> num;
    
    if (num > 0){
        while (num)
        {
            separateNum = num % 10;
            maxNum = maxNum > separateNum ? maxNum : separateNum;
            minNum = minNum < separateNum ? minNum : separateNum;
            cout << separateNum << " ";
            num /= 10;
        }
    }
    else
    {
        num = -num;
        while (num)
        {
            separateNum = num % 10;
            maxNum = maxNum > separateNum ? maxNum : separateNum;
            cout << separateNum << " ";
            num /= 10;
        }
        minNum = -separateNum;
    }
    cout << "\nOur min number is:" << minNum << endl;
    cout << "Our max number is:" << maxNum << endl;
    
    
    return 0;
}
