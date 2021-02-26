//Create an Array structure based on a regular array

#include <iostream>
#include <vector>


using namespace std;

struct Array
{
public:

    void add_arr(int num_elem)
    {
        arr_size = num_elem;
        this->ptrHeadArr = new int[arr_size];
        this->ptrArr = ptrHeadArr;
    };
    
    void push_back(int elem)
    {
        if ((ptrHeadArr + arr_size) == ptrArr)
            resizeArr();
            
            *ptrArr = elem;
            ptrArr++;
            count_cell++;
    }
    
    void pop_back()
    {
        if (ptrHeadArr != ptrArr)
        {
            ptrArr--;
            count_cell--;
        }
    }

    
    void clear()
    {
        delete [] ptrHeadArr;
        this->ptrHeadArr = new int[arr_size];
        this->ptrArr = ptrHeadArr;
        count_cell = 0;
        
    }
    
    void print_arr()
    {
        if (ptrHeadArr == ptrArr)
            cout << "Your array is empty!" << endl;
        
        for (int i = 0; i < count_cell; i++)
        {
            cout << "Arr cell# " << i << " : " << ptrHeadArr[i] << endl;
        }
    }
    
    int size()
    {
        return 4 * count_cell;
    }
    

    
private:
    
    void resizeArr()
    {
            if (count_cell >= arr_size -1)
        {
            cout << "array is full. we will resize it." << endl;
            arr_size *=2;
            int *tptrHeadArr = new int[arr_size];
            int *tptrArr = tptrHeadArr;
        
            for (int i = 0; i < count_cell; i++)
            {
                tptrArr[i] = ptrHeadArr[i];
                
            }
            
            delete[] ptrHeadArr;
            

            ptrHeadArr = tptrHeadArr;
            ptrArr = &tptrArr[count_cell];

                        
        }
    }
    
    int arr_size = 0;
    int *ptrArr;
    int *ptrHeadArr;
    int count_cell = 0;
};

int main(int argc, const char * argv[]) {

    Array arr;
    arr.add_arr(2);
    arr.push_back(10);
    arr.push_back(15);
    arr.push_back(13);
    arr.pop_back();
    arr.push_back(78);
    
    arr.print_arr();

    
    arr.push_back(33);
    arr.push_back(22);
    arr.push_back(65);
    arr.push_back(76);

    arr.print_arr();

    arr.clear();
    arr.print_arr();

    return 0;
}
