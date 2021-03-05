//Create a copy of a text file where words are in reverse order

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "UICommunicator.hpp"

using namespace  std;


int main(int argc, const char * argv[]) {



    
    string path_to_source = "";
    vector<string> reverse_file;
    

        cout << "First we need to parse the file.\nEnter the path to the file:"
             << endl;
        cin >> path_to_source;

        try
        {
            ifstream input(path_to_source);
            
            if (input)
            {
                while (input)
                {
                    string tem_str;
                    input >> tem_str;
                    reverse_file.push_back(tem_str);
                    cout << tem_str << endl;
                }
                cout << "Done!" << endl;
            }
            else
            {
                cout << "Error!" << endl;
            }
                
            input.close();
            
            
        }
        catch (exception& ex)
        {
            cout << "We got error: " << ex.what() << endl;
        }

    int choice = 0;
    
    cout << "Select a data output variant:\n1.Output to console.\n2.Output to file."
         << endl;
    
    cin >> choice;

    try
    {
        vector<string>::iterator itr;
        switch (choice) {
            case 1:
            {
                
                ConsoleComminicator console;
                for (itr = reverse_file.end(); itr != reverse_file.begin(); itr--)
                {
                    console.OutStream(*itr);
                }
                break;
            }
            case 2:
            {
                string out_path = "";

                cout << "Enter the path along with the file name to save the "
                "data\n(C:/PatToFile/file_name.txt):" << endl;
                cin >> path_to_source;

                FileCommunicator f_console;
                for (itr = reverse_file.end(); itr != reverse_file.begin(); itr--)
                {
                    f_console.OutStream(*itr, out_path);
                }
                cout << endl;
                break;

            }
            default:
                break;
        }
    }
    catch (exception& ex)
    {
        cout << "We got error: " << ex.what() << endl;
    }
        

    return 0;
}
