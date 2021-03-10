//Create a copy of a text file where words are in reverse order

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include "UICommunicator.hpp"

using namespace  std;


int main(int argc, const char * argv[]) {


    UIFile file_reader;
    Reverse reverse;
    int command = 0;
    do
    {
        
        switch (command)
        {
            case Choise::LOAD_FILE:
            {
                string path_to_file;
                cout << "Input path/file data, you whant to load from." << endl;
                cin >> path_to_file;

                file_reader.PullData(path_to_file);
                
                cout << "Read file to DB" << endl;
                file_reader.PrintData();
                cout << endl;
                
                break;
            }
            case Choise::LOAD_CONSOLE:
            {
                cout << "Input data from console(for exit - print exit())" << endl;
                file_reader.PullConsoleData();
                break;
            }
            case Choise::REVERSE_DATA:
            {
                file_reader.ReverseData();
                
                break;
            }
            case Choise::WRITE_FILE:
            {
                string path_to_file;
                cout << "Input path/file data, you whant to load from." << endl;
                cin >> path_to_file;

                file_reader.PushData(path_to_file);
                cout << "Write to file DB" << endl;
                file_reader.PrintReverseData();
                cout << endl;

                break;
            }
            case Choise::WRITE_CONSOLE:
            {
                
                file_reader.PrintReverseData();
                cout << endl;
                break;
            }
            default:
                break;
        }
        
        cout << "1. Read From File\n2. Read From Console\n3. Reverse data\n"
             "4. Write to file(reverse data)\n5. Write to console(reverse data)\n"
             "6. Exit"
             << endl;
        
    } while(cin >> command);
    
    return 0;
}
