//Create a copy of a text file where words are in reverse order

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace  std;


int main(int argc, const char * argv[]) {


    vector<string> reverse_file;
    const string path = "input.txt";
    const string out_path = "output.txt";
    
    ifstream input(path);
    
    if (input)
    {
        while (input)
        {
            string tem_str;
            input >> tem_str;
            reverse_file.push_back(tem_str);
        }
        
    }
    else
    {
        cout << "Error!" << endl;
    }
        
    input.close();
    
    vector<string>::iterator itr;
    
    ofstream output(out_path);
    
    for (itr = reverse_file.end(); itr != reverse_file.begin(); itr--)
    {
        output << *itr << " ";
    }
    return 0;
}
