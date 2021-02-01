//
//  main.cpp
//  Lesson2_HW
//
//  Created by admin on 01.02.2021.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {

    int num, separateNum, numLength;

    numLength = 5;

    cout << "Enter your number:" << endl;
    cin >> num;

    num = num > 0 ? num : -num;

    while (num){
        separateNum = num % 10;
        num /=10;
        cout << separateNum << " ";
    }
    cout << endl;

    cout << "Enter number again(2-nd variant):"<< endl;
    cin >> num;
    cout << "Enter this number length:"<< endl;
    cin >> numLength;

    num = num > 0 ? num : -num;
    
    for (int i = (numLength - 1); i >= 0; --i){
        separateNum = num / pow(10, i);
        num = num - separateNum * pow(10, i);
        cout << separateNum << " ";
    }
    cout << endl;
    return 0;
}
