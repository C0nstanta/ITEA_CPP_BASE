//Strings Sorting
//The user enters 5 lines. Sort lines in descending order.
//You can use functions strcmp, strcpy_s
//
//Example:
//
//bbb
//aaaaaa
//cc
//ffff
//dddd
//ee
//
//Result:
//ffff
//ee
//dddd
//cc
//bbb
//aaaaaa

#include <iostream>

using  namespace std;



int main(int argc, const char * argv[]) {

    const char size = 100;
    
    int num = 0;
    char **words = new char*[size];
    cout << "Input number of words - lines in your request:" << endl;
    cin >> num;
    
    for (int i =0; i < num; i++)
    {
        cout << "Enter " << i + 1 << " word." << endl;
        words[i] = new char[size];
        cin >> words[i];
        
    }
    
  
    for (int i = 0; i < num -1 ; i++)
    {
        for (int j = i +1; j < num; j++)
        {
            if (strcmp(words[i], words[j]) < 0)
            {
                swap(words[i], words[j]);
            }
        }
    }
 
    cout << " The result is:" << endl;
    
    for (int i = 1; i <+ num; i++)
    {
        int j = 0;
        while (words[i-1][j])
        {
            cout << words[i][j];
            j++;
        }
        cout << endl;
    }
        
    
    
    return 0;
}
