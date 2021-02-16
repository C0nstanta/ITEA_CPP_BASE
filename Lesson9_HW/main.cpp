//TODO:
//The user enters information:
//- students name
//- students phone
//Add to the program the ability to search by student name and phone number.

//Example of work:
//
//Person: 1
//Name: Peter
//Phone Number: 1234
//Person: 2
//Name: Ivan
//Phone Number: 4567
//Person: 3
//Name: John
//Phone Number: 789809
//
//
//Choose an variant:
//1- Search by name
//2 - Search by phone
//
//Enter phone number: 4567
//
//Result:
//Name: Ivan
//Phone Number: 4567

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string name;
    string phone;
    
} ;
//Simple check is digit or not
bool is_alpha(string);
//Simple check is alpha or not
bool is_digit(string);

//Add data to DB
void stud_db(struct  Student *ptr_stud, int num_stud);

//Search in DB(panel)
int google_2(struct  Student *ptr_stud, int);

//Search in DB(core)
int finder(struct  Student *ptr_stud, string, string, int);

int main(int argc, const char * argv[]) {
    
    
    const int num_stud = 3;
    
    Student *ptr_stud = new Student[3];
    
    google_2(ptr_stud, num_stud);
    stud_db(ptr_stud, num_stud);
    
    for (int i = 0; i < num_stud; i++)
    {
        cout << ptr_stud[i].name << endl;
        cout << ptr_stud[i].phone << endl;
        cout << endl;
    }
    
    google_2(ptr_stud, num_stud);


    return 0;
}



void stud_db(struct  Student *ptr_stud, int num_stud)
{
    string st_name = "";
    string st_phone = "";
    
    for (int i = 0; i < num_stud; i++)
    {
        cin.clear();
        cout << "Enter student name:";
        getline(cin, st_name);
        
        if ( ::is_alpha(st_name) )
        {
            cout << "Name correct." << endl;
            ptr_stud[i].name = st_name;
        }
        else
        {
           cout << "Name NOT correct." << endl;
           ptr_stud[i].name = "Not correct data";
        }
        
        cin.clear();
        cout << "Enter student phone(only numbers without spaces):" << endl;
        getline(cin, st_phone);

        
        if ( ::is_digit(st_phone) != 0 )
        {
            cout << "Phone number correct." << endl;
            ptr_stud[i].phone = st_phone;
        }
        else
        {
            cout << "Phone NOT correct." << endl;
            ptr_stud[i].phone = "Not correct data";
        }
        cout << endl;
    }

};

bool is_digit(string phone)
{
    std::string::iterator start_str = phone.begin();
    
    while (start_str != phone.end() && isdigit(*start_str))
    {
        ++start_str;
    }
    return start_str == phone.end() && !phone.empty();
};

bool is_alpha(string name)
{
//    int i = 0, j = 0;
    std::string::iterator start_str = name.begin();
    
    while (start_str != name.end() &&  isalpha(*start_str))
    {
        ++start_str;
    }
    
    return !name.empty() && name.end() == start_str;
};


int google_2(struct Student *ptr_stud, int num_stud)
{
    string choice = " ";
    string search_phone_name ="";
    int find_result = 0;
    
    cout << "Whant to find:\n1. By name:\n2. By phone:\n" << endl;
    getline(cin, choice);

    if (choice == "1")
    {
        cout << "Input student name:" << endl;
        getline(cin, search_phone_name);
        find_result = ::finder(ptr_stud, search_phone_name, "1", num_stud);
    }
    else if (choice == "2")
    {
        cout << "Input student phone:" << endl;
        getline(cin, search_phone_name);
        find_result = ::finder(ptr_stud, search_phone_name, "2", num_stud);
    }
    else
    {
        cout << "Wrong data." << endl;
    }
    
    if (find_result == -1)
        cout << "No data in our DB." << endl;
    
    return 0;
};


int finder(struct  Student *ptr_stud, string phone_name, string choice, int num_stud)
{
    if (choice == "1")
        for (int i = 0; i < num_stud; i++)
        {
            if (ptr_stud[i].name == phone_name)
            {
                cout << "Result:\nName: " << ptr_stud[i].name << "\nPhone: " << ptr_stud[i].phone << endl;
                return 0;
            }
        }


    if (choice == "2")
        for (int i = 0; i < num_stud; i++)
        {
            if (ptr_stud[i].phone == phone_name)
            {
                cout << "Result:\nName: " << ptr_stud[i].name << "\nPhone: " << ptr_stud[i].phone << endl;
                return 0;
            }
        }

    return -1;
};
