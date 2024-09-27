#include <iostream>
#include <sstream>
using namespace std;

int main(){
    char operation;
    int value;

    cout << "Enter a character and an optional integer: ";
    cin >> operation;

    while(operation != 'q')
    {
        if(operation == '+')
        {
            if(cin >> value)
            {
                cout << "insert method" << endl;
            }
        }
        else if(operation == '-')
        {
            if(cin >> value)
            {
                cout << "Remove method" << endl;
            }
        }
        else if(operation == '?')
        {
            if(cin >> value)
            {
                cout << "Search method" << endl;
            }
        }
        else if(operation == 'p')
        {
            cout << "Test print " << endl;
        }
        else if(operation == '@')
        {
            cout << "At cursor  " << endl;
        }
        else if(operation == 'b')
        {
            cout << "GoTOBeginning " << endl;
        }
        else if(operation == 'e')
        {
            cout << "GO to end  " << endl;
        }
        else if(operation == '>')
        {
            cout << "Go to next " << endl;
        }
        else if(operation == '<')
        {
            cout << "Go to prev " << endl;
        }
        else if(operation == '1')
        {
            cout << "Test print " << endl;
        }
        else if(operation == '2')
        {
            cout << "Test print " << endl;
        }
        else if(operation == '3')
        {
            cout << "Test constructor " << endl;
        }
        else if(operation == '4')
        {
            cout << "Test copy const " << endl;
        }
        else if(operation == '5')
        {
            cout << "Test destructor " << endl;
        }
        else if(operation == '6')
        {
            cout << "Test assignment op " << endl;
        }
        else if(operation == '7')
        {
            cout << "Print clear the list " << endl;
        }
        else if(operation == 'm')
        {
            cout << "print menu " << endl;
        }
        else
        {
            cout << "HOW DID YOU GET HERE?" << endl;
            cout << "ANYWAYS HAVE A NICE DAY" << endl;
            return 0;
        }
        cin >> operation;
    }

    return 0;
}
