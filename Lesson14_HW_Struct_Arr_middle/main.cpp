//Create an Array structure based on a regular array
//In this program, we create a dynamic array and can fill it in 2 directions.
//If the array is completely full, it automatically expands.
#include <iostream>

using namespace std;


template<typename T>
struct Array
{
private:
    
    int arr_size = 0;
    T *ptrArr = nullptr;
    T *ptrHeadArr = nullptr;
    T *ptrMiddleArr = nullptr;
    int count_cell = 0;

    int l_side_size = 0;
    int r_side_size = 0;
    
    int l_count = 0;
    int r_count = 0;
    
    void resizeArr()
    {
            if (l_side_size - l_count  < 0 || r_side_size + r_count >= arr_size)
        {
            cout << "array is full. we will resize it." << endl;
            
            arr_size *=2;
            T *tptrArr = new T[arr_size];
            
            l_side_size = (arr_size - (l_count + r_count)) / 2 + l_count - 1;
            r_side_size = (arr_size - (l_count + r_count)) / 2 + r_count + 1;
            
            if (r_side_size == l_side_size) r_side_size += 1;
            
            for (int i = 0; i < l_count; i++)
            {
                tptrArr[l_side_size - i] = *(ptrHeadArr--);
            }

            for (int i = 0; i < r_count; i++)
            {
                tptrArr[r_side_size + i] = *(++ptrHeadArr);
            }

                delete[] ptrArr;
                ptrArr = tptrArr;
                ptrHeadArr = &ptrArr[l_side_size];
            }

        }
    
public:
    void add_arr(int num_elem)
    {
        arr_size = num_elem;
        l_side_size = arr_size / 2 - 1;
        r_side_size = arr_size / 2;
        l_count = 0;
        r_count = 0;
        
        ptrArr = new T[arr_size];
        ptrHeadArr = &ptrArr[l_side_size];
    };
    
    
    void push_back(T elem)
    {
        
        if (this->l_side_size - this->l_count < 0)
        {
            cout << "Need to resize array for push_back" << endl;
            resizeArr();
        }
        
        int idx = l_side_size - l_count;
        ptrArr[idx] = elem;
        l_count++;
        cout << "push_back" << endl;
    }
    
    void pop_back()
    {
        
        if (l_count> 0)
        {
            l_count--;
            cout << "pop_back" << endl;
        }
        else
        {
            cout << "There is no any element on left array side" << endl;
            return;
        }
    }
    
    void push_front(T elem)
    {
        if (r_count + r_side_size >= arr_size)
        {
            cout << "Need to resize array for push_front" << endl;
            resizeArr();
            
        }
        
        int idx = r_count + r_side_size;
        ptrArr[idx] = elem;
        r_count++;
    }

    void pop_front()
    {
        if (r_count > 0)
        {
            r_count--;
            cout << "pop_front" << endl;
        }
        else
        {
            cout << "There is no any element on right array side" << endl;
            return;
        }
    }

    
    void clear()
    {
        delete [] ptrArr;
        this->ptrArr = new T[arr_size];

        l_side_size = arr_size / 2 - 1;
        r_side_size = arr_size - arr_size / 2;
        l_count = 0;
        r_count = 0;
        
    }
    
    void print_arr()
    {
        if (!l_count && !r_count )
        {
            cout << "Your array is empty!" << endl;
        }
        else
        {
            int j = 0;
            for (int i = l_side_size - l_count + 1; i < r_side_size + r_count;
                 i++)
            {
                
                cout << "Arr cell# " << j++ << " : " << ptrArr[i] << endl;
            }
        }
    }
    
    int size()
    {
        return 4 * count_cell;
    }

};
    

    

int main(int argc, const char * argv[]) {

    Array<int> arr;
    arr.add_arr(2);
    
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(10);
    arr.print_arr();
    cout << "====================" << endl;
    arr.pop_back();
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(10);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(10);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(15);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(13);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_back(78);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_front(111);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_front(115);
    arr.print_arr();
    cout << "====================" << endl;
    arr.push_front(134);
    arr.print_arr();
    cout << "====================" << endl;
    arr.pop_back();
    arr.print_arr();
    cout << "====================" << endl;
    arr.pop_front();
    arr.print_arr();
    cout << "====================" << endl;
    arr.clear();
    arr.print_arr();


    return 0;
}
