//
//  main.cpp
//  HW
//
//  Created by admin on 04.02.2021.
//Пользователь вводит строку состоящую из десятичных чисел расположенных по возрастанию. Также вводит отдельное число от 0 до 9. Вставить введенное число во входную строку, так чтобы порядок цифр не поменялся.

//Результат нужно сохранить в массиве!

#include <iostream>
#include <chrono>

using namespace std;


int main(int argc, const char * argv[]) {

    char digit, num[100] = {};
    int j = 0, my_arr[100] = {};
    
    
    cout << "Enter your numbers here(from lowest to highest):" << endl;
    cin >> num;
    
    cout << "Enter digit you want past into:" << endl;
    cin >> digit;
    
//Start measuring the time.
    auto begin = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < strlen(num); i++)
    {
//     The number  at the end of the array
        if ( (i == strlen(num)-1) && num[strlen(num)-1] == digit)
        {
            my_arr[j] = num[i] - '0';;
        }
        my_arr[j] = num[i] - '0';

//     Usual case
        if ((num[i] == digit) && (num[i+1] != digit))
        {
            ++j;
            my_arr[j] = (digit - '0');
        }
        j++;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    
    printf("Time measured: %.5f seconds.\n", elapsed.count() * 1e-9);
        
    int arraySize = sizeof(my_arr) / sizeof(int);
    
    for (int i = 0; i < arraySize; i++)
    {
        cout << my_arr[i] << " ";
        if(my_arr[i+1] == 0)
        {
            cout << endl;
            exit(0);
        }
    }
    cout << endl;

                
    return 0;
}
