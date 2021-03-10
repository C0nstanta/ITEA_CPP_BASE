
#ifndef UICommunicator_hpp
#define UICommunicator_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


enum  Choise {
    LOAD_FILE = 1,
    LOAD_CONSOLE,
    REVERSE_DATA,
    WRITE_FILE,
    WRITE_CONSOLE,
    EXIT
};

class UICommunicator
{
public:

    
    vector<string>& GetDB()
    {
        return this->db_base_;
    };
    
    vector<string>& GetDBReverse()
    {
        return this->db_reverse_;
    }
    
    void PrintData()
    {
        for (int i = 0; i < static_cast<int>(this->db_base_.size()); i++)
        {
            cout << this->db_base_[i] << " ";
        }
    }
    
    void PrintReverseData()
    {
        for (const auto& db : this->db_reverse_)
            cout << db << " ";
    }

private:
    vector<string> db_base_;
    vector<string> db_reverse_;
};


class Reverse: public UICommunicator
{
public:

    void ReverseData()
    {
        vector<string> db_reverse_tmp = GetDB();
        reverse(db_reverse_tmp.begin(), db_reverse_tmp.end());
        vector<string>& db_reverse = GetDBReverse();
        db_reverse = db_reverse_tmp;
    }
    
};


class UIFile: public Reverse
{
public:
    
    void PushData(const string& path_in)
    {
        this->out_.open(path_in, ios::app);
        for (const auto& db : db_reverse_ )
        {
         
            out_ << db << " ";
        }
        out_.close();
    }
    
    void PullData(const string& path_out)
    {
        
        writer_.open(path_out);
        while (writer_)
        {
            string str;
            writer_ >> str;
            db_base_.push_back(str);
        }
        writer_.close();
    }
    
    void PullConsoleData()
    {
        string line;
        while (getline(cin, line))
        {
            if (line != "exit()")
            {
                
                db_base_.push_back(line);
            }
            else
            {
                break;
            }
        }
    }
    

private:
    ifstream writer_;
    ofstream out_;
    
    vector<string>& db_base_ = GetDB();
    vector<string>& db_reverse_ = GetDBReverse();
};

#endif /* UICommunicator_hpp */

