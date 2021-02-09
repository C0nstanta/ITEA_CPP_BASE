//Create a function that returns the N prime number.
//Write a function that finds the N-e prime number.
//int GetPrimeNumer(int n)
//{
////....
//}
//
//Example1:
//cout << GetPrimeNumer(1);
////Result: 2
//
//Expl2:
//cout << GetPrimeNumer(5);
////Res:11
//
//Expl3:
//cout << GetPrimeNumer(10);
////Res: 29

#include <iostream>

int GetPrimeNumber(int prime_num_arr[], int num);

int main(int argc, const char * argv[]) {

    int num = 0;
    
    std::cout << "How many primes do you want to find?" << std::endl;
    std::cin >> num;
    
    int prime_num_arr[num];
    
    
    GetPrimeNumber(prime_num_arr, num);
    
    std::cout << "Here are our " << num << " numbers:" << std::endl;
    for (int i = 0; i < num; i++)
    {
        std::cout << prime_num_arr[i] << " ";
    }
    
    std::cout << "\nAnd separately the last number of the array:\n" << prime_num_arr[num-1] << std::endl;
    

    return 0;
}


int GetPrimeNumber(int prime_num_arr[], int num)
{
    
    int i = 0;
    int searchPrimeNum = 0;
    
    
    while (i < num)
    {
        int count = 0, j = 1;
        searchPrimeNum ++;
        
        while(j <= searchPrimeNum)
        {
            if(searchPrimeNum % j == 0)
            {
                count++;
            }
            j++;
        }
        
        if (count == 2)
        {
            prime_num_arr[i] = searchPrimeNum;
            i++;
        }
    }
    
    return 0;
};
