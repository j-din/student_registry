/* Program that allows user to create and modify a doubly linked list of students */

#include "student.h"

int main()
{
    Student* head = nullptr;
    int choice;
    int ID;
    int newID;
    string name;
    string newName;

    printMenu();
    // Handles user input and validattion
    do
    {
        cin >> choice;
        while(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Invalid input, enter a number: ";
            cin >> choice;
        }
        switch(choice)
        {
            case 1:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while(cin.fail() || searchList(head, ID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID already exists, enter a new ID: ";
                    }
                    cin >> ID;
                }
                cout << "Enter the name of the student: ";
                cin.ignore();
                getline(cin, name);
                append(head, ID, name);
                break;
            case 2:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while(cin.fail() || searchList(head, ID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID already exists, enter a new ID: ";

                    }
                    cin >> ID;
                }
                cout << "Enter the name of the student: ";
                cin.ignore();
                getline(cin, name);
                push(head, ID, name);
                break;
            case 3:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while(cin.fail() || !searchList(head, ID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID not found, enter a new ID: ";

                    }
                    cin >> ID;
                }
                cout << "Enter the ID of the new student: ";
                cin >> newID;
                while(cin.fail() || searchList(head, newID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID already exists, enter a new ID: ";

                    }
                    cin >> newID;
                }
                cout << "Enter the name of the new student: ";
                cin.ignore();
                getline(cin, newName);
                insertAfter(head, ID, newID, newName);
                break;
            case 4:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while(cin.fail() || !searchList(head, ID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID not found, enter a new ID: ";

                    }
                    cin >> ID;
                }
                cout << "Enter the ID of the new student: ";
                cin >> newID;
                while(cin.fail() || searchList(head, newID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID already exists, enter a new ID: ";

                    }
                    cin >> newID;
                }
                cout << "Enter the name of the new student: ";
                cin.ignore();
                getline(cin, newName);
                insertBefore(head, ID, newID, newName);
                break;
            case 5:
                reverseList(head);
                break;
            case 6:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while(cin.fail() || !searchList(head, ID))
                {
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "Invalid input, enter a number: ";
                    }
                    else
                    {
                        cout << "ID not found, enter a new ID: ";

                    }
                    cin >> ID;
                }
                removeFromList(head, ID);
                break;
            case 7:
                cout << "Enter the ID of the student: ";
                cin >> ID;
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Invalid input, enter a number: ";
                    cin >> ID;
                }
                searchList(head, ID);
                break;
            case 8:
                printList(head);
                break;
            case 9:
                printMenu();
                break;
            case 10:
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 10);

    deleteList(head);
    
    return 0;
}