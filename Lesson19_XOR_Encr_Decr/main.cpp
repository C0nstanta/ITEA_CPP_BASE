//
//  main.cpp
//  XOR_Encrypt_Decrypt_file
//
//  Created by admin on 15.03.2021.
//

#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


void EncryptFunc(const string& in_file_path, string& out_file_path, short& password)
{
    ifstream in(in_file_path);
    if (in)
    {
        string line;
        vector<char> encrypt_file;
        
        while(getline(in, line))
        {
            for (char l : line)
            {
                cout << (char)(l ^ password);
                encrypt_file.push_back((char)(l ^ password));
            }
        }
        cout << endl;
        in.close();
        
        ofstream out(out_file_path);
        for (char e_f : encrypt_file)
        {
            out << e_f;
        }
    }
    else
    {
        cout << "Error reading file! Wrong path.";
    }
}

void DecryptFunc(const string& de_file_path, short& password)
{
    ifstream in(de_file_path);
    
    if (in)
    {
        string line;
        vector<char> decrypt_file;
        
        while(getline(in, line))
        {

            for (int l : line)
            {
                cout << (char)(l ^ password);
                decrypt_file.push_back((char)(l ^ password));
            }
        }
        cout << endl;
        
        in.close();
    }
    else
    {
        cout << "Error reading file! Wrong path.";
    }
}


int main(int argc, const char * argv[]) {


    string en_file_path;
    string de_file_path;

    en_file_path = "in.txt";
    de_file_path = "out.txt";

    
    cout << "Input file path for encryption: " << endl;
    cin >> en_file_path;
    
    cout << "Input encrypt password: " << endl;
    short pass = 0;
    cin >> pass;

    EncryptFunc(en_file_path, de_file_path, pass);

    cout << "Input decrypt password: " << endl;
    short de_pass = 0;
    cin >> de_pass;
    
    DecryptFunc(de_file_path, de_pass);

    return 0;
}
