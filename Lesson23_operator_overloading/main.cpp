//
//  main.cpp
//  Operator_Overloading
//Create a class with overloaded index and (= operator). The class contains dynamic memory.
//  Created by admin on 24.03.2021.
//

#include <iostream>



class MyArray
{
public:
    MyArray(int s)
    {
        m_size = s;
    }
    
    
    MyArray(const MyArray& rhs)
    {
        this->m_array_0 = rhs.m_array_0;
    }
    
    
    int& operator[](const int& idx)
    {
        return this->m_array_0[idx];
    }
    
    
    MyArray& operator = (const MyArray& rhs)
    {
//        m_array_0 = new int(m_size);
        
        for (int i = 0; i < m_size; i++)
        {
            m_array_0[i] = rhs.m_array_0[i];
        }
        
        return *this;
    }

    
    ~MyArray()
    {
        delete m_array_0;
    }
    
private:
    int m_size;
    int *m_array_0 = new int(m_size);
    
};


int main(int argc, const char * argv[])
{

    MyArray arr1(100), arr2(100);
    
    arr1[0] = 120;

    arr2 = arr1;
    std::cout << arr1[0] << std::endl;
    std::cout << arr2[0] << std::endl;
    
    arr2[0] = 22;
    std::cout << arr1[0] << std::endl;
    std::cout << arr2[0] << std::endl;

    
    return 0;
}
