//
//  UICommunicator.hpp
//  HW_on_classes
//
//  Created by admin on 04.03.2021.
//

#ifndef UICommunicator_hpp
#define UICommunicator_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


class UICommunicator
{
public:
    virtual void OutStream(const string& str)
    {
        
    }
    
};


class FileCommunicator : public UICommunicator
{
public:
    void OutStream(const string& str, const string& out_path)
    {
        ofstream output(out_path, std::ofstream::app);
        output << str << " ";
        output.close();
    }
};

class ConsoleComminicator : public UICommunicator
{
public:
    void OutStream(const string& str)
    {
        std::cout << str << " " ;
        
    }
    
};


#endif /* UICommunicator_hpp */
