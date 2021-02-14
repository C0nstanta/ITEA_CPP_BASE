//TODO:
//Sort array by ascend.
//Create a function to sort the array by ascend.
//For instance:
//void BubbleSort (const int arr [], int n);
//
//Example of work:
//Array: 10 5 7 87 23 34 23
//Result: 5 7 10 23 23 34 87

//This program transform usual random array to binary tree array.
//This is VERY raw program and i fix it in next versions.

//NOTE!!

//In this algorithm, I take the worst case when the number of elements in the array is equal to the height of the binary tree!
//In the future, I will refine the algorithm and it will have uniform alignment


//First we create an array of random numbers. random_num_array() function.
//Next, we put our binary tree into an array.
//How?

//We start to fill  our binary tree array.
//left_child = node * 2 + 1
//right_child = node * 2 + 2
//array_high = log2(Total_nodes);


#include <iostream>
#include <ctime>
#include <cmath>


void random_num_array(int *arr, int num);
void binary_tree_arr(int *source_arr, int *bin_arr, int length_source_arr, int length_binary_arr);


int main(int argc, const char * argv[]) {

    int arrayLength = 0;
    
    
    std::cout << "Need to create array first. \nEnter the number of digits in"
                 " the array:" << std::endl;
    std::cin >> arrayLength;
    
    int bin_tree_len = 500;//pow(2, arrayLength - 1);
    

    int *ptr_rand_arr = new int[arrayLength];

    random_num_array(ptr_rand_arr, arrayLength);

    
    for (int i = 0; i < arrayLength; i++)
    {
        std::cout << *(ptr_rand_arr + i) << " ";
    };
    std::cout << std::endl;

    int *binary_tree_array = new int[bin_tree_len]; // This is the worst case! i'll rebuild algo in a next version!
    memset(binary_tree_array, -1, bin_tree_len); //fill the array by -1
    
    binary_tree_arr(ptr_rand_arr, binary_tree_array, arrayLength, bin_tree_len);
    
    
    return 0;
}

void binary_tree_arr(int *source_arr, int *bin_arr, int length_source_arr, int length_binary_arr)
{
    int start_pos = 0;
    int end_pos = length_source_arr - 1;
    int root_node = (end_pos - start_pos) / 2;
    int rotor = -1; // Thus we rotate our sign and take one number from right side, then left.
    
    
    *bin_arr = *(source_arr + root_node);
    
    for (int i = 0; i < length_source_arr; i++)
    {
        
        int idx_l = 0, idx_r = 0;
        rotor *= -1; // rotate sign!
        int curr_val = *(source_arr + root_node + rotor * (i/2 + 1));
        bool l_flag = true; //flag to enter  left tree side
        bool r_flag = true; //flag to enter  right tree side
        
        while(1)
        {
            if(l_flag)
            {
                if (*(bin_arr + idx_l) >= curr_val)
                {
                    idx_l = idx_l * 2 + 1;
                    if (*(bin_arr + idx_l) == -1)
                    {
                        *(bin_arr + idx_l) = curr_val;
                        break;
                    }
                    else
                    {
                        r_flag = false;
                        continue;
                    }
                }
                if (*(bin_arr + idx_l) < curr_val)
                {
                    idx_r = idx_l * 2 + 2;
                    if (*(bin_arr + idx_r) == -1)
                    {
                        *(bin_arr + idx_r) = curr_val;
                        break;
                    }
                    else
                    {
                        l_flag = false;
                        r_flag = true;
                        continue;
                    }
                }
                r_flag = false;
            }
            
            if(r_flag)
            {
                if (*(bin_arr + idx_r) < curr_val)
                {
                    idx_r = idx_r * 2 + 2;
                    if (*(bin_arr + idx_r) == -1)
                    {
                        *(bin_arr + idx_r) = curr_val;
                        break;
                    }
                    else
                    {
                        l_flag = false;
                        continue;
                    }
                }
                if (*(bin_arr + idx_r) >= curr_val)
                {
                    idx_l = idx_r * 2 + 1;
                    if (*(bin_arr + idx_l) == -1)
                    {
                        *(bin_arr + idx_l) = curr_val;
                        break;
                    }
                    else
                    {
                        r_flag = false;
                        l_flag = true;
                        continue;
                    }
                }

                r_flag = false;
            }
        };
        
        for (int i = 0; i < 60; i++)
        {
            std::cout << *(bin_arr + i) << " ";
        };
        std::cout << std::endl;
        
    };
};


void random_num_array(int *rand_arr,int num)
{
    srand(time(NULL));
    for (int i = 0; i < num; i++)
    {
        
        *(rand_arr + i) = rand() % 100;
    };
    
};
